
// If BF_TEST is defined then BF_ASSERT(a,b) macros
// are expanded. These form a valid C program that can be compiled
// and executed to test whether all assertions pass.
#ifdef BF_TEST

#include <assert.h>
#include <string.h>
int main(void) {

#define BF_ASSERT(a,b) assert(strcmp(BF_PSTR(a),#b) == 0);

#else
#define BF_ASSERT(a,b)
#endif

#define BF_CAT(a,b) a##b
#define BF_PCAT(a,b) BF_CAT(a,b)
#define BF_STR(a) #a
#define BF_PSTR(a) BF_STR(a)
#define BF_FX(f,...) f(__VA_ARGS__)
#define BF_SCAN(...) __VA_ARGS__
#define BF_NOSCAN(P,...) P##__VA_ARGS__
#define BF_LPAREN (

#define BF_TUPLE_AT_1(a,...) a
#define BF_TUPLE_AT_2(a,b,...) b
#define BF_TUPLE_SCAN_EAT2(a,b,...) __VA_ARGS__

#define BF_SEQ_EAT(...)
#define BF_SEQ_SPLAT(...) __VA_ARGS__,
#define BF_SEQ_AT_1(P,x) BF_SEQ_AT_1a(BF_SEQ_SPLAT P##x)
#define BF_SEQ_AT_1a(x) BF_TUPLE_AT_1(x)
BF_ASSERT(BF_SEQ_AT_1(,(1)(2)(3)), 1)


// Returns 1 if the identifiers x and y are equal and otherwise 0.
// For this to work a BF_EQUAL_X_X must be defined to ",1", where X is the
// identifier that shall be compared.
#define BF_EQUAL(x,y) BF_CHECK0(BF_EQUAL_##x##_##y)
#define BF_CHECK0(...) BF_TUPLE_AT_2(__VA_ARGS__,0,)
#define BF_CHECK(...) BF_TUPLE_AT_2(__VA_ARGS__,)

#define BF_IS_0(x) BF_CHECK0(BF_EQUAL_0_##x)
#define BF_EQUAL_0_0 ,1
BF_ASSERT(BF_IS_0(0), 1)
BF_ASSERT(BF_IS_0(24), 0)


// Returns 1 if a is empty and otherwise 0.
#define BF_IS_EMPTY(...) BF_FX(BF_TUPLE_AT_2,BF_IS_EMPTY_EXPAND __VA_ARGS__ (),0,)
#define BF_IS_EMPTY_EXPAND() ,1
BF_ASSERT(BF_IS_EMPTY(), 1)
BF_ASSERT(BF_IS_EMPTY(X), 0)



#include "math.c"
#include "format.c"
#include "cm.c"
#include "cm-debug.c"

// BF((input1,input2,...),instruction1,instruction2,...)
// executes the Brainfuck instructions with the specified input.
// The following are the corresponding Brainfuck instructions:
//     >   R   Move the tape head to the right
//     <   L   Move the tape head to the left
//     +   I   Increment the tape head
//     -   D   Decrement the tape head
//     .   A   Output the tape head as ASCII
//         O   Output the tape head as a hexadecimal number
//     ,   G   Read an input character and set the tape head to it
//     [   B   Jump past the matching ] if the cell at the pointer is 0
//     ]   E   Jump back to the matching [ if the cell at the pointer is nonzero
//         Q   Stops the execution
//
// The following can be used to convert from traditional brainfuck to this dialect:
// sed 's/,/,G/g;s/>/,R/g;s/</,L/g;s/+/,I/g;s/-/,D/g;s/\./,A/g;s/\[/,B/g;s/\]/,E/g;'

// The continuation consists of the following registers (P,i,tl,t,tr,is,f,...):
//
// empty (P): This is always empty and used by BF_CM to delay macro expansion,
//             which considerably speeds up the execution.
// input (i): sequence of inputs
// tape left (tl): (_) terminated stack of values on the left of the tape head
// tape head (t): value at the tape head
// tape right (tr): (_) terminated stack of values on the right of the tape head
// instruction stack (is): stack of used to restore the instructions inside of loops,
//                      after they have been executed
// instruction (f): this is the next instruction to be executed by BF_CM
// code (...): sequence of instructions to be executed
//
// The code is preprocessed by BF_TO_CODE to a sequence with nested loops, so
// "G,I,B,D,G,B,D,E,D,G,I,E" is turned into "(G)(I)(B)((D)(G)(B)((D)(E))(D)(G)(I)(E))".



// stops the continuations
#define BF__Q(P,i,tl,t,tr,is,...) )
BF_ASSERT(BF_LPAREN BF__Q(,i,tl,t,tr,is,(X)), ( ))

// increment tape head
#define BF__I(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_INC(P##t),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
BF_ASSERT(BF__I(,i,tl,2,tr,is,(a)(b)), (,i,tl,3,tr,is,a,(b)))

// decrement tape head
#define BF__D(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_DEC(P##t),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
BF_ASSERT(BF__D(,i,tl,2,tr,is,(a)(b)), (,i,tl,1,tr,is,a,(b)))

// reads from the input into the tape head
#define BF__G(P,i,tl,t,tr,is,...) (,BF_SEQ_EAT P##i,P##tl,BF_SEQ_AT_1(,P##i),P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
BF_ASSERT(BF__G(,(3)(4),tl,1,tr,is,(a)(b)), (,(4),tl,3,tr,is,a,(b)))


// All output is output in reverse, this is later reversed again by BF_FORMAT,
// which also converts the hex output to ASCII.
// Any output of the form (_(...)) isn't converted to ASCII and directly output.

// outputs tape head, this is later converted to ASCII
#define BF__A(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(P##t)
BF_ASSERT(BF__A(,i,tl,80,tr,is,(a)(b)), (,i,tl,80,tr,is,a,(b))(80))

// outputs current tape head
#define BF__O(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(_(P##t))
BF_ASSERT(BF__O(,i,tl,t,tr,is,(a)(b)), (,i,tl,t,tr,is,a,(b))(_(t)))

// Outputs the current state, this is for debugging purposes and only works when
// without BF_FORMAT, so either with BF_RAW.
// The output should be piped to sed 's/XXX/\n/g'|tac,
// so it's in the correct order and newlines are inserted appropriately.
// This should also be used if BF_DEBUG is defined, as this will essentially
// execute S after every executed instruction.
#define BF__S(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)(,#i,#tl,#t,#tr,#is,S,#__VA_ARGS__)XXX




// Eats the first element from a tape stack, without removing the terminating (_)
#define BF_TAPE_EAT(x) BF_CHECK(BF_TAPE_CHECK_##x,BF_TAPE_EAT0)
#define BF_TAPE_CHECK__ ,BF_TAPE_EAT1
#define BF_TAPE_EAT0
#define BF_TAPE_EAT1 (_)
BF_ASSERT(BF_TAPE_EAT(2)(1)(_) BF_TAPE_EAT(1)(_) BF_TAPE_EAT(_), (1)(_) (_) (_))


// Returns the first element from a tape stack.
// If the tape is (_), it will output 0.
#define BF_TAPE_AT_1(P,x) BF_FX(BF_TAPE_AT_1_1a,BF_SEQ_SPLAT P##x)
#define BF_TAPE_AT_1_1a(x,seq) BF_CHECK(BF_TAPE_AT_CHECK_##x,BF_TAPE_AT_1_0)(x)
#define BF_TAPE_AT_CHECK__ ,BF_TAPE_AT_1_1
#define BF_TAPE_AT_1_0(x) x
#define BF_TAPE_AT_1_1(x) 0
BF_ASSERT(BF_TAPE_AT_1(,(2)(1)(_)),2)
BF_ASSERT(BF_TAPE_AT_1(,(1)(_)),1)
BF_ASSERT(BF_TAPE_AT_1(,(_)),0)

// shifts the tape left/right
#define BF__L(P,i,tl,t,tr,is,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_AT_1(,P##tl),(P##t)P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF__R(P,i,tl,t,tr,is,...) (,P##i,(P##t)P##tl,BF_TAPE_AT_1(,P##tr),BF_TAPE_EAT P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
BF_ASSERT(BF__L(,i,(1)(_),2,(3)(_),is,(a)(b)), (,i,(_),1,(2)(3)(_),is,a,(b)))
BF_ASSERT(BF__R(,i,(1)(_),2,(3)(_),is,(a)(b)), (,i,(2)(1)(_),3,(_),is,a,(b)))
BF_ASSERT(BF__L(,i,(_),1,(2)(3)(_),is,(a)(b)), (,i,(_),0,(1)(2)(3)(_),is,a,(b)))
BF_ASSERT(BF__R(,i,(2)(1)(_),3,(_),is,(a)(b)), (,i,(3)(2)(1)(_),0,(_),is,a,(b)))



// The beginning of a loop:
#define BF__B(P,i,tl,t,tr,...) (,P##i,P##tl,P##t,P##tr,BF_PCAT(BF_B,BF_IS_0(P##t))(,P##__VA_ARGS__))

// If the tape head is 0, skip the loop
#define BF_B1(P,is,...) P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__)
BF_ASSERT(BF__B(,i,tl,0,tr,is,((a)(b)(c))(d)(e)), (,i,tl,0,tr,is,d,(e)))

// If the tape head is not 0, push the lopp body to the instruction stack and execute the loop body.
#define BF_B0(P,is,...) (BF_SEQ_AT_1(,P##__VA_ARGS__))P##is,BF_SCAN(BF_SEQ_SPLAT BF_SCAN P##__VA_ARGS__)
BF_ASSERT(BF__B(,i,tl,t,tr,is,((a)(b)(c))(d)(e)), (,i,tl,t,tr,((a)(b)(c))is,a,(b)(c)(d)(e)))



// The end of a loop:
#define BF__E(P,i,tl,t,tr,is,...) (,P##i,P##tl,P##t,P##tr,BF_PCAT(BF_E,BF_IS_0(P##t))(,P##is,P##__VA_ARGS__))

// If the tape head is 0, remove the loop from the instruction stack and continue execution.
#define BF_E1(P,is,...) BF_SEQ_EAT P##is,BF_SEQ_SPLAT P##__VA_ARGS__
BF_ASSERT(BF__E(,i,tl,0,tr,((a)(b))is,(c)(d)), (,i,tl,0,tr,is,c,(d)))

// If the tape isn't 0, execute the loop body from the top of the instruction stack again.
#define BF_E0(P,is,...) P##is,BF_SCAN(BF_SEQ_SPLAT BF_FX(BF_TUPLE_AT_1,BF_SEQ_SPLAT P##is))P##__VA_ARGS__
BF_ASSERT(BF__E(,i,tl,1,tr,((a)(b))is,(c)(d)), (,i,tl,1,tr,((a)(b))is,a,(b)(c)(d)))







// Converts instructions into an executable instruction sequences with nested loops.
// So "G,I,B,D,G,B,D,E,D,G,I,E" is turned into "(G)(I)(B)((D)(G)(B)((D)(E))(D)(G)(I)(E))".
#define BF_TO_CODE(...) BF_CM(,,,,,,TO_CODE,__VA_ARGS__,TO_CODE_Q,)


// Branches to BF_TO_CODE... for different values of f
#define BF__TO_CODE(P,o,is,_1,_2,_3,f,...) BF_CHECK(BF_TO_CODE_SWITCH_##f,BF_TO_CODE_0)(,P##f,P##o,P##is,,,,TO_CODE,P##__VA_ARGS__)

#define BF_TO_CODE_SWITCH_TO_CODE_Q ,BF_TO_CODE_Q
#define BF_TO_CODE_SWITCH_B ,BF_TO_CODE_B
#define BF_TO_CODE_SWITCH_E ,BF_TO_CODE_E

// Default: append the instruction to the sequence
#define BF_TO_CODE_0(P,x,o,...) (,P##o(P##x),P##__VA_ARGS__)
// TO_CODE_Q: stop and output code
#define BF_TO_CODE_Q(P,x,o,...) )P##o
// B: push output to the instruction stack
#define BF_TO_CODE_B(P,x,o,is,...) (,,(P##o(P##x))P##is,P##__VA_ARGS__)
// E: pop from the instructio stack to the output and parenthesize the old output
#define BF_TO_CODE_E(P,x,o,is,...) (,BF_SEQ_AT_1(,P##is)(P##o(P##x)),BF_SEQ_EAT P##is,P##__VA_ARGS__)

BF_ASSERT(BF_TO_CODE(1,2,3,B,4,5,B,6,7,E,B,8,9,E,10,E),
          (1)(2)(3)(B)((4)(5)(B)((6)(7)(E))(B)((8)(9)(E))(10)(E)))





#define BF_FORMAT(seq) BF_PSTR(BF_CM(,0,,seq(FMT_Q),,,FMT,))

#define BF_EQUAL_FMT_Q_FMT_Q ,1
#define BF__FMT(P,n,o,i,_1,_2,...) BF_FX(BF_FMT,,P##n,P##o,BF_SEQ_SPLAT P##i)

#define BF_FMT0(P,n,o,ni,i0,i) (,P##ni,BF_ASCII_APPEND##ni##n(,P##i0,P##o),P##i,,,FMT,)
#define BF_FMT1(P,n,o,...) )P##o
#define BF_FMT(P,n,o,i0,i) BF_PCAT(BF_FMT,BF_EQUAL(FMT_Q,P##i0)(,P##n,P##o,BF_ASCII(P##i0),P##i))





// Combines continues sequences of I's and D's to a single _i,n, so "I,I,D,I,I" turns into "_i,3".
// This is run before execution to optimize the code.
#if 0
#define BF_SUM(...) __VA_ARGS__
#else
#define BF_SUM(f,...) BF_SCAN(BF_TUPLE_SCAN_EAT2 BF_CM(,(,),0,,,,BF_SUM_SWITCH(f),f,__VA_ARGS__,SUM_Q,))

#define BF_SUM_SWITCH_SUM_Q ,SUM_Q
#define BF_SUM_SWITCH_I ,SUM_I
#define BF_SUM_SWITCH_D ,SUM_D
#define BF_SUM_CHECK(...) BF_TUPLE_AT_2(__VA_ARGS__,SUM_DEFAULT,)
#define BF_SUM_SWITCH(f) BF_SUM_CHECK(BF_SUM_SWITCH_##f)
BF_ASSERT(BF_SUM_SWITCH(I), SUM_I)
BF_ASSERT(BF_SUM_SWITCH(D), SUM_D)
BF_ASSERT(BF_SUM_SWITCH(x), SUM_DEFAULT)

#define BF_SUM_EXPAND0(x) _i,x,
#define BF_SUM_EXPAND1(x)
#define BF_SUM_EXPAND(x) BF_PCAT(BF_SUM_EXPAND,BF_IS_0(x))(x)

#define BF__SUM_DEFAULT(P,o,x,_1,_2,_3,f1,f2,...) (,(,BF_NOSCAN P##o,BF_SUM_EXPAND(P##x)P##f1),0,,,,BF_SUM_SWITCH(P##f2),P##f2,P##__VA_ARGS__)
BF_ASSERT(BF__SUM_DEFAULT(,(,A),0,,,,X,Y,Z), (,(,A,X),0,,,,SUM_DEFAULT,Y,Z))
BF_ASSERT(BF__SUM_DEFAULT(,(,A),4,,,,X,Y,Z), (,(,A,_i,4,X),0,,,,SUM_DEFAULT,Y,Z))

#define BF__SUM_I(P,o,x,_1,_2,_3,f1,f2,...) (,P##o,BF_INC(P##x),,,,BF_SUM_SWITCH(P##f2),P##f2,P##__VA_ARGS__)
#define BF__SUM_D(P,o,x,_1,_2,_3,f1,f2,...) (,P##o,BF_DEC(P##x),,,,BF_SUM_SWITCH(P##f2),P##f2,P##__VA_ARGS__)
BF_ASSERT(BF__SUM_I(,(,),5,,,,I,D,Z), (,(,),6,,,,SUM_D,D,Z))
BF_ASSERT(BF__SUM_D(,(,),5,,,,D,I,Z), (,(,),4,,,,SUM_I,I,Z))
BF_ASSERT(BF__SUM_D(,(,),5,,,,D,X,Z), (,(,),4,,,,SUM_DEFAULT,X,Z))

#define BF__SUM_Q(P,o,x,_2,_3,_4,f,...) )P##o
BF_ASSERT((BF_SUM(I,I,D,X,Y,Z,D,D,D,Q)), (_i,1,X,Y,Z,_i,fd,Q))

#define BF___i(P,i,tl,t,tr,is,...) (,P##i,P##tl,BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__))(P##t),P##tr,P##is,BF_SCAN(BF_SEQ_SPLAT BF_SEQ_EAT P##__VA_ARGS__))
BF_ASSERT(BF___i(,i,tl,2,tr,is,(7)(a)(b)), (,i,tl,9,tr,is,a,(b)))

#endif






// Merges instructions whenever possible and replaces some combinations of
// instructions with specialized, faster implementations.
// This is run before execution to optimize the code.
#if 0
#define BF_MERGE(...) __VA_ARGS__,
#else
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


#define BF_MERGE_DO1234_0(P,a1,a2,a3,a4,...) BF_MERGE_DO124(BF_CHECK0(BF_MERGE_1234_##a1##a2##a3##a4))(,P##a1,P##a2,P##a3,P##a4)
#define BF_MERGE_DO124_1(...) 1234
#define BF_MERGE_DO124_CAT(a,b) a##b
#define BF_MERGE_DO124(x) BF_MERGE_DO124_CAT(BF_MERGE_DO124_,x)

#define BF_MERGE_DO124_0(P,a1,a2,a3,a4) BF_MERGE_DO123(BF_CHECK0(BF_MERGE_124_##a1##a2##a4))(,P##a1,P##a2,P##a3)
#define BF_MERGE_DO123_1(...) 124
#define BF_MERGE_DO123_3(...) 124_3
#define BF_MERGE_DO123_CAT(a,b) a##b
#define BF_MERGE_DO123(x) BF_MERGE_DO123_CAT(BF_MERGE_DO123_,x)

#define BF_MERGE_DO123_0(P,a1,a2,a3) BF_MERGE_DO13(BF_CHECK0(BF_MERGE_123_##a1##a2##a3))(,P##a1,P##a2,P##a3)
#define BF_MERGE_DO13_1(...) 123
#define BF_MERGE_DO13_CAT(a,b) a##b
#define BF_MERGE_DO13(x) BF_MERGE_DO13_CAT(BF_MERGE_DO13_,x)

#define BF_MERGE_DO13_0(P,a1,a2,a3) BF_MERGE_DO12(BF_CHECK0(BF_MERGE_13_##a1##a3))(,P##a1,P##a2)
#define BF_MERGE_DO12_1(...) 13
#define BF_MERGE_DO12_2(...) 13_2
#define BF_MERGE_DO12_CAT(a,b) a##b
#define BF_MERGE_DO12(x) BF_MERGE_DO12_CAT(BF_MERGE_DO12_,x)

#define BF_MERGE_DO12_0(P,a1,a2) BF_MERGE_DO1(BF_CHECK0(BF_MERGE_12_##a1##a2))
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

#define BF_MERGE_12__i1 I,1
#define BF_MERGE_12__iff D,1

#define BF_MERGE_124_B_iE _0,1
#define BF___0(P,i,tl,t,tr,is,...) (,P##i,P##tl,0,P##tr,P##is,BF_SEQ_SPLAT P##__VA_ARGS__)


// This uses recursive sequence iteration, whether this
// BF_HAS_SEQ_ITERa()()() expands nested or not is unspecified behavior.
// Since there are only two options, we can detect if the expansion isn't nested
// and use this to write faster implementations of some functions.
#define BF_HAS_SEQ_ITER BF_PCAT(BF_,BF_HAS_SEQ_ITERa()()())
#define BF_HAS_SEQ_ITERa() BF_HAS_SEQ_ITERb
#define BF_HAS_SEQ_ITERb() BF_HAS_SEQ_ITERa

#define BF_BF_HAS_SEQ_ITERa() 0
#define BF_BF_HAS_SEQ_ITERb 1

#if 0
#elif BF_HAS_SEQ_ITER

// Specialized implementation of [>] and [<], which a common patters.
#define BF_MERGE_123_BLE _L0,1
#define BF_MERGE_123_BRE _R0,1


#define BF_L0_TO_GUIDE_SWITCH_0 ,BF_L0_TO_GUIDE_1
#define BF_L0_TO_GUIDE_SWITCH__ ,BF_L0_TO_GUIDE_2

#define BF_L0_TO_GUIDE_0(a,f) ,a)f
#define BF_L0_TO_GUIDE_1(a,f) ,0),
#define BF_L0_TO_GUIDE_2(a,f) ,0),(_)

#define BF_L0_TO_GUIDE1(a) BF_CHECK(BF_L0_TO_GUIDE_SWITCH_##a,BF_L0_TO_GUIDE_0)(a,BF_L0_TO_GUIDE2)
#define BF_L0_TO_GUIDE2(a) BF_CHECK(BF_L0_TO_GUIDE_SWITCH_##a,BF_L0_TO_GUIDE_0)(a,BF_L0_TO_GUIDE1)



#define BF_L0_EXEC_SWITCH_0 ,BF_L0_EXEC_1
#define BF_L0_EXEC_SWITCH__ ,BF_L0_EXEC_2

#define BF_L0_EXEC_0(a,b,f) f((b)a
#define BF_L0_EXEC_1(a,b,f) a,0

#define BF_L0_EXEC1(a,b) BF_CHECK(BF_L0_EXEC_SWITCH_##b,BF_L0_EXEC_0)(a,b,BF_L0_EXEC2)
#define BF_L0_EXEC2(a,b) BF_CHECK(BF_L0_EXEC_SWITCH_##b,BF_L0_EXEC_0)(a,b,BF_L0_EXEC1)


#define BF_L0_DO(t,tr) BF_SCAN(BF_L0_EXEC1 BF_LPAREN BF_L0_TO_GUIDE1(t)tr)

#define BF_L0a(tl1,tl0,t,tr) BF_CAT(,tl0)tl1,t,tr
#define BF_R0a(tr1,tr0,t,tl) tl,t,BF_CAT(,tr0)tr1

#define BF___R0(P,i,tl,t,tr,is,...) (,P##i,BF_FX(BF_L0a,tl,BF_L0_DO(t,tr)),P##is,BF_SEQ_SPLAT P##__VA_ARGS__)
#define BF___L0(P,i,tl,t,tr,is,...) (,P##i,BF_FX(BF_R0a,tr,BF_L0_DO(t,tl)),P##is,BF_SEQ_SPLAT P##__VA_ARGS__)

BF_ASSERT(BF___L0(,,(3)(2)(0)(1)(_),4,(5)(6)(0)(7)(8)(_),,(Q)), (,,(1)(_),0,(2)(3)(4)(5)(6)(0)(7)(8)(_),,Q,))
BF_ASSERT(BF___R0(,,(3)(2)(0)(1)(_),4,(5)(6)(0)(7)(8)(_),,(Q)), (,,(6)(5)(4)(3)(2)(0)(1)(_),0,(7)(8)(_),,Q,))
BF_ASSERT(BF___L0(,,(3)(2)(1)(_),4,(5)(6)(7)(8)(_),,(Q)), (,,(_),0,(1)(2)(3)(4)(5)(6)(7)(8)(_),,Q,))
BF_ASSERT(BF___R0(,,(3)(2)(1)(_),4,(5)(6)(7)(8)(_),,(Q)), (,,(8)(7)(6)(5)(4)(3)(2)(1)(_),0,(_),,Q,))

#endif

#endif




#ifndef BF_DEBUG
#define BF(input,...) BF_FORMAT(BF_CM(,BF_TO_CODE input(),(_),0,(_),,BF_SCAN(BF_SEQ_SPLAT BF_TO_CODE(BF_MERGE(BF_SUM(__VA_ARGS__,Q))))))
#else
#define BF(input,...) BF_CM_DBG(,BF_TO_CODE input(),(_),0,(_),,BF_SCAN(BF_SEQ_SPLAT BF_TO_CODE(BF_MERGE(BF_SUM(__VA_ARGS__,Q)))))
#endif



#ifdef BF_TEST
	return 0;
}

#endif
