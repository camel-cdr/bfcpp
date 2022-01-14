# Let's write an optimizing Brainfuck interpreter using only the C Preprocessor

Note: This isn't fully fleshed out yet, and more of a brain dump I wrote after finishing the project.


## Overview

* [1. Introduction](#1-introduction)
	* [1.1. Example, "better" case statements](#11-example-better-case-statements)
	* [1.2. Common utility macros and data structures](#12-common-utility-macros-and-data-structures)
		* [1.2.1. Tuple](#121-Tuple)
		* [1.2.2. Sequences](#122-Sequences)
		* [1.2.3. Comparisons and branches](#123-comparisons-and-branches)
	* [1.3. 8-bit Arithmetic](#13-8-bit-arithmetic)
	* [1.4. Faking recursion](#14-faking-recursion)
		* [1.4.1. The Continuation Machine](#141-the-continuation-machine)
* [2. Implementing Brainfuck](#2-implementing-brainfuck)
	* [2.1. The Continuation](#21-the-continuation)
	* [2.2. Implementing everything but loops](#22-implementing-everything-but-loops)
	* [2.3. Loops](#23-loops)
	* [2.4. Preparing the input](#24-preparing-the-input)
	* [2.5. Formatting the output](#25-formatting-the-output)
	* [2.6. A first complete version](#26-a-first-complete-version)
* [3. Adding Optimization Passes](#3-adding-optimization-passes)
	* [3.1. Summing increments and decrements](#31-summing-increments-and-decrements)
	* [3.2. Merging instructions](#32-merging-instructions)
		* [3.2.1. Special implementation for `[-]`, `[>]` and `[<]`](#321-special-implementation-for----and-)
	* [3.3. The final code](#33-the-final-code)




## 1 Introduction

The goal of this article is to implement an optimizing brainfuck interpreter using only the C preprocessor.
The final code can be used as follows:

<table><tr><td><b>Hello World</b></td><td><b>Output (cpp main.c)</b></td></tr><tr><td>

```c
#include "bf.c"

BF(,I,I,I,I,I,I,I,I,B,R,I,I,I,I,B,R,I,I,R,I,I,
    I,R,I,I,I,R,I,L,L,L,L,D,E,R,I,R,I,R,D,R,R,
    I,B,L,E,L,D,E,R,R,A,R,D,D,D,A,I,I,I,I,I,I,
    I,A,A,I,I,I,A,R,R,A,L,D,A,L,A,I,I,I,A,D,D,
    D,D,D,D,A,D,D,D,D,D,D,D,D,A,R,R,I,A,R,I,I,A)
```

</td><td>

```
Hello\x20World!\n
```

</td></tr></table>

I won't explain macro expansion in detail here, but you should read through [Paul Mensonides amazing write-up](https://marc.info/?l=boost&m=118835769257658&w=2) on the macro expansion process.
If you aren't certain how something expands, you might also want to check out [ppstep](https://github.com/notfoundry/ppstep), which visualizes every step of macro expansion.

Paul Mensonides didn't mention the existence of variadic macros arguments. If the last argument of a macro is `...`, it can take a variable number of arguments and any use of `__VA_ARGS__` inside of the replacement text will be replaced with the expanded comma separated arguments.

I disagree with Paul Mensonides explanation only in one detail, that is that its unspecified behaviour whether the following

```c
#define A() B
#define B() A

A()()() *
```

expands to `B *`, as explained in the write-up, or to `A() *`.

The relevant standard passage is [Annex J.1](https://port70.net/~nsz/c/c11/n1570.html#J.1):

> When a fully expanded macro replacement list contains a function-like macro name as its last preprocessing token and the next preprocessing token from the source file is a (, and the fully expanded replacement of that macro ends with the name of the first macro and the next preprocessing token from the source file is again a (, whether that is considered a nested replacement

As well as the example from [6.10.3.4p4](https://port70.net/~nsz/c/c11/n1570.html#6.10.3.4p4):

> EXAMPLE There are cases where it is not clear whether a replacement is nested or not. For example, given the following macro definitions:
> ```c
> #define f(a) a*g
> #define g(a) f(a)
> ```
> the invocation `f(2)(9)` may expand to either `2*f(9)` or `2*9*g`.
> Strictly conforming programs are not permitted to depend on such unspecified behavior.

I interpret this to mean the following: It is unspecified whether the disabling context is closed, after the function-like macro name has been read, or, after the entire function-like macro with all its arguments has been read.

Fortunately for us, most preprocessors close the disabling context after the function-like macro has been read (`A()()() *` expands to `B *` on all confirming preprocessors that I know of).
We are able to detect which behaviour our implementation choose to use, which we'll [use later for an optional faster implementation](#32-merging-instructions).


If what I've written above is completely new to you, then you should definitely read [Paul Mensonides write-up](https://marc.info/?l=boost&m=118835769257658&w=2).



### 1.1 Example, "better" case statements

As a first warm-up example, let's take a look at how one would implement the following
automatically breaking case statement syntax.

```c
switch (x) {
	Case(expr1) {} // break;case (expr1): {}
	Case(expr2) {} // break;case (expr2): {}
}
```

With the knowledge from above, this should be straightforward:

```c
#define Case(...) break;case(__VA_ARGS__):
```

Let's expand this new syntax by adding a default case if the `Case` arguments are empty.

```c
switch (x) {
	Case(expr1) {} // break;case (expr1): {}
	Case(expr2) {} // break;case (expr2): {}
	Case() {}      // break;default: {}
}
```

If we assume we've already defined a `IS_EMPTY(...)` macro that expands to `1` if the argument is empty and otherwise expands to `0`.
Now, can already write the following:

```c
#define CAT(a,b) a##b
#define PCAT(a,b) CAT(a,b)
#define Case(...) PCAT(Case,IS_EMPTY(__VA_ARGS__))(__VA_ARGS__)
#define Case0(...) break;case(__VA_ARGS__):
#define Case1(...) break;default:

switch (x) {
	Case(expr1) {} // break;case (expr1): {}
	Case(expr2) {} // break;case (expr2): {}
	Case() {}      // break;default: {}
}
```

The `Case` macro now forwards to `Case1` if the arguments are empty, and otherwise to `Case0`.
Notice how we needed to write the `PCAT` instead of just `CAT` because we require the arguments to be expanded before they are concatenated and concatenation happens before argument replacement and expansion.

Ok, but how do we implement `IS_EMPTY(...)`?
Consider the following code:

```c
#define IS_EMPTY_EXPAND() ,1
IS_EMPTY_EXPAND args ()
IS_EMPTY_EXPAND ()
```

The expansion of the first `IS_EMPTY_EXPAND` would be blocked by `args` whiles the second one expands to `,1`.
We can use this to implement `IS_EMPTY(...)`, by putting the arguments between `IS_EMPTY_EXPAND` and `()` and then detect the extra `,`:

```c
#define FX(f,...) f(__VA_ARGS__)
#define TUPLE_AT_2(a,b,...) b
#define IS_EMPTY(...) FX(TUPLE_AT_2,IS_EMPTY_EXPAND __VA_ARGS__ (),0,)
#define IS_EMPTY_EXPAND() ,1
IS_EMPTY() // 1
IS_EMPTY(abc) // 0
```

Note that we again need to define a helper macro `FX`, because we require the arguments to be expanded before they are passed to the function-like macro.

The observant reader might have noticed this approach doesn't work for all cases:

```
IS_EMPTY((abc)asd) // 0
IS_EMPTY(abc,123) // 123
```

Rest assured, all of those edge cases can be handled, but I'll leave that as an exercise,
since `Case((a))` and `Case(3,4)` are nonsensical, and we won't need the general solution later either. (Check out https://gustedt.wordpress.com/2010/06/08/detect-empty-macro-arguments/ for a full `IS_EMPTY(...)` implementation)



### 1.2 Common utility macros and data structures

In the previous section, you could already see we needed to define certain helper macros, and I'll introduce some more:

* `#define BF_CAT(a,b) a##b` concatenates two preprocessor identifiers.
* `#define BF_PCAT(a,b) BF_CAT(a,b)` concatenates the result of expanding both arguments
* `#define BF_STR(a) #a` stringifies the argument
* `#define BF_PSTR(a) BF_STR(a)` stringifies the argument after it has been expanded
* `#define BF_FX(f,...) f(__VA_ARGS__)` expands f after the arguments have been expanded
* `#define BF_SCAN(...) __VA_ARGS__` rescans the arguments

#### 1.2.1 Tuple

Tuples take the form of `(a,b,c,...).

* `#define BF_TUPLE_AT_1(a,...) a` expands to the first element of a tuple
* `#define BF_TUPLE_AT_2(a,b,...) b` expands to the second element of a tuple
* `#define BF_SCAN(...) __VA_ARGS__` unwraps the tuple, can be e.g. used to append values
* `#define BF_NOSCAN(P,...) P##__VA_ARGS__` unwraps a tuple, where the first argument is empty. This can be faster than `SCAN(...)` because the arguments aren't rescanned.

#### 2.2.2 Sequences

Preprocessor sequences take the form of `(a)(b)(c)...`.

* `#define BF_SEQ_EAT(...)` removes the first element
* `#define BF_SEQ_SPLAT(...) __VA_ARGS__,` splits the first element and the rest of the sequence into
* `#define BF_SEQ_AT_1a(x) BF_TUPLE_AT_1(x)`
  `#define BF_SEQ_AT_1(P,x) BF_SEQ_AT_1a(BF_SEQ_SPLAT P##x)` returns the first element


They allow very fast appending to the front and back and removal from the front because none of these operations need to rescan the entire sequence.
Because of these properties, preprocessor sequences can be very neatly used as stacks, by pushing and popping the front, and as queues, but pushing to the back and popping from the front.

They additionally allow for very fast iteration:

```c
#define A(a) a B
#define B(a) a A
A(a)(b)(c)(d)(e) // a b c d e
```

But as already mentioned, whether this works is unspecified, but detectable, behaviour.


#### 2.2.3 Comparisons and branches

We currently aren't capable of checking whether an identifier is equal to a specific identifier.

This can be achived by detecting whether a macro expands to two arguments or doesn't at all expand:

```c
#define BF_CHECK(...) BF_TUPLE_AT_2(__VA_ARGS__,0,)
#define BF_EQUAL(x,y) BF_CHECK(BF_EQUAL_##x##_##y)
```

The macro can be used to e.g. implement a check for `0`:

```c
#define BF_IS_0(x) BF_EQUAL(0,x)
#define BF_EQUAL_0_0 ,1
```

Exploiting the technique from [better switch](#11-example-better-case-statements) you could also branch to different macros depending on the value of an argument with a default case of `0` for unknown arguments:

```
#define FOO_SWITCH_1 ,1
#define FOO_SWITCH_2 ,2
#define FOO(x,...) BF_PCAT(FOO_,CHECK(FOO_SWITCH_##x))(__VA_ARGS__

#define FOO_0(...) ... // default case
#define FOO_1(...) ... // 1 case
#define FOO_2(...) ... // 2 cast
```

Finally, just to be complete, this is again the implementation `IS_EMPTY`:

```c
#define BF_IS_EMPTY(...) BF_FX(BF_TUPLE_AT_2,BF_IS_EMPTY_EXPAND __VA_ARGS__ (),0,)
#define BF_IS_EMPTY_EXPAND() ,1
```

### 1.3 8-bit Arithmetic

There is no fancy way of doing integer arithmetic using the preprocessor, since we only have text replacement, so everything must be be hand coded:

<table><tr><td><b>Incrementing</b></td><td><b>Decrementing</b></td></tr><tr><td>

```c
#define BF_INC(x) BF_INC_##x
#define BF_PINC(x) BF_INC(x)

#define BF_INC_0 1
#define BF_INC_1 2
#define BF_INC_2 3
...
#define BF_INC_fe ff
#define BF_INC_ff 0
```

</td><td>

```c
#define BF_DEC(x) BF_DEC_##x
#define BF_PDEC(x) BF_DEC(x)

#define BF_DEC_0 ff
#define BF_DEC_1 0
#define BF_DEC_2 1
...
#define BF_DEC_fe fd
#define BF_DEC_ff fe
```

</td></tr></table>

For Brainfuck increment and decrement operations are the only ones required, but since we are going to optimize the Brainfuck code, we'll later also use addition.

Addition can be implemented using two lookup tables, one for adding 1 to f to all numbers and one for adding 10 to f0 to all numbers.
Because additions and subtractions (which are implemented using additions) of small values are more common, we'll shift the first table, so it stores the result of subtracting 7,6,5,4,3,2 and adding 2,3,4,5,6,7,8. We also removed the +/-`1` from the table, since we can use `BF_DEC()`/`BF_INC()` instead.

Finally, we need to combine both lookup tables:


```c
#define BF_ADD_TO_0(F) F(f9,fa,fb,fc,fd,fe,2,3,4,5,6,7,8)
#define BF_ADD_TO_1(F) F(fa,fb,fc,fd,fe,ff,3,4,5,6,7,8,9)
...

#define BF_SUB_AT_7(a,b,c,d,e,f,g,h,i,j,k,l,m) a
#define BF_SUB_AT_6(a,b,c,d,e,f,g,h,i,j,k,l,m) b
...
#define BF_ADD_AT_7(a,b,c,d,e,f,g,h,i,j,k,l,m) l
#define BF_ADD_AT_8(a,b,c,d,e,f,g,h,i,j,k,l,m) m

#define BF_ADD10_TO_0(F) F(10,20,30,40,50,60,70,80,90,a0,b0,c0,d0,e0,f0)
#define BF_ADD10_TO_1(F) F(11,21,31,41,51,61,71,81,91,a1,b1,c1,d1,e1,f1)
...


#define BF_ADD_AT_10(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) a
#define BF_ADD_AT_20(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) b
...

#define BF_ADD_1(x) BF_INC_##x
#define BF_ADD_2(x) BF_ADD_TO_##x(BF_ADD_AT_2)
...
#define BF_ADD_3e(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_40)
#define BF_ADD_3f(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_40)
#define BF_ADD_40(x) BF_ADD10_TO_##x(BF_ADD_AT_40)
...
#define BF_ADD_fe(x) BF_ADD_TO_##x(BF_SUB_AT_2)
#define BF_ADD_ff(x) BF_DEC_##x
```

The full code can be found in [math.c](math.c)

### 1.4 Faking recursion

Now that we have data structures, branches and arithmetic, the question remaining is how we can "do stuff". Our problem is macros aren't recursive. If they were, we could just recur until an equality check has a specific value and stop our calculation there.

One way to do that is by tricking the preprocessor into not painting a function-like macro blue. With `#define EMPTY` one can defer the expansion of a function-like macro, without it getting painted blue, by placing it between the macro name and its arguments. If we repeatedly rescan the expansion, we've got finite macro recursion, the depth of which can be increased exponentially by adding another line of code:

```c
#define SCAN(...) __VA_ARGS__
#define SCAN2(...) SCAN(SCAN(SCAN(SCAN(SCAN(SCAN(SCAN(SCAN(__VA_ARGS__))))))))
#define SCAN3(...) SCAN2(SCAN2(SCAN2(SCAN2(SCAN2(SCAN2(SCAN2(SCAN2(__VA_ARGS__))))))))
#define SCAN4(...) SCAN3(SCAN3(SCAN3(SCAN3(SCAN3(SCAN3(SCAN3(SCAN3(__VA_ARGS__))))))))
// ...

#define EMPTY
#define A(x) x B EMPTY (x)
#define B(x) x A EMPTY (x)

SCAN2(A(2))
SCAN3(A(3))
SCAN4(A(4))
```

`SCAN2(A(2))` expands to `2 2 2 2 2 2 2 2 2 2 A (2)`, `SCAN3(A(3))` expands to `3 3 3 ... A (3)` with 74 3's and `SCAN4(A(4))` expands to `4 4 4 ... A (4)` with 587 4's.

If we continue that pattern from above and evaluate `SCAN8(A())`, this already takes about 5 seconds to preprocess. This would be the minimal execution time of our program and would limit the number of recursions we could do.
So what we need is a way to stop the rescanning.


#### 1.4.1 The Continuation Machine

Enter the continuation machine. This lovely piece of code does exactly what we are looking for:


```c
#define LPAREN (
#define SEQ_EAT(...)
#define SCAN(...) __VA_ARGS__
#define CM(...) SCAN(SEQ_EAT LPAREN CM_UP_0(__VA_ARGS__))

#define CM_UP_0(P,registers,f,...) CM_PASS_UP_1(CM_PASS_DN_0(XXX__##f(,P##registers,P##__VA_ARGS__)))
#define CM_UP_1(P,registers,f,...) CM_PASS_UP_2(CM_PASS_DN_1(XXX__##f(,P##registers,P##__VA_ARGS__)))
#define CM_UP_2(P,registers,f,...) CM_PASS_UP_3(CM_PASS_DN_2(XXX__##f(,P##registers,P##__VA_ARGS__)))

#define CM_DN_0(P,registers,f,...)                           XXX__##f(,P##registers,P##__VA_ARGS__  )
#define CM_DN_1(P,registers,f,...) CM_PASS_DN_0(CM_PASS_DN_0(XXX__##f(,P##registers,P##__VA_ARGS__)))
#define CM_DN_2(P,registers,f,...) CM_PASS_DN_1(CM_PASS_DN_1(XXX__##f(,P##registers,P##__VA_ARGS__)))

#define CM_PASS_UP_1(x)  CM_UP_1 x
#define CM_PASS_UP_2(x)  CM_UP_2 x
#define CM_PASS_UP_3(x) CM_ERROR_NO_MORE_MACHINE_STATE x

#define CM_PASS_DN_0(x)  CM_DN_0 x
#define CM_PASS_DN_1(x)  CM_DN_1 x
#define CM_PASS_DN_2(x)  CM_DN_2 x

#define CM_ERROR_NO_MORE_MACHINE_STATE()


// Example Usage:

#define XXX__PUSH(P,registers,arg,...) (,(P##arg)P##registers,P##__VA_ARGS__)
#define XXX__POP(P,registers,...) (,SEQ_EAT P##registers,P##__VA_ARGS__)
#define XXX__QUIT(P,registers,...) )P##registers

CM(,,PUSH,1,PUSH,2,POP,PUSH,3,QUIT,) // expands to (3)(1)
```

Here `registers` can be any number of named arguments that we want to use in all of our macros, and the `__VA_ARGS__` part contains the instructions that we want to execute.
Importantly, we can arbitrarily append to this list of instructions that are to be executed, and we can also terminate the execution at any time, by expanding to a closing parenthesis.


To illustrate how this works, I've annotated the relevant parts of the expansion process:

```
1. CM(,,PUSH,1,PUSH,2,POP,PUSH,3,QUIT,)
   ^ expands
2. SCAN(SEQ_EAT LPAREN CM_UP_0(,,PUSH,1,PUSH,2,POP,PUSH,3,QUIT,))
   ^ expands
Isolated expansion of `__VA_ARGS__` in SCAN:
    3. SEQ_EAT LPAREN CM_UP_0(,,PUSH,1,PUSH,2,POP,PUSH,3,QUIT,)
       ^ not recognized as a function-like macro and thus not painted blue
    3. SEQ_EAT LPAREN CM_UP_0(,,PUSH,1,PUSH,2,POP,PUSH,3,QUIT,)
               ^ expands
    4. SEQ_EAT ( CM_UP_0(,,PUSH,1,PUSH,2,POP,PUSH,3,QUIT,)
                 ^ expands
    6. SEQ_EAT ( CM_PASS_UP_1( CM_PASS_DN_0( XXX__PUSH(,,1,PUSH,2,POP,PUSH,3,QUIT,) ) )
                 ^ expands
    Isolated expansion of CM_PASS_UP_1's the arguments:
        7. CM_PASS_DN_0( XXX__PUSH(,,1,PUSH,2,POP,PUSH,3,QUIT,) )
           ^ expands
        Isolated expansion of CM_PASS_DN_0's the arguments:
            8. XXX__PUSH(,,1,PUSH,2,POP,PUSH,3,QUIT,)
               ^ expands
            9. (,(1),PUSH,2,POP,PUSH,3,QUIT,)
        10. CM_DN_0(,(1),PUSH,2,POP,PUSH,3,QUIT,)
            ^ expands
        11. XXX__PUSH(,(1),2,POP,PUSH,3,QUIT,)
            ^ expands
        12. (,(2)(1),POP,PUSH,3,QUIT,)
    13. SEQ_EAT ( CM_UP_1 (,(2)(1),POP,PUSH,3,QUIT,)
                  ^ expands
    14. SEQ_EAT ( CM_PASS_UP_2( CM_PASS_DN_1( XXX__POP(,(2)(1),PUSH,3,QUIT,) )
                  ^ expands
    Isolated expansion of CM_PASS_UP_2's arguments:
        15. CM_UP_2 CM_PASS_DN_1( XXX__POP(,(2)(1),PUSH,3,QUIT,) )
                    ^ expands
        Isolated expansion of CM_PASS_DN_1's arguments:
            16. XXX__POP(,(1),PUSH,3,QUIT,)
                ^ expands
            17. (,(1),PUSH,3,QUIT,)
        18. CM_DN_1 (,(1),PUSH,3,QUIT,)
            ^ expands
        19. CM_PASS_DN_0( CM_PASS_DN_0( XXX__PUSH(,(1),3,QUIT,) ) )
        Isolated expansion of CM_PASS_DN_0's arguments:
            19. CM_PASS_DN_0( XXX__PUSH(,(1),3,QUIT,) )
                ^ expands
            Isolated expansion of CM_PASS_DN_0's arguments:
                20. XXX__PUSH(,(1),3,QUIT,)
                    ^ expands
                21. (,(3)(1),QUIT,)
            22. CM_DN_0 (,(3)(1),QUIT,)
                ^ expands
            Isolated expansion of CM_DN_0's arguments:
                22. CM_QUIT(,(3)(1),)
                    ^ expands
                23. )(3)(1)
            24. )(3)(1)
        23. CM_DN_0 )(3)(1)
    24. SEQ_EAT ( CM_UP_2 CM_DN_0 )(3)(1)
25. SEQ_EAT ( CM_UP_2 CM_DN_0 )(3)(1)
    ^ expands
26. (3)(1)
```

That was quite a mouth full.

I hope you now have a decent understanding of how the continuation machine works. Don't worry if you don't, you'll get a good understanding of how to use it in the next part.

If you know the definition of a continuation then you might already see why this is called a continuation machine.

> [...] the continuation is a data structure that represents the computational process at a given point in the process's execution; the created data structure can be accessed by the programming language, instead of being hidden in the runtime environment. ([wikipedia](https://en.wikipedia.org/wiki/Continuation))

This is exactly what we have in the continuation machine. The entire state of the execution is accessible through every instruction executed by the continuation machine, and we can literately take the entire current state and put it into a register.



## 2 Implementing Brainfuck

I'll assume that you already know how Brainfuck works, if not, check out https://esolangs.org/wiki/Brainfuck.

Because we can't detect the original character set we need an alternative one:

| Original | Instruction | Description                                                       |
| ---      | ---         | ---                                                               |
| >        | R           | Move the tape head to the right                                   |
| <        | L           | Move the tape head to the left                                    |
| +        | I           | Increment the tape head                                           |
| -        | D           | Decrement the tape head                                           |
| .        | A           | Output the tape head as ASCII\*                                   |
|          | O           | Output the tape head as a hexadecimal number                      |
| ,        | G           | Read an input character and set the tape head to it               |
| [        | B           | Jump past the matching ] if the cell at the pointer is 0          |
| ]        | E           | Jump back to the matching [ if the cell at the pointer is nonzero |


### 2.1 The Continuation

To implement Brainfuck we'll use the continuation `(P,i,tl,t,tr,is,f,...)`, where:


* `P` Is always empty and used by the continuation machine to reduce the number of rescans.
* `i` Stores the input we pass to the Brainfuck program.

These three registers are used to represent the tape:

* `tl` left tape: sequence of tape values terminated by (_) and used as a stack
* `t` tape head
* `tr` right tape: sequence of tape values terminated by (_) and used as a stack

So the state `1 2 3 [4] 5 6` would be represented as `tl: (3)(2)(1)(_)` `t: 4` `tr: (5)(6)(_)`. To shift the tape head to the left you only need to pop the first element from `tr`, move it to `t` and append the old `t` to `tl`. The resulting tape would look like this: `tl: (4)(3)(2)(1)(_)` `5` `tr: (6)(_)`

Additionally, we need another register to implement the loops, but we'll discuss the details of that later:

* `is` instruction stack

The full continuation can be found in [cm.c](cm.c) and is called `BF_CM`.
There is also a "debug" continuation machine in [cm-debug.c](cm-debug.c) called `BF_CM_DBG`, which outputs the entire continuation on every iteration of the continuation machine.


### 2.2 Implementing everything but loops

First of all, we'll define the terminating instruction:

```c
#define BF__Q(P,i,tl,t,tr,is,...) )
```

You might be wondering where the output that we had in [1.3.4](TODO) went and why there is no output register.
This is because passing around redundant data through every macro expansion is quite expensive and we can just output the output directly, by adding it behind the continuation:

```c
#define BF__A(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(P##t)
```

This will reverse the output, but we'll need to post-process the output regardless, to convert it to ASCII, so we might as well reverse the output then.
This time we don't just propagate the `__VA_ARGS__`, because we represent the instructions that are to be executed as a sequence instead of an argument list, since this is faster.
For this to work we need to extract the first element of the sequence with `BF_SEQ_SPLAT`, so the continuation machine can actually execute it.

Sometimes we'd like our output not to be converted to ASCII, this is done by the `O` instruction, which outputs in the form of `(_(...))` instead of `(...)`.
This will be later detected and not converted to ASCII.

```c
#define BF__O(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(_(P##t))
```

We'll also implement this helper instruction that displays the current continuation:

```c
#define BF__S(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(,#i,#tl,#t,#tr,#is,S,#__VA_ARGS__)XXX
```

This instruction isn't intended to be used with formatted output.
The `XXX` has been added, so we can easily run the output through `sed 's/XXX/\n/g' | tac` to get proper newlines and the debug output in the correct order.
`BF_CM_DBG` basically does the same as `BF__S` but on every step of the continuation machine.

Implementing the increment and decrement operators is very easy, we use `BF_INC()` and `BF_DEC()` on the tape head:

```c
#define BF__I(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_INC(P##t),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__D(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_DEC(P##t),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
```

Getting the input is similarly easy, we remove the first element from the input and set the tape to this first element:

```c
#define BF__G(P,i,tl,t,tr,is,...) (,BF_SEQ_EAT P##i,P##tl,BF_SEQ_AT_1(,P##i),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
```

Shifting the tape left and right however is a bit more tricky.

Since the left and right tape stacks are terminated by `(_)` we need to define a special eat macro, that doesn't remove the `(_)`, when it's the only element in the stack:

```c
#define BF_TAPE_EAT(x) BF_PCAT(BF_TAPE_EAT,BF_CHECK(BF_TAPE_CHECK_##x))
#define BF_TAPE_CHECK__ ,1
#define BF_TAPE_EAT0
#define BF_TAPE_EAT1 (_)
```

We also need a macro that gives us the first element of a tape stack and `0` if the tape is empty, i.e. only contains `(_)`:

```c
#define BF_TAPE_AT_1(P,x) BF_FX(BF_TAPE_AT_1_1a,BF_SEQ_SPLAT P##x)
#define BF_TAPE_AT_1_1a(x,seq) BF_PCAT(BF_TAPE_AT_1_,BF_CHECK(BF_TAPE_CHECK_##x))(x)
#define BF_TAPE_AT_1_0(x) x
#define BF_TAPE_AT_1_1(x) 0
```

Now we just need to use these helpers to move the tape:

```c
#define BF__L(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_AT_1(,P##tl),(P##t)P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__R(P,i,tl,t,tr,is,...) (,P##i,(P##t)P##tl,BF_TAPE_AT_1(,P##tr),BF_TAPE_EAT P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
```

Lovely, we've already implemented everything but loops and are ready to test executing our first programs:


<details>
<summary>Expand full code</summary>
<br>

```c
#include "cm.c"
#include "math.c"

#define BF_CAT(a,b) a##b
#define BF_PCAT(a,b) BF_CAT(a,b)
#define BF_STR(a) #a
#define BF_PSTR(a) BF_STR(a)
#define BF_FX(f,...) f(__VA_ARGS__)
#define BF_SCAN(...) __VA_ARGS__
#define BF_LPAREN (

#define BF_TUPLE_AT_1(a,...) a
#define BF_TUPLE_AT_2(a,b,...) b
#define BF_SCAN(...) __VA_ARGS__
#define BF_NOSCAN(P,...) P##__VA_ARGS__

#define BF_SEQ_EAT(...)
#define BF_SEQ_SPLAT(...) __VA_ARGS__,
#define BF_SEQ_AT_1a(x) BF_TUPLE_AT_1(x)
#define BF_SEQ_AT_1(P,x) BF_SEQ_AT_1a(BF_SEQ_SPLAT P##x)


#define BF_CHECK(...) BF_TUPLE_AT_2(__VA_ARGS__,0,)
#define BF_EQUAL(x,y) BF_CHECK(BF_EQUAL_##x##_##y)

#define BF_IS_0(x) BF_EQUAL(0,x)
#define BF_EQUAL_0_0 ,1

#define BF_IS_EMPTY(...) BF_FX(BF_TUPLE_AT_2,BF_IS_EMPTY_EXPAND __VA_ARGS__ (),0,)
#define BF_IS_EMPTY_EXPAND() ,1



#define BF__Q(P,i,tl,t,tr,is,...) )

#define BF__A(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(P##t)
#define BF__O(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(_(P##t))
#define BF__S(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(,#i,#tl,#t,#tr,#is,S,#__VA_ARGS__)XXX

#define BF__I(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_INC(P##t),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__D(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_DEC(P##t),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)

#define BF__G(P,i,tl,t,tr,is,...) (,BF_SEQ_EAT P##i,P##tl,BF_SEQ_AT_1(,P##i),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)

#define BF_TAPE_EAT(x) BF_PCAT(BF_TAPE_EAT,BF_CHECK(BF_TAPE_CHECK_##x))
#define BF_TAPE_CHECK__ ,1
#define BF_TAPE_EAT0
#define BF_TAPE_EAT1 (_)

#define BF_TAPE_AT_1(P,x) BF_FX(BF_TAPE_AT_1_1a,BF_SEQ_SPLAT P##x)
#define BF_TAPE_AT_1_1a(x,seq) BF_PCAT(BF_TAPE_AT_1_,BF_CHECK(BF_TAPE_CHECK_##x))(x)
#define BF_TAPE_AT_1_0(x) x
#define BF_TAPE_AT_1_1(x) 0

#define BF__L(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_AT_1(,P##tl),(P##t)P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__R(P,i,tl,t,tr,is,...) (,P##i,(P##t)P##tl,BF_TAPE_AT_1(,P##tr),BF_TAPE_EAT P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)


BF_CM(,(1)(2)(3),(_),0,(_),,BF_SEQ_SPLAT (G)(I)(R)(G)(I)(R)(D)(A)(L)(O)(A)(L)(A)(Q))

// expands to : (2)(3)(_(3))(ff)
```

</details>


### 2.3 Loops

I've held back one thing about the input sequence. It is actually a nested sequence, so loops are represented as `(B)((I1)(I2)...(E))`.
This helps us tremendously with executing loops.

Recall that `B` skips the loop if is `0` and otherwise executes the loop.

Skipping the loop is very easy, we just eat the loop body:

```c
// If the tape head is 0, skip the loop
#define BF_B1(P,is,...) P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__)
```

In the other case we need to append the loop body to the instruction stack and flatten the loop body with `BF_SCAN`:

```c
// If the tape head is not 0, push the lopp body to the instruction stack and execute the loop body.
#define BF_B0(P,is,...) (BF_SEQ_AT_1(,P##__VA_ARGS__))P##is,BF_SCAN(BF_SEQ_SPLAT BF_SCAN P##__VA_ARGS__)
```

Now we just need to branch to the two macros depending on the value of the tape head:

```c
#define BF__B(P,i,tl,t,tr,...) (,P##i,P##tl,P##t,P##tr,BF_PCAT(BF_B,BF_IS_0(P##t))(,P##__VA_ARGS__))
```

`E` is quite similar:

```c
#define BF__E(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,BF_PCAT(BF_E,BF_IS_0(P##t))(,P##is,P##__VA_ARGS__))
// If the tape head is 0, remove the loop from the instruction stack and continue execution.
#define BF_E1(P,is,...) BF_SEQ_EAT P##is,BF_SEQ_SPLAT P##__VA_ARGS__
// If the tape isn't 0, execute the loop body from the top of the instruction stack again.
#define BF_E0(P,is,...) P##is,BF_SCAN(BF_SEQ_SPLAT BF_FX(BF_TUPLE_AT_1,BF_SEQ_SPLAT P##is))P##__VA_ARGS__
```

And just like that, we already have a working Brainfuck interpreter.
The output might be in reverse and the code isn't in a human friendly format, but we can already execute arbitrary Brainfuck code:


<table><tr><td><b>Hello World</b></td><td><b>Output</b></td></tr><tr><td>

```c
BF_CM(,,BF_SEQ_SPLAT
(I)(I)(I)(I)(I)(I)(I)(I)(B)((R)(I)(I)(I)(I)(B)((R)(I)
(I)(R)(I)(I)(I)(R)(I)(I)(I)(R)(I)(L)(L)(L)(L)(D)(E))(R)
(I)(R)(I)(R)(D)(R)(R)(I)(B)((L)(E))(L)(D)(E))(R)(R)(A)
(R)(D)(D)(D)(A)(I)(I)(I)(I)(I)(I)(I)(A)(A)(I)(I)(I)(A)
(R)(R)(A)(L)(D)(A)(L)(A)(I)(I)(I)(A)(D)(D)(D)(D)(D)(D)
(A)(D)(D)(D)(D)(D)(D)(D)(D)(A)(R)(R)(I)(A)(R)(I)(I)(A)
)
```

</td><td>

```
(a)(21)(64)(6c)(72)(6f)(57)(20)(6f)(6c)(6c)(65)(48)
```

</td></tr></table>

Great, but this is still missing proper output formatting and a proper interface.


### 2.4 Preparing the input

Instead of writing `(G)(I)(B)((D)(G)(B)((D)(E))(D)(G)(I)(E))` it would be much nicer, if we could just write `G,I,B,D,G,B,D,E,D,G,I,E` instead.

To implement this, we'll write a preprocessing parse `BF_TO_CODE`, that transforms the comma-separated instructions into the nested sequence structure we can directly execute.

We can recycle the same continuation machine and use the registers for different things:

```c
#define BF_TO_CODE(...) BF_CM(,,,,,,TO_CODE,__VA_ARGS__,TO_CODE_Q,)

#define BF__TO_CODE(P,o,is,_1,_2,_3,f,...) BF_PCAT(BF_TO_CODE_,BF_CHECK(BF_TO_CODE_SWITCH_##f))(,P##f,P##o,P##is,,,,TO_CODE,P##__VA_ARGS__)

#define BF_TO_CODE_SWITCH_TO_CODE_Q ,Q
#define BF_TO_CODE_SWITCH_B ,B
#define BF_TO_CODE_SWITCH_E ,E
```

Here `o` is the output, `is` is the instruction stack.
The idea is now that we, append to `o` until we hit a `B` or a `E`.
If we hit a `B`, then we'll push `o` to the `is`.
If we hit a `E`, then we'll append `is` to `o`.

```c
// Default: append the instruction to the sequence
#define BF_TO_CODE_0(P,x,o,...) (,P##o(P##x),P##__VA_ARGS__)
// TO_CODE_Q: stop and output code
#define BF_TO_CODE_Q(P,x,o,...) )P##o
// B: push output to the instruction stack
#define BF_TO_CODE_B(P,x,o,is,...) (,,(P##o(P##x))P##is,P##__VA_ARGS__)
// E: pop from the instructio stack to the output and parenthesize the old output
#define BF_TO_CODE_E(P,x,o,is,...) (,BF_SEQ_AT_1(,P##is)(P##o(P##x)),BF_SEQ_EAT P##is,P##__VA_ARGS__)
```

To get a better picture of how this works I've executed `BF_TO_CODE` on `G,I,B,D,G,B,D,E,D,G,I,E` with `BF_CM_DBG` instead of `BF_CM` (and cleand up the output a bit):

```
(,,                                        ,                      ,,,TO_CODE,G,I,B,D,G,B,D,E,D,G,I,E,TO_CODE_Q,)
(,(G),                                     ,                      ,,,TO_CODE,I,B,D,G,B,D,E,D,G,I,E,TO_CODE_Q,)
(,(G)(I),                                  ,                      ,,,TO_CODE,B,D,G,B,D,E,D,G,I,E,TO_CODE_Q,)
(,,                                        ((G)(I)(B)),           ,,,TO_CODE,D,G,B,D,E,D,G,I,E,TO_CODE_Q,)
(,(D),                                     ((G)(I)(B)),           ,,,TO_CODE,G,B,D,E,D,G,I,E,TO_CODE_Q,)
(,(D)(G),                                  ((G)(I)(B)),           ,,,TO_CODE,B,D,E,D,G,I,E,TO_CODE_Q,)
(,,                                        ((D)(G)(B))((G)(I)(B)),,,,TO_CODE,D,E,D,G,I,E,TO_CODE_Q,)
(,(D),                                     ((D)(G)(B))((G)(I)(B)),,,,TO_CODE,E,D,G,I,E,TO_CODE_Q,)
(,(D)(G)(B)((D)(E)),                       ((G)(I)(B)),           ,,,TO_CODE,D,G,I,E,TO_CODE_Q,)
(,(D)(G)(B)((D)(E))(D),                    ((G)(I)(B)),           ,,,TO_CODE,G,I,E,TO_CODE_Q,)
(,(D)(G)(B)((D)(E))(D)(G),                 ((G)(I)(B)),           ,,,TO_CODE,I,E,TO_CODE_Q,)
(,(D)(G)(B)((D)(E))(D)(G)(I),              ((G)(I)(B)),           ,,,TO_CODE,E,TO_CODE_Q,)
(,(G)(I)(B)((D)(G)(B)((D)(E))(D)(G)(I)(E)),,                      ,,,TO_CODE,TO_CODE_Q,)
(G)(I)(B)((D)(G)(B)((D)(E))(D)(G)(I)(E))
```



### 2.5 Formatting the output

The preprocessor is quite tricky in situations where two characters/tokens are output without space between them.
There are two ways of getting such output:

1. if both tokens are identifiers, they can be concatenated with the `##` operator
2. if one of the tokens isn't an identifier that they can be (mostly) concatenated with `BF_SCAN(a)b`.

The problem is that the behaviour of 2. is quite different between preprocessors.
Here is the output of `SCAN(!)SCAN(!)SCAN(!)SCAN(#)SCAN(#)SCAN(#)SCAN($)...` for a bunch of different preprocessors:

* tcc: `!!!###$ $ $%%%&&&***+ + +- - -...///:::;;;<<<===>>>???@@@[[[]]]^^^{{{|||}}}~~~`
* gcc: `!!!# # #$ $ $%%%& & &***+ + +- - -. . ./ / /: : :;;;< < < = = => > >???@@@[[[]]]^^^{{{| | |}}}~~~`
* clang: `!!!# # #$ $ $%%%& & &***+ + +- - -.. ./ / /:::;;;< < < = = => > >???@@@[[[]]]^^^{{{| | |}}}~~~`
* mcpp: `!  !  !  #  #  #  $  $  $  %  %  %  &  &  &  *  *  *  +  +  +  -  -  -  .  .  .  /  /  /  :  :  :  ;  ;  ;  <  <  <  =  =  =  >  >  >  ?  ?  ?  @  @  @  [  [  [  ]  ]  ]  ^  ^  ^  {  {  {  |  |  |  }  }  }  ~  ~  ~`
* chibicc: `!!!###$$$%%%&&&***+++---...///:::;;;<<<===>>>???@@@[[[]]]^^^{{{|||}}}~~~`

Sadly I don't know of any better way to concatenate non-identifier tokens.

To implement this we'll need to know three things a) what hexadecimal number is mapped to which character, b) if this character is an identifier, and c) if this character can be used in C code.

We'll once again resort to our trusty friend the lookup table:

```c
#define BF_ASCII(x) BF_ASCII_##x

#define BF_ASCII_0  2,\0
#define BF_ASCII_1  2,\x1
#define BF_ASCII_2  2,\x2
...
#define BF_ASCII_9  2,\t
#define BF_ASCII_a  2,\n
...

#define BF_ASCII_2a 0,*
#define BF_ASCII_2b 0,+
#define BF_ASCII_2c 2,\x2c
#define BF_ASCII_2d 0,-
#define BF_ASCII_2e 0,.
#define BF_ASCII_2f 0,/
#define BF_ASCII_30 1,0
#define BF_ASCII_31 1,1
#define BF_ASCII_32 1,2
...
#define BF_ASCII__(...) 0,(__VA_ARGS__)
```

The full code can be found in [format.c](format.c).

* `0,...` marks non-identifier tokens
* `1,...` marks identifier tokens
* `2,...` marks non-representable tokens, we output them in the `\0xXX` format, which begins as a non-identifier, but ends as an identifier.
* `_(...)` used in the `O` instruction, expands to `0,(...)`.

Now we'll define the concatenation rules:

```c
#define BF_FMT_SCAN(a) a
#define BF_ASCII_APPEND00(P,a,b) BF_FMT_SCAN(P##a)P##b
#define BF_ASCII_APPEND01(P,a,b) BF_FMT_SCAN(P##a)P##b
#define BF_ASCII_APPEND10(P,a,b) BF_FMT_SCAN(P##a)P##b
#define BF_ASCII_APPEND11(P,a,b) a##b

#define BF_ASCII_APPEND02(P,a,b) BF_FMT_SCAN(P##a)P##b
#define BF_ASCII_APPEND12(P,a,b) BF_FMT_SCAN(P##a)P##b
#define BF_ASCII_APPEND22(P,a,b) BF_FMT_SCAN(P##a)P##b
#define BF_ASCII_APPEND21(P,a,b) a##b
#define BF_ASCII_APPEND20(P,a,b) BF_FMT_SCAN(P##a)P##b
```

This can be used in our postprocessing parse `BF_FORMAT`, which also reverses the output:

```c
#define BF_FORMAT(seq) BF_CM(,0,,seq(FMT_Q),,,FMT,)

#define BF_EQUAL_FMT_Q_FMT_Q ,1
#define BF__FMT(P,n,o,i,_1,_2,...) BF_FX(BF_FMT,,P##n,P##o,BF_SEQ_SPLAT P##i)

#define BF_FMT(P,n,o,i0,i) BF_PCAT(BF_FMT,BF_EQUAL(FMT_Q,P##i0)(,P##n,P##o,BF_ASCII(P##i0),P##i))
#define BF_FMT0(P,n,o,ni,i0,i) (,P##ni,BF_ASCII_APPEND##ni##n(,P##i0,P##o),P##i,,,FMT,)
#define BF_FMT1(P,n,o,...) )P##o
```

### 2.6 A first complete version

<details>
<summary>Expand full code</summary>
<br>

```c
#include "cm.c"
#include "math.c"
#include "format.c"

#define BF_CAT(a,b) a##b
#define BF_PCAT(a,b) BF_CAT(a,b)
#define BF_STR(a) #a
#define BF_PSTR(a) BF_STR(a)
#define BF_FX(f,...) f(__VA_ARGS__)
#define BF_SCAN(...) __VA_ARGS__
#define BF_LPAREN (

#define BF_TUPLE_AT_1(a,...) a
#define BF_TUPLE_AT_2(a,b,...) b
#define BF_SCAN(...) __VA_ARGS__
#define BF_NOSCAN(P,...) P##__VA_ARGS__

#define BF_SEQ_EAT(...)
#define BF_SEQ_SPLAT(...) __VA_ARGS__,
#define BF_SEQ_AT_1a(x) BF_TUPLE_AT_1(x)
#define BF_SEQ_AT_1(P,x) BF_SEQ_AT_1a(BF_SEQ_SPLAT P##x)


#define BF_CHECK(...) BF_TUPLE_AT_2(__VA_ARGS__,0,~)
#define BF_EQUAL(x,y) BF_CHECK(BF_EQUAL_##x##_##y)

#define BF_IS_0(x) BF_EQUAL(0,x)
#define BF_EQUAL_0_0 ,1

#define BF_IS_EMPTY(...) BF_FX(BF_TUPLE_AT_2,BF_IS_EMPTY_EXPAND __VA_ARGS__ (),0,~)
#define BF_IS_EMPTY_EXPAND() ,1



#define BF__Q(P,i,tl,t,tr,is,...) )

#define BF__A(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(P##t)
#define BF__O(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(_(P##t))
#define BF__S(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(,#i,#tl,#t,#tr,#is,S,#__VA_ARGS__)XXX

#define BF__I(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_INC(P##t),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__D(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_DEC(P##t),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)

#define BF__G(P,i,tl,t,tr,is,...) (,BF_SEQ_EAT P##i,P##tl,BF_SEQ_AT_1(,P##i),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)

#define BF_TAPE_EAT(x) BF_PCAT(BF_TAPE_EAT,BF_CHECK(BF_TAPE_CHECK_##x))
#define BF_TAPE_CHECK__ ,1
#define BF_TAPE_EAT0
#define BF_TAPE_EAT1 (_)

#define BF_TAPE_AT_1(P,x) BF_FX(BF_TAPE_AT_1_1a,BF_SEQ_SPLAT P##x)
#define BF_TAPE_AT_1_1a(x,seq) BF_PCAT(BF_TAPE_AT_1_,BF_CHECK(BF_TAPE_CHECK_##x))(x)
#define BF_TAPE_AT_1_0(x) x
#define BF_TAPE_AT_1_1(x) 0

#define BF__L(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_AT_1(,P##tl),(P##t)P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__R(P,i,tl,t,tr,is,...) (,P##i,(P##t)P##tl,BF_TAPE_AT_1(,P##tr),BF_TAPE_EAT P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)

#define BF__B(P,i,tl,t,tr,...) (,P##i,P##tl,P##t,P##tr,BF_PCAT(BF_B,BF_IS_0(P##t))(,P##__VA_ARGS__))
// If the tape head is 0, skip the loop
#define BF_B1(P,is,...) P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__)
// If the tape head is not 0, push the lopp body to the instruction stack and execute the loop body.
#define BF_B0(P,is,...) (BF_SEQ_AT_1(,P##__VA_ARGS__))P##is,BF_SCAN(BF_SEQ_SPLAT BF_SCAN P##__VA_ARGS__)

#define BF__E(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,BF_PCAT(BF_E,BF_IS_0(P##t))(,P##is,P##__VA_ARGS__))
// If the tape head is 0, remove the loop from the instruction stack and continue execution.
#define BF_E1(P,is,...) BF_SEQ_EAT P##is,BF_SEQ_SPLAT P##__VA_ARGS__
// If the tape isn't 0, execute the loop body from the top of the instruction stack again.
#define BF_E0(P,is,...) P##is,BF_SCAN(BF_SEQ_SPLAT BF_FX(BF_TUPLE_AT_1,BF_SEQ_SPLAT P##is))P##__VA_ARGS__


#define BF_TO_CODE(...) BF_CM(,,,,,,TO_CODE,__VA_ARGS__,TO_CODE_Q,~)

#define BF__TO_CODE(P,o,is,_1,_2,_3,f,...) BF_PCAT(BF_TO_CODE_,BF_CHECK(BF_TO_CODE_SWITCH_##f))(,P##f,P##o,P##is,,,,TO_CODE,P##__VA_ARGS__)

#define BF_TO_CODE_SWITCH_TO_CODE_Q ,Q
#define BF_TO_CODE_SWITCH_B ,B
#define BF_TO_CODE_SWITCH_E ,E

// Default: append the instruction to the sequence
#define BF_TO_CODE_0(P,x,o,...) (,P##o(P##x),P##__VA_ARGS__)
// TO_CODE_Q: stop and output code
#define BF_TO_CODE_Q(P,x,o,...) )P##o
// B: push output to the instruction stack
#define BF_TO_CODE_B(P,x,o,is,...) (,,(P##o(P##x))P##is,P##__VA_ARGS__)
// E: pop from the instructio stack to the output and parenthesize the old output
#define BF_TO_CODE_E(P,x,o,is,...) (,BF_SEQ_AT_1(,P##is)(P##o(P##x)),BF_SEQ_EAT P##is,P##__VA_ARGS__)



#define BF_FORMAT(seq) BF_CM(,0,,seq(FMT_Q),,,FMT,)

#define BF_EQUAL_FMT_Q_FMT_Q ,1
#define BF__FMT(P,n,o,i,_1,_2,...) BF_FX(BF_FMT,,P##n,P##o,BF_SEQ_SPLAT P##i)

#define BF_FMT(P,n,o,i0,i) BF_PCAT(BF_FMT,BF_EQUAL(FMT_Q,P##i0)(,P##n,P##o,BF_ASCII(P##i0),P##i))
#define BF_FMT0(P,n,o,ni,i0,i) (,P##ni,BF_ASCII_APPEND##ni##n(,P##i0,P##o),P##i,,,FMT,)
#define BF_FMT1(P,n,o,...) )P##o

#define BF(input,...) BF_FORMAT(BF_CM(,BF_TO_CODE input(),(_),0,(_),,BF_SCAN(BF_SEQ_SPLAT BF_TO_CODE(__VA_ARGS__,Q))))
```

</details>


<table><tr><td><b>Hello World</b></td><td><b>Output</b></td></tr><tr><td>

```c
BF(,I,I,I,I,I,I,I,I,B,R,I,I,I,I,B,R,I,I,R,I,I,I,R,I,I,I,R,
    I,L,L,L,L,D,E,R,I,R,I,R,D,R,R,I,B,L,E,L,D,E,R,R,A,R,D,
    D,D,A,I,I,I,I,I,I,I,A,A,I,I,I,A,R,R,A,L,D,A,L,A,I,I,I,
    A,D,D,D,D,D,D,A,D,D,D,D,D,D,D,D,A,R,R,I,A,R,I,I,A)
```

</td><td>

```
Hello\x20World!\n
```

</td></tr></table>

<table><tr><td><b>Hello World</b></td><td><b>Output</b></td></tr><tr><td>

```c
#define ISORT(...) BF((__VA_ARGS__,0),\
	R,I,B,L,B,B,R,R,I,L,L,D,E,R,B,L,L,I,L,B,D,R,R,I,B,L,E,\
	E,R,R,R,B,R,E,L,L,D,E,L,L,L,E,R,R,B,L,L,I,R,R,D,E,L,B,\
	R,I,L,D,E,R,B,R,R,E,L,G,E,L,L,L,B,L,I,L,E,R,B,R,O,R,E)

ISORT(3,1,7,9,5,2,6,4,8)
```

</td><td>

```
(1)(2)(3)(4)(5)(6)(7)(8)(9)
```

</td></tr></table>





## 3 Adding Optimization Passes

### 3.1 Summing increments and decrements

This optimization parse will take the code and join all of the increments and decrements to one `_i,n` instruction, where `n` is the number that should be added to the tape.
E.g. `...,L,I,I,D,I,I,R,...` is turned into `...,L,_i,3,R,...`.

The `_i` instruction can be easily implemented using our `BF_ADD` macros:

```c
#define BF___i(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__))(P##t),P##tr,P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__))
```

To sum the increments/decrements we go through each instruction and branch on whether it is an increment or a decrement or something else:

```c
#define BF_SUM(f,...) BF_SCAN(BF_TUPLE_SCAN_EAT2 BF_CM(,(,),0,,,,BF_SUM_SWITCH(f),f,__VA_ARGS__,SUM_Q,))
#define BF_TUPLE_SCAN_EAT2(a,b,...) __VA_ARGS__

#define BF_SUM_SWITCH_SUM_Q ,SUM_Q
#define BF_SUM_SWITCH_I ,SUM_I
#define BF_SUM_SWITCH_D ,SUM_D
#define BF_SUM_CHECK(...) BF_TUPLE_AT_2(__VA_ARGS__,SUM_DEFAULT,)
#define BF_SUM_SWITCH(f) BF_SUM_CHECK(BF_SUM_SWITCH_##f)

#define BF__SUM_Q(P,o,x,_2,_3,_4,f,...) )P##o
```

If it's an increment/decrement then we'll increment/decrement the `x` register.

```c
#define BF__SUM_I(P,o,x,_1,_2,_3,f1,f2,...) (,P##o,BF_INC(P##x),,,,BF_SUM_SWITCH(P##f2),P##f2,P##__VA_ARGS__)
#define BF__SUM_D(P,o,x,_1,_2,_3,f1,f2,...) (,P##o,BF_DEC(P##x),,,,BF_SUM_SWITCH(P##f2),P##f2,P##__VA_ARGS__)
```

If it's another instruction, then we'll insert an `_i,x` if the `x` register isn't `0` and afterwards set `x` to `0`.

```c
#define BF__SUM_DEFAULT(P,o,x,_1,_2,_3,f1,f2,...) (,(,BF_NOSCAN P##o,BF_SUM_EXPAND(P##x)P##f1),0,,,,BF_SUM_SWITCH(P##f2),P##f2,P##__VA_ARGS__)
#define BF_SUM_EXPAND0(x) _i,x,
#define BF_SUM_EXPAND1(x)
#define BF_SUM_EXPAND(x) BF_PCAT(BF_SUM_EXPAND,BF_IS_0(x))(x)
```


If now you benchmark this you might notice, that the interpreter hasn't gotten much faster due to this optimization.
This is because we are wasting most of our time in tight loops, like `[-]`, `[>]` and `[<]`, where the joined increments/decrements don't have a big impact.
The following optimization however eliminates these loops and works way better with joined increments/decrements.

### 3.2 Merging instructions

Some instruction combinations could be merged into a single instruction and others, loops like `[-]`, `[>]` and `[<]` could even be completely reduced to a single operation.

To join these instruction combinations we'll check for the existence of the following macros (in the following order), where `a1` to `a4` are the next instructions:

```
BF_MERGE_1234_##a1##a2##a3##a4
BF_MERGE_124_##a1##a2##a4
BF_MERGE_123_##a1##a2##a3
BF_MERGE_13_##a1##a3
BF_MERGE_12_##a1##a2
```

They should be defined to the format `new_instruction_name,1`.
For `BF_MEREG_13`/`BF_MERGE_124` they can also be defined as `new_instruction_name,2`/`new_instruction_name,3`, which appends the ignored argument after the new instruction, which is needed to merge e.g.`_i,n,L`.

This is done by `BF_MERGE_DO1234_0`, which checks for the `1234` case and if it doesn't match forwards to `BF_MERGE_DO124_0` and so on.

```c
#define BF_MERGE_DO1234_0(P,a1,a2,a3,a4,...) BF_MERGE_DO124(BF_CHECK(BF_MERGE_1234_##a1##a2##a3##a4))(,P##a1,P##a2,P##a3,P##a4)
#define BF_MERGE_DO124_1(...) 1234
#define BF_MERGE_DO124_CAT(a,b) a##b
#define BF_MERGE_DO124(x) BF_MERGE_DO124_CAT(BF_MERGE_DO124_,x)

#define BF_MERGE_DO124_0(P,a1,a2,a3,a4) BF_MERGE_DO123(BF_CHECK(BF_MERGE_124_##a1##a2##a4))(,P##a1,P##a2,P##a3)
#define BF_MERGE_DO123_1(...) 124
#define BF_MERGE_DO123_3(...) 124_3
#define BF_MERGE_DO123_CAT(a,b) a##b
#define BF_MERGE_DO123(x) BF_MERGE_DO123_CAT(BF_MERGE_DO123_,x)

#define BF_MERGE_DO123_0(P,a1,a2,a3) BF_MERGE_DO13(BF_CHECK(BF_MERGE_123_##a1##a2##a3))(,P##a1,P##a2,P##a3)
#define BF_MERGE_DO13_1(...) 123
#define BF_MERGE_DO13_CAT(a,b) a##b
#define BF_MERGE_DO13(x) BF_MERGE_DO13_CAT(BF_MERGE_DO13_,x)

#define BF_MERGE_DO13_0(P,a1,a2,a3) BF_MERGE_DO12(BF_CHECK(BF_MERGE_13_##a1##a3))(,P##a1,P##a2)
#define BF_MERGE_DO12_1(...) 13
#define BF_MERGE_DO12_2(...) 13_2
#define BF_MERGE_DO12_CAT(a,b) a##b
#define BF_MERGE_DO12(x) BF_MERGE_DO12_CAT(BF_MERGE_DO12_,x)

#define BF_MERGE_DO12_0(P,a1,a2) BF_MERGE_DO1(BF_CHECK(BF_MERGE_12_##a1##a2))
#define BF_MERGE_DO1_0 1
#define BF_MERGE_DO1_1 12
#define BF_MERGE_DO1_CAT(a,b) a##b
#define BF_MERGE_DO1(x) BF_MERGE_DO1_CAT(BF_MERGE_DO1_,x)
```

The `BF_MERGE_DO...` functions expand to one of the names of the following macros:

```
#define BF_MERGE_1234(P,o,a1,a2,a3,a4,...)   (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_1234_##a1##a2##a3##a4)),,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE_124_3(P,o,a1,a2,a3,a4,...)  (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_124_##a1##a2##a4))     ,,,,,MERGE0,P##a3,P##__VA_ARGS__)
#define BF_MERGE_124_3(P,o,a1,a2,a3,a4,...)  (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_124_##a1##a2##a4))     ,,,,,MERGE0,P##a3,P##__VA_ARGS__)
#define BF_MERGE_124(P,o,a1,a2,a3,a4,...)    (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_124_##a1##a2##a4))     ,,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE_123(P,o,a1,a2,a3,...)       (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_123_##a1##a2##a3))     ,,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE_13_2(P,o,a1,a2,a3,...)      (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_13_##a1##a3))          ,,,,,MERGE0,P##a2,P##__VA_ARGS__)
#define BF_MERGE_13(P,o,a1,a2,a3,...)        (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_13_##a1##a3))          ,,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE_12(P,o,a1,a2,...)           (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_12_##a1##a2))          ,,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE_1(P,o,a1,...)               (,(,BF_NOSCAN P##o,P##a1)                                              ,,,,,BF_PCAT(MERGE,BF_IS_EMPTY(P##a1)),P##__VA_ARGS__)
```

Which are then applied to the continuation by `BF__MERGE0`:

```c
#define BF_MERGE(...) BF_SCAN(BF_TUPLE_SCAN_EAT2 BF_CM(,(,),,,,,MERGE0,__VA_ARGS__,,,,,))

#define BF__MERGE1(P,o,...) )P##o

#define BF__MERGE0(P,o,_1,_2,_3,_4,...) BF_MERGE0(BF_MERGE_DO1234_0(,P##__VA_ARGS__))(,P##o,P##__VA_ARGS__)
#define BF_MERGE0_CAT(a,b) a##b
#define BF_MERGE0(x) BF_MERGE0_CAT(BF_MERGE,x)
```


The merged instructions can now be implemented in the following way:

```c
#define BF_MERGE_12_L_i _Li,1
#define BF___Li(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__)(BF_TAPE_AT_1(,P##tl))),(P##t)P##tr,P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__))

#define BF_MERGE_13__iL _iL,2
#define BF___iL(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_AT_1(,P##tl),(BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__))(P##t))P##tr,P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__))
```

I'll leave the implementaion of `R_i _iR L_i1 L_iff R_i1 R_iff __i1L _iffL _i1R _iffR LL RR LLL RRR LLLL RRRR` to the reader.

We'll also rejoin `_i,ff` and `_i,1` instructions to the, `I` and `D` instructions, since they are smaller and more efficient:

```c
#define BF_MERGE_12__i1 I,1
#define BF_MERGE_12__iff D,1
```

And what did we gain? The [squares](http://brainfuck.org/squares.b) program now takes ~12s instead of ~25s to execute!

#### 3.2.1 Special implementation for `[-]`, `[>]` and `[<]`

The patterns`[-]`, `[>]` and `[<]` occur repeatedly in Brainfuck code and warrant a separate implementation.

Let's start with the easiest of the bunch `[-]` or `B,_i,n,E`.
This decrements/increments the tape head until it has the value of `0`, so we might as well skip the entire looping process and set the tape head to `0` directly:

```c
#define BF_MERGE_124_B_iE _0,1
#define BF___0(P,i,tl,t,tr,is,...) (,P##i,P##tl,0,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
```

`[<]` and `[>]` are a lot more tricky. They move the tape to the left or the right until the tape head is `0`.

To implement this efficiently I'll introduce a completely new paradigm.

As already mentioned in [the introduction](#1-introduction) the following can be used to iterate over sequences, and, since our tape is represented as a sequence, also the tape:

```c
#define A(a) a B
#define B(a) a A
A(a)(b)(c)(d)(e) // a b c d e
```

This is way faster than using the continuation machine because it only operates on one element of the sequence at a time and thus way less data needs to be copied and we also don't have to deal with the general overhead of the continuation machine.

As mentioned before, it is unspecified but detectable behaviour if this is interpreted by the preprocessor to be a recursive expansion, and is thus blocked, or not.

We can detect the behaviour in the following way:

```c
#define BF_HAS_SEQ_ITER BF_PCAT(BF_,BF_HAS_SEQ_ITERa()()())
#define BF_HAS_SEQ_ITERa() BF_HAS_SEQ_ITERb
#define BF_HAS_SEQ_ITERb() BF_HAS_SEQ_ITERa

#define BF_BF_HAS_SEQ_ITERa() 0
#define BF_BF_HAS_SEQ_ITERb 1

#if BF_HAS_SEQ_ITER
#define BF_MERGE_123_BLE _L0,1
#define BF_MERGE_123_BRE _R0,1
...
#endif
```

Cool, but now there is only one thing stopping us from implementing `_L0`/`_R0`: We don't have a continuation, and thus can't move state between iterations.
We need to be able to do that though because we need to output the consumed parts of the sequence in reverse, so we can append them to the other side of the tape.


To borrow the terminology from [bfi](http://www.kotha.net/bfi//), we can transform the sequence `(3)(4)(6)(0)(3)` into a guide `,3),4),6,0)(3)` and then use this guide.

```c
#define BF_L0_SWITCH_0 ,1
#define BF_L0_SWITCH__ ,2

#define BF_L0_TO_GUIDE_0(a,f) ,a)f
#define BF_L0_TO_GUIDE_1(a,f) ,0),
#define BF_L0_TO_GUIDE_2(a,f) ,0),(_)

#define BF_L0_TO_GUIDE1(a) BF_PCAT(BF_L0_TO_GUIDE_,BF_CHECK(BF_L0_SWITCH_##a))(a,BF_L0_TO_GUIDE2)
#define BF_L0_TO_GUIDE2(a) BF_PCAT(BF_L0_TO_GUIDE_,BF_CHECK(BF_L0_SWITCH_##a))(a,BF_L0_TO_GUIDE1)

BF_L0_TO_GUIDE1(3)(4)(6)(0)(3) // expands to: ,3),4),6),0),(3)
```

Now we can use this guide to reverse the sequence.

```c
#define BF_L0_EXEC_0(a,b,f) f((b)a
#define BF_L0_EXEC_1(a,b,f) a,0

#define BF_L0_EXEC1(a,b) BF_PCAT(BF_L0_EXEC_,BF_CHECK(BF_L0_SWITCH_##b))(a,b,BF_L0_EXEC2)
#define BF_L0_EXEC2(a,b) BF_PCAT(BF_L0_EXEC_,BF_CHECK(BF_L0_SWITCH_##b))(a,b,BF_L0_EXEC1)

#define BF_L0_DO(t,tr) BF_SCAN(BF_L0_EXEC1 BF_LPAREN BF_L0_TO_GUIDE1(t)tr)

BF_L0_DO(3,(4)(6)(0)(3)) // expands to: (6)(4)(3),0,(3)
```

Finally, we just need to use this on the actual tape:

```c
#define BF_L0a(tl1,tl0,t,tr) BF_CAT(,tl0)tl1,t,tr
#define BF_R0a(tr1,tr0,t,tl) tl,t,BF_CAT(,tr0)tr1

#define BF___R0(P,i,tl,t,tr,is,...) (,P##i,BF_FX(BF_L0a,tl,BF_L0_DO(t,tr)),P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF___L0(P,i,tl,t,tr,is,...) (,P##i,BF_FX(BF_R0a,tr,BF_L0_DO(t,tl)),P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
```

This brought down the execution time of the Brainfuck [quine](http://brainfuck.org/392quine.b) from ~124s to ~32s, very nice!

### 3.3 The final code

<details>
<summary>Expand full code</summary>
<br>

```c
#include "cm.c"
#include "math.c"
#include "format.c"

#define BF_CAT(a,b) a##b
#define BF_PCAT(a,b) BF_CAT(a,b)
#define BF_STR(a) #a
#define BF_PSTR(a) BF_STR(a)
#define BF_FX(f,...) f(__VA_ARGS__)
#define BF_SCAN(...) __VA_ARGS__
#define BF_LPAREN (

#define BF_TUPLE_AT_1(a,...) a
#define BF_TUPLE_AT_2(a,b,...) b
#define BF_TUPLE_SCAN_EAT2(a,b,...) __VA_ARGS__
#define BF_SCAN(...) __VA_ARGS__
#define BF_NOSCAN(P,...) P##__VA_ARGS__

#define BF_SEQ_EAT(...)
#define BF_SEQ_SPLAT(...) __VA_ARGS__,
#define BF_SEQ_AT_1a(x) BF_TUPLE_AT_1(x)
#define BF_SEQ_AT_1(P,x) BF_SEQ_AT_1a(BF_SEQ_SPLAT P##x)


#define BF_CHECK(...) BF_TUPLE_AT_2(__VA_ARGS__,0,)
#define BF_EQUAL(x,y) BF_CHECK(BF_EQUAL_##x##_##y)

#define BF_IS_0(x) BF_EQUAL(0,x)
#define BF_EQUAL_0_0 ,1

#define BF_IS_EMPTY(...) BF_FX(BF_TUPLE_AT_2,BF_IS_EMPTY_EXPAND __VA_ARGS__ (),0,)
#define BF_IS_EMPTY_EXPAND() ,1



#define BF__Q(P,i,tl,t,tr,is,...) )

#define BF__A(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(P##t)
#define BF__O(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(_(P##t))
#define BF__S(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(,#i,#tl,#t,#tr,#is,S,#__VA_ARGS__)XXX

#define BF__I(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_INC(P##t),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__D(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_DEC(P##t),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)

#define BF__G(P,i,tl,t,tr,is,...) (,BF_SEQ_EAT P##i,P##tl,BF_SEQ_AT_1(,P##i),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)

#define BF_TAPE_EAT(x) BF_PCAT(BF_TAPE_EAT,BF_CHECK(BF_TAPE_CHECK_##x))
#define BF_TAPE_CHECK__ ,1
#define BF_TAPE_EAT0
#define BF_TAPE_EAT1 (_)

#define BF_TAPE_AT_1(P,x) BF_FX(BF_TAPE_AT_1_1a,BF_SEQ_SPLAT P##x)
#define BF_TAPE_AT_1_1a(x,seq) BF_PCAT(BF_TAPE_AT_1_,BF_CHECK(BF_TAPE_CHECK_##x))(x)
#define BF_TAPE_AT_1_0(x) x
#define BF_TAPE_AT_1_1(x) 0

#define BF__L(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_AT_1(,P##tl),(P##t)P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__R(P,i,tl,t,tr,is,...) (,P##i,(P##t)P##tl,BF_TAPE_AT_1(,P##tr),BF_TAPE_EAT P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)

#define BF__B(P,i,tl,t,tr,...) (,P##i,P##tl,P##t,P##tr,BF_PCAT(BF_B,BF_IS_0(P##t))(,P##__VA_ARGS__))
// If the tape head is 0, skip the loop
#define BF_B1(P,is,...) P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__)
// If the tape head is not 0, push the lopp body to the instruction stack and execute the loop body.
#define BF_B0(P,is,...) (BF_SEQ_AT_1(,P##__VA_ARGS__))P##is,BF_SCAN(BF_SEQ_SPLAT BF_SCAN P##__VA_ARGS__)

#define BF__E(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,BF_PCAT(BF_E,BF_IS_0(P##t))(,P##is,P##__VA_ARGS__))
// If the tape head is 0, remove the loop from the instruction stack and continue execution.
#define BF_E1(P,is,...) BF_SEQ_EAT P##is,BF_SEQ_SPLAT P##__VA_ARGS__
// If the tape isn't 0, execute the loop body from the top of the instruction stack again.
#define BF_E0(P,is,...) P##is,BF_SCAN(BF_SEQ_SPLAT BF_FX(BF_TUPLE_AT_1,BF_SEQ_SPLAT P##is))P##__VA_ARGS__



#define BF_TO_CODE(...) BF_CM(,,,,,,TO_CODE,__VA_ARGS__,TO_CODE_Q,)

#define BF__TO_CODE(P,o,is,_1,_2,_3,f,...) BF_PCAT(BF_TO_CODE_,BF_CHECK(BF_TO_CODE_SWITCH_##f))(,P##f,P##o,P##is,,,,TO_CODE,P##__VA_ARGS__)

#define BF_TO_CODE_SWITCH_TO_CODE_Q ,Q
#define BF_TO_CODE_SWITCH_B ,B
#define BF_TO_CODE_SWITCH_E ,E

// Default: append the instruction to the sequence
#define BF_TO_CODE_0(P,x,o,...) (,P##o(P##x),P##__VA_ARGS__)
// TO_CODE_Q: stop and output code
#define BF_TO_CODE_Q(P,x,o,...) )P##o
// B: push output to the instruction stack
#define BF_TO_CODE_B(P,x,o,is,...) (,,(P##o(P##x))P##is,P##__VA_ARGS__)
// E: pop from the instructio stack to the output and parenthesize the old output
#define BF_TO_CODE_E(P,x,o,is,...) (,BF_SEQ_AT_1(,P##is)(P##o(P##x)),BF_SEQ_EAT P##is,P##__VA_ARGS__)



#define BF_SUM(f,...) BF_SCAN(BF_TUPLE_SCAN_EAT2 BF_CM(,(,),0,,,,BF_SUM_SWITCH(f),f,__VA_ARGS__,SUM_Q,))

#define BF_SUM_SWITCH_SUM_Q ,SUM_Q
#define BF_SUM_SWITCH_I ,SUM_I
#define BF_SUM_SWITCH_D ,SUM_D
#define BF_SUM_CHECK(...) BF_TUPLE_AT_2(__VA_ARGS__,SUM_DEFAULT,)
#define BF_SUM_SWITCH(f) BF_SUM_CHECK(BF_SUM_SWITCH_##f)

#define BF_SUM_EXPAND0(x) _i,x,
#define BF_SUM_EXPAND1(x)
#define BF_SUM_EXPAND(x) BF_PCAT(BF_SUM_EXPAND,BF_IS_0(x))(x)

#define BF__SUM_DEFAULT(P,o,x,_1,_2,_3,f1,f2,...) (,(,BF_NOSCAN P##o,BF_SUM_EXPAND(P##x)P##f1),0,,,,BF_SUM_SWITCH(P##f2),P##f2,P##__VA_ARGS__)
#define BF__SUM_I(P,o,x,_1,_2,_3,f1,f2,...) (,P##o,BF_INC(P##x),,,,BF_SUM_SWITCH(P##f2),P##f2,P##__VA_ARGS__)
#define BF__SUM_D(P,o,x,_1,_2,_3,f1,f2,...) (,P##o,BF_DEC(P##x),,,,BF_SUM_SWITCH(P##f2),P##f2,P##__VA_ARGS__)
#define BF__SUM_Q(P,o,x,_2,_3,_4,f,...) )P##o

#define BF___i(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__))(P##t),P##tr,P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__))



#define BF_MERGE(...) BF_SCAN(BF_TUPLE_SCAN_EAT2 BF_CM(,(,),,,,,MERGE0,__VA_ARGS__,,,,,))

#define BF__MERGE1(P,o,...) )P##o

#define BF__MERGE0(P,o,_1,_2,_3,_4,...) BF_MERGE0(BF_MERGE_DO1234_0(,P##__VA_ARGS__))(,P##o,P##__VA_ARGS__)
#define BF_MERGE0_CAT(a,b) a##b
#define BF_MERGE0(x) BF_MERGE0_CAT(BF_MERGE,x)

#define BF_MERGE1234(P,o,a1,a2,a3,a4,...)   (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_1234_##a1##a2##a3##a4)),,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE124_3(P,o,a1,a2,a3,a4,...)  (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_124_##a1##a2##a4))     ,,,,,MERGE0,P##a3,P##__VA_ARGS__)
#define BF_MERGE124_3(P,o,a1,a2,a3,a4,...)  (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_124_##a1##a2##a4))     ,,,,,MERGE0,P##a3,P##__VA_ARGS__)
#define BF_MERGE124(P,o,a1,a2,a3,a4,...)    (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_124_##a1##a2##a4))     ,,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE123(P,o,a1,a2,a3,...)       (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_123_##a1##a2##a3))     ,,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE13_2(P,o,a1,a2,a3,...)      (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_13_##a1##a3))          ,,,,,MERGE0,P##a2,P##__VA_ARGS__)
#define BF_MERGE13(P,o,a1,a2,a3,...)        (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_13_##a1##a3))          ,,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE12(P,o,a1,a2,...)           (,(,BF_NOSCAN P##o,BF_FX(BF_TUPLE_AT_1,BF_MERGE_12_##a1##a2))          ,,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE1(P,o,a1,...)               (,(,BF_NOSCAN P##o,P##a1)                                              ,,,,,BF_PCAT(MERGE,BF_IS_EMPTY(P##a1)),P##__VA_ARGS__)

#define BF_MERGE_DO1234_0(P,a1,a2,a3,a4,...) BF_MERGE_DO124(BF_CHECK(BF_MERGE_1234_##a1##a2##a3##a4))(,P##a1,P##a2,P##a3,P##a4)
#define BF_MERGE_DO124_1(...) 1234
#define BF_MERGE_DO124_CAT(a,b) a##b
#define BF_MERGE_DO124(x) BF_MERGE_DO124_CAT(BF_MERGE_DO124_,x)

#define BF_MERGE_DO124_0(P,a1,a2,a3,a4) BF_MERGE_DO123(BF_CHECK(BF_MERGE_124_##a1##a2##a4))(,P##a1,P##a2,P##a3)
#define BF_MERGE_DO123_1(...) 124
#define BF_MERGE_DO123_3(...) 124_3
#define BF_MERGE_DO123_CAT(a,b) a##b
#define BF_MERGE_DO123(x) BF_MERGE_DO123_CAT(BF_MERGE_DO123_,x)

#define BF_MERGE_DO123_0(P,a1,a2,a3) BF_MERGE_DO13(BF_CHECK(BF_MERGE_123_##a1##a2##a3))(,P##a1,P##a2,P##a3)
#define BF_MERGE_DO13_1(...) 123
#define BF_MERGE_DO13_CAT(a,b) a##b
#define BF_MERGE_DO13(x) BF_MERGE_DO13_CAT(BF_MERGE_DO13_,x)

#define BF_MERGE_DO13_0(P,a1,a2,a3) BF_MERGE_DO12(BF_CHECK(BF_MERGE_13_##a1##a3))(,P##a1,P##a2)
#define BF_MERGE_DO12_1(...) 13
#define BF_MERGE_DO12_2(...) 13_2
#define BF_MERGE_DO12_CAT(a,b) a##b
#define BF_MERGE_DO12(x) BF_MERGE_DO12_CAT(BF_MERGE_DO12_,x)

#define BF_MERGE_DO12_0(P,a1,a2) BF_MERGE_DO1(BF_CHECK(BF_MERGE_12_##a1##a2))
#define BF_MERGE_DO1_0 1
#define BF_MERGE_DO1_1 12
#define BF_MERGE_DO1_CAT(a,b) a##b
#define BF_MERGE_DO1(x) BF_MERGE_DO1_CAT(BF_MERGE_DO1_,x)


#define BF_MERGE_12_L_i _Li,1
#define BF_MERGE_12_R_i _Ri,1
#define BF___Li(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__)(BF_TAPE_AT_1(,P##tl))),(P##t)P##tr,P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__))
#define BF___Ri(P,i,tl,t,tr,is,...) (,P##i,(P##t)P##tl,BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__)(BF_TAPE_AT_1(,P##tr))),BF_TAPE_EAT P##tr,P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__))

#define BF_MERGE_13__iL _iL,2
#define BF_MERGE_13__iR _iR,2
#define BF___iL(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_AT_1(,P##tl),(BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__))(P##t))P##tr,P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__))
#define BF___iR(P,i,tl,t,tr,is,...) (,P##i,(BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__))(P##t))P##tl,BF_TAPE_AT_1(,P##tr),BF_TAPE_EAT P##tr,P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__))

#define BF_MERGE_123_L_i1 LI,1
#define BF_MERGE_123_L_iff LD,1
#define BF_MERGE_123_R_i1 RI,1
#define BF_MERGE_123_R_iff RD,1
#define BF__LI(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_PINC(BF_TAPE_AT_1(,P##tl)),(P##t)P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__LD(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_PDEC(BF_TAPE_AT_1(,P##tl)),(P##t)P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__RI(P,i,tl,t,tr,is,...) (,P##i,(P##t)P##tl,BF_PINC(BF_TAPE_AT_1(,P##tr)),BF_TAPE_EAT P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__RD(P,i,tl,t,tr,is,...) (,P##i,(P##t)P##tl,BF_PDEC(BF_TAPE_AT_1(,P##tr)),BF_TAPE_EAT P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)

#define BF_MERGE_123__i1L IL,1
#define BF_MERGE_123__iffL DL,1
#define BF_MERGE_123__i1R IR,1
#define BF_MERGE_123__iffR DR,1
#define BF__IL(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_AT_1(,P##tl),(BF_INC(P##t))P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__DL(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_AT_1(,P##tl),(BF_DEC(P##t))P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__IR(P,i,tl,t,tr,is,...) (,P##i,(BF_INC(P##t))P##tl,BF_TAPE_AT_1(,P##tr),BF_TAPE_EAT P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__DR(P,i,tl,t,tr,is,...) (,P##i,(BF_DEC(P##t))P##tl,BF_TAPE_AT_1(,P##tr),BF_TAPE_EAT P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)

#define BF_MERGE_12__i1 I,1
#define BF_MERGE_12__iff D,1

#define BF_MERGE_124_B_iE _0,1
#define BF___0(P,i,tl,t,tr,is,...) (,P##i,P##tl,0,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)


#define BF_TAPE_L(P,tl,t,tr) BF_TAPE_EAT P##tl,BF_TAPE_AT_1(,P##tl),(P##t)P##tr
#define BF_TAPE_R(P,tl,t,tr) (P##t)P##tl,BF_TAPE_AT_1(,P##tr),BF_TAPE_EAT P##tr
#define BF_TAPE_FX2(f,...) f(__VA_ARGS__)
#define BF_TAPE_L2(P,tl,t,tr) BF_TAPE_FX2(BF_TAPE_L,,BF_TAPE_L(,P##tl,P##t,P##tr))
#define BF_TAPE_R2(P,tl,t,tr) BF_TAPE_FX2(BF_TAPE_R,,BF_TAPE_R(,P##tl,P##t,P##tr))
#define BF_TAPE_FX3(f,...) f(__VA_ARGS__)

#define BF_MERGE_12_LL L2,1
#define BF_MERGE_12_RR R2,1
#define BF_MERGE_123_LLL L3,1
#define BF_MERGE_123_RRR R3,1
#define BF_MERGE_1234_LLLL L4,1
#define BF_MERGE_1234_RRRR R4,1
#define BF__L2(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_FX2(BF_TAPE_L,,BF_TAPE_L(,P##tl,P##t,P##tr)),P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__R2(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_FX2(BF_TAPE_R,,BF_TAPE_R(,P##tl,P##t,P##tr)),P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__L3(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_FX3(BF_TAPE_L,,BF_TAPE_L2(,P##tl,P##t,P##tr)),P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__R3(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_FX3(BF_TAPE_R,,BF_TAPE_R2(,P##tl,P##t,P##tr)),P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__L4(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_FX3(BF_TAPE_L2,,BF_TAPE_L2(,P##tl,P##t,P##tr)),P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__R4(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_FX3(BF_TAPE_R2,,BF_TAPE_R2(,P##tl,P##t,P##tr)),P##is,BF_SEQ_SPLAT P##__VA_ARGS__)


#define BF_HAS_SEQ_ITER BF_PCAT(BF_,BF_HAS_SEQ_ITERa()()())
#define BF_HAS_SEQ_ITERa() BF_HAS_SEQ_ITERb
#define BF_HAS_SEQ_ITERb() BF_HAS_SEQ_ITERa

#define BF_BF_HAS_SEQ_ITERa() 0
#define BF_BF_HAS_SEQ_ITERb 1

#if BF_HAS_SEQ_ITER

#define BF_MERGE_123_BLE _L0,1
#define BF_MERGE_123_BRE _R0,1

#define BF_L0_SWITCH_0 ,1
#define BF_L0_SWITCH__ ,2

#define BF_L0_TO_GUIDE_0(a,f) ,a)f
#define BF_L0_TO_GUIDE_1(a,f) ,0),
#define BF_L0_TO_GUIDE_2(a,f) ,0),(_)

#define BF_L0_TO_GUIDE1(a) BF_PCAT(BF_L0_TO_GUIDE_,BF_CHECK(BF_L0_SWITCH_##a))(a,BF_L0_TO_GUIDE2)
#define BF_L0_TO_GUIDE2(a) BF_PCAT(BF_L0_TO_GUIDE_,BF_CHECK(BF_L0_SWITCH_##a))(a,BF_L0_TO_GUIDE1)

#define BF_L0_EXEC_0(a,b,f) f((b)a
#define BF_L0_EXEC_1(a,b,f) a,0

#define BF_L0_EXEC1(a,b) BF_PCAT(BF_L0_EXEC_,BF_CHECK(BF_L0_SWITCH_##b))(a,b,BF_L0_EXEC2)
#define BF_L0_EXEC2(a,b) BF_PCAT(BF_L0_EXEC_,BF_CHECK(BF_L0_SWITCH_##b))(a,b,BF_L0_EXEC1)

#define BF_L0_DO(t,tr) BF_SCAN(BF_L0_EXEC1 BF_LPAREN BF_L0_TO_GUIDE1(t)tr)

#define BF_L0a(tl1,tl0,t,tr) BF_CAT(,tl0)tl1,t,tr
#define BF_R0a(tr1,tr0,t,tl) tl,t,BF_CAT(,tr0)tr1

#define BF___R0(P,i,tl,t,tr,is,...) (,P##i,BF_FX(BF_L0a,tl,BF_L0_DO(t,tr)),P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF___L0(P,i,tl,t,tr,is,...) (,P##i,BF_FX(BF_R0a,tr,BF_L0_DO(t,tl)),P##is,BF_SEQ_SPLAT P##__VA_ARGS__)

#endif




#define BF_FORMAT(seq) BF_CM(,0,,seq(FMT_Q),,,FMT,)

#define BF_EQUAL_FMT_Q_FMT_Q ,1
#define BF__FMT(P,n,o,i,_1,_2,...) BF_FX(BF_FMT,,P##n,P##o,BF_SEQ_SPLAT P##i)

#define BF_FMT(P,n,o,i0,i) BF_PCAT(BF_FMT,BF_EQUAL(FMT_Q,P##i0)(,P##n,P##o,BF_ASCII(P##i0),P##i))
#define BF_FMT0(P,n,o,ni,i0,i) (,P##ni,BF_ASCII_APPEND##ni##n(,P##i0,P##o),P##i,,,FMT,)
#define BF_FMT1(P,n,o,...) )P##o

#define BF(input,...) BF_FORMAT(BF_CM(,BF_TO_CODE input(),(_),0,(_),,BF_SCAN(BF_SEQ_SPLAT BF_TO_CODE(BF_MERGE(BF_SUM(__VA_ARGS__,Q))))))
```

</details>
