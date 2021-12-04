# Optimizing Brainfuck interpreter in the C preprocessor


[![Tests](https://github.com/camel-cdr/bfcpp/workflows/Tests/badge.svg)](https://github.com/camel-cdr/bfcpp/actions?workflow=Tests)

A C99 confirming\* optimizing Brainfuck implementation written (and executed) only using the C preprocessor.

\*If you find something that does not confirm to the standard or is unspecified/undefined, please open an issue.

## Example

<table><tr><td><b>Hello World</b></td><td><b>Output</b></td></tr><tr><td>

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


<table><tr><td><b>Multiplication (0xc*0xa)</b></td><td><b>Output (0xc*0xa=0x78)</b></td></tr><tr><td>

```c
#include "bf.c"

BF((c,a),G,R,G,L,B,R,B,D,R,I,R,I,L,L,E,R,
         R,B,D,L,L,I,R,R,E,L,L,L,D,E,R,R,O)
```

</td><td>

```
(78)
```

</td></tr></table>

Check out [examples.c](examples.c) for more examples.

## Getting started

Since the preprocessor can't distinguish between the standard Brainfuck symbols, this implementation uses the following alternative instruction names:

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

\*Note that there might be extra space inserted between symbols, because all preprocessors I know of disagree when spaces are inserted in `S(a)b` with `#define S(x) x` and different tokens in `a` and `b`.

## Preprocessors/Compilers

* [tcc](https://repo.or.cz/w/tinycc.git): use with `tcc -P -E`. tcc has the fastest preprocessor I know of.
* [gcc](https://gcc.gnu.org/): use with `gcc -P -E -ftrack-macro-expansion=0`. If you can't use tcc I recommend using gcc over clang, because it's faster, and gives you incremental output.
* [clang](https://clang.llvm.org/): use with `clang -P -E -fmacro-backtrace-limit=1`.
* msvc: use with `cl /P /C /Zc:preprocessor`. You need `/Zc:preprocessor`, because otherwise msvc will use a non-standard confirming preprocessor implementation.
* [mcpp](https://sourceforge.net/p/mcpp/): use with `mcpp -P -W0`. `-W0` is required, because the otherwise you'll get the warning "Replacement text ... of macro ... involved subsequent text", which is valid, but mcpp warns about it, because in "normal" code this is probably not indented behavior. There is also currently a [mcpp bug](https://sourceforge.net/p/mcpp/bugs/14/), where the add lookup table segfaults the preprocessor, so you'll need to disable `BF_SUM` for mcpp to preprocess the code.


If you want to get more fine grain information of execution times, then you might want to patch tcc with [tinycc.diff](tinycc.diff).
This adds the `__TIMER__` macro, which expands to the executed time and resets the timer, so the second `__TIMER__` in `__TIMER__ FOO __TIMER__` expands to the time it took to preprocess `FOO`.


## How does this work?

Check out the [tutorial](TUTORIAL.md), if you want to learn how I wrote this.

## Benchmarks with similar projects

The programs tested are also present in [examples.c](examples.c).


| Program                                                          | bfcpp  | [bfi](http://www.kotha.net/bfi//) | [CPP_COMPLETE](https://github.com/orangeduck/CPP_COMPLETE) | [preprocessor_brainfuck](https://github.com/Ferdi265/preprocessor_brainfuck) |
| ---                                                              | ---    | ---                               | ---                                                        | ---                                                                          |
| [Hello World](https://esolangs.org/wiki/Brainfuck)               | 0.020s | 0.048s                            | 23s                                                        | ~20 minutes                                                                  |
| [insertion sort](http://brainfuck.org/isort.b) 1                 | 0.049s | 0.11s                             | ---                                                        | ---                                                                          |
| [insertion sort](http://brainfuck.org/isort.b) 2                 | 0.09s  | 0.22s                             | ---                                                        | ---                                                                          |
| [insertion sort](http://brainfuck.org/isort.b) 3                 | 0.75s  | 1.7s                              | ---                                                        | ---                                                                          |
| [insertion sort](http://brainfuck.org/isort.b) 4                 | 2.15s  | 5.1s                              | ---                                                        | ---                                                                          |
| [sierpinski triangle](http://brainfuck.org/sierpinski.b)         | 5.60s  | 6.6s                              | ---                                                        | ---                                                                          |
| [square numbers from 0 to 10000](http://brainfuck.org/squares.b) | 11.49s | 11.45s                            | ---                                                        | ---                                                                          |
| [quine](http://brainfuck.org/392quine.b)                         | 32.22s | 283.3s                            | ---                                                        | ---                                                                          |


## Credit
Thanks to [notfoundry](https://github.com/notfoundry) and Jad Lévesque for helping me understand preprocessor meta programming.
Also, thanks to [bfi](http://www.kotha.net/bfi//), for the idea of the addition lookup table and a big motivation to further optimize my implementation.


## Licensing
For all files without an integrated license [LICENSE](LICENSE) applies.


