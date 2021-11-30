#define BF_CAT(a,b) a##b
#define BF_PCAT(a,b) BF_CAT(a,b)

// If BF_DO_ASSERT is defined then BF_ASSERT(a,b) macros
// are expanded. These form a valid C program that can be compiled
// and executed to test whether all assertions pass.
#ifdef BF_DO_ASSERT

#include <assert.h>
#include <string.h>
int main(void) {

#define BF_ASSERT(a,b) BF_ASSERTa(a,b)
#define BF_ASSERTa(a,b) assert(strcmp(#a,#b) == 0);

#else
#define BF_ASSERT(a,b)
#endif


#define BF_SCAN(...) __VA_ARGS__
#define BF_PSCAN(P,...) P##__VA_ARGS__
#define BF_EAT(...)
#define BF_FX(f,...) f(__VA_ARGS__)
#define BF_SPLIT(...) (__VA_ARGS__),
#define BF_SPLAT(...) __VA_ARGS__,
#define BF_LPAREN (
#define BF_RPAREN (
#define BF_EMPTY()

#define BF_TUPLE_EAT2(a,b,...) __VA_ARGS__
#define BF_TUPLE_AT_1(x,...) x
#define BF_PTUPLE_AT_1(...) BF_TUPLE_AT_1(__VA_ARGS__)

#define BF_SEQ_AT_1(P,x) BF_SEQ_AT_1a(BF_SPLAT P##x)
#define BF_SEQ_AT_1a(x) BF_TUPLE_AT_1(x)
BF_ASSERT(BF_SEQ_AT_1(,(1)(2)(3)), 1)


// Returns 1 if the identifiers x and y are equal and otherwise 0.
// For this to work a BF_EQUAL_X_X must be defined to ",1", where X is the
// identifier that shall be compared.
#define BF_EQUAL(x,y) BF_CHECK(BF_EQUAL_##x##_##y)
#define BF_CHECK_N(P,x,n,...) P##n
#define BF_CHECK(...) BF_CHECK_N(,__VA_ARGS__,0,~)

#define BF_EQUAL_0_0 ,1
#define BF_IS_0(x) BF_CHECK(BF_EQUAL_0_##x)
BF_ASSERT(BF_IS_0(0), 1)
BF_ASSERT(BF_IS_0(24), 0)


// Returns 1 if t is empty and otherwise 0.
#define BF_IS_EMPTY(P,t) BF_HAS_COMMA(,1,0,BF_IS_EMPTY_ADD_COMMA t ())
#define BF_HAS_COMMA_TEST(P,a0,a1,a2,...) P##a2
#define BF_HAS_COMMA(P,t,f,...) BF_HAS_COMMA_TEST(,__VA_ARGS__,P##t,P##f,~)
#define BF_IS_EMPTY_ADD_COMMA() ,
BF_ASSERT(BF_IS_EMPTY(,), 1)
BF_ASSERT(BF_IS_EMPTY(,X), 0)



#include "math.c"
#include "cm.c"
#include "cm-debug.c"
#include "format.c"

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

// The continuation consists of the following registers (P,i,tl,t,tr,fs,f,...):
//
// empty (P): This is always empty and used by BF_CM to delay macro expansion,
//             which considerably speeds up the execution.
// input (i): sequence of inputs
// tape left (tl): (_) terminated stack of values on the left of the tape head
// tape head (t): value at the tape head
// tape right (tr): (_) terminated stack of values on the right of the tape head
// function stack (fs): stack of used to restore the functions inside of loops,
//                      after they have been executed
// function (f): this is the next function to be executed by BF_CM
// code (...): sequence of instructions to be executed
//
// The code is preprocessed by BF_TO_CODE to a sequence with nested loops, so
// "G,I,B,D,G,B,D,E,D,G,I,E" is turned into "(G)(I)(B)((D)(G)(B)((D)(E))(D)(G)(I)(E))".



// stops the continuations
#define BF__Q(P,i,tl,t,tr,fs,...) )
BF_ASSERT(BF_LPAREN BF__Q(,i,tl,t,tr,fs,(X)), ( ))

// increment tape head
#define BF__I(P,i,tl,t,tr,fs,...) (,P##i,P##tl,BF_INC(P##t),P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)
BF_ASSERT(BF__I(,i,tl,2,tr,fs,(a)(b)), (,i,tl,3,tr,fs,a,(b)))

// decrement tape head
#define BF__D(P,i,tl,t,tr,fs,...) (,P##i,P##tl,BF_DEC(P##t),P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)
BF_ASSERT(BF__D(,i,tl,2,tr,fs,(a)(b)), (,i,tl,1,tr,fs,a,(b)))

// reads from the input into the tape head
#define BF__G(P,i,tl,t,tr,fs,...) (,BF_EAT P##i,P##tl,BF_SEQ_AT_1(,P##i),P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)
BF_ASSERT(BF__G(,(3)(4),tl,1,tr,fs,(a)(b)), (,(4),tl,3,tr,fs,a,(b)))


// All output is output in reverse, this is later reversed again by BF_FORMAT,
// which also converts the hex output to ASCII.
// Any output of the form (_(...)) isn't converted to ASCII and directly output.

// outputs tape head, this is later converted to ASCII
#define BF__A(P,i,tl,t,tr,fs,...) (,P##i,P##tl,P##t,P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)(P##t)
BF_ASSERT(BF__A(,i,tl,80,tr,fs,(a)(b)), (,i,tl,80,tr,fs,a,(b))(80))

// outputs current tape head
#define BF__O(P,i,tl,t,tr,fs,...) (,P##i,P##tl,P##t,P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)(_(P##t))
BF_ASSERT(BF__O(,i,tl,t,tr,fs,(a)(b)), (,i,tl,t,tr,fs,a,(b))(_(t)))

// Outputs the current state, this is for debugging purposes and only works when
// without BF_FORMAT, so either with BF_RAW.
// The output should be piped to sed 's/XXX/\n/g'|tac,
// so it's in the correct order and newlines are inserted appropriately.
// This should also be used if BF_DEBUG is defined, as this will essentially
// execute S after every executed instruction.
#define BF__S(P,i,tl,t,tr,fs,...) (,P##i,P##tl,P##t,P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)(,#i,#tl,#t,#tr,#fs,S,#__VA_ARGS__)XXX




// Eats the first element from a tape stack, without removing the terminating (_)
#define BF_TAPE_EAT(x) BF_PCAT(BF_TAPE_EAT,BF_CHECK(BF_TAPE_CHECK_##x))
#define BF_TAPE_CHECK__ ,1
#define BF_TAPE_EAT0
#define BF_TAPE_EAT1 (_)
BF_ASSERT(BF_TAPE_EAT(2)(1)(_) BF_TAPE_EAT(1)(_) BF_TAPE_EAT(_), (1)(_) (_) (_))


// Returns the first element from a tape stack.
// If the tape is (_), it will output 0.
#define BF_TAPE_FST(P,x) BF_FX(BF_TAPE_FST_1a,BF_SPLAT P##x)
#define BF_TAPE_FST_1a(x,seq) BF_PCAT(BF_TAPE_FST,BF_CHECK(BF_TAPE_CHECK_##x))(x)
#define BF_TAPE_FST0(x) x
#define BF_TAPE_FST1(x) 0
BF_ASSERT(BF_TAPE_FST(,(2)(1)(_)),2)
BF_ASSERT(BF_TAPE_FST(,(1)(_)),1)
BF_ASSERT(BF_TAPE_FST(,(_)),0)

// shifts the tape left/right
#define BF__L(P,i,tl,t,tr,fs,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_FST(,P##tl),(P##t)P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)
#define BF__R(P,i,tl,t,tr,fs,...) (,P##i,(P##t)P##tl,BF_TAPE_FST(,P##tr),BF_TAPE_EAT P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)
BF_ASSERT(BF__L(,i,(1)(_),2,(3)(_),fs,(a)(b)), (,i,(_),1,(2)(3)(_),fs,a,(b)))
BF_ASSERT(BF__R(,i,(1)(_),2,(3)(_),fs,(a)(b)), (,i,(2)(1)(_),3,(_),fs,a,(b)))
BF_ASSERT(BF__L(,i,(_),1,(2)(3)(_),fs,(a)(b)), (,i,(_),0,(1)(2)(3)(_),fs,a,(b)))
BF_ASSERT(BF__R(,i,(2)(1)(_),3,(_),fs,(a)(b)), (,i,(3)(2)(1)(_),0,(_),fs,a,(b)))



// The beginning of a loop:
#define BF__B(P,i,tl,t,tr,...) (,P##i,P##tl,P##t,P##tr,BF_PCAT(BF_B,BF_IS_0(P##t))(,P##__VA_ARGS__))

// If the tape head is zero, skip to the closing `]` (E).
#define BF_B1(P,fs,...) P##fs,BF_SCAN(BF_SPLAT BF_EAT P##__VA_ARGS__)
BF_ASSERT(BF__B(,i,tl,0,tr,fs,((a)(b)(c))(d)(e)), (,i,tl,0,tr,fs,d,(e)))

// If the tape head is not zero, push the continuation and execute the next loop body.
#define BF_B0(P,fs,...) (BF_SEQ_AT_1(,P##__VA_ARGS__))P##fs,BF_SCAN(BF_SPLAT BF_SCAN P##__VA_ARGS__)
BF_ASSERT(BF__B(,i,tl,t,tr,fs,((a)(b)(c))(d)(e)), (,i,tl,t,tr,((a)(b)(c))fs,a,(b)(c)(d)(e)))



// The end of a loop:
#define BF__E(P,i,tl,t,tr,fs,...) (,P##i,P##tl,P##t,P##tr,BF_PCAT(BF_E,BF_IS_0(P##t))(,P##fs,P##__VA_ARGS__))

// If the tape head is zero, remove the loop from the function stack and continue execution.
#define BF_E1(P,fs,...) BF_EAT P##fs,BF_SPLAT P##__VA_ARGS__
BF_ASSERT(BF__E(,i,tl,0,tr,((a)(b))fs,(c)(d)), (,i,tl,0,tr,fs,c,(d)))

// If the tape isn't zero, execute the loop body from the top of the function stack.
#define BF_E0(P,fs,...) P##fs,BF_SCAN(BF_SPLAT BF_PTUPLE_AT_1(BF_SPLAT P##fs))P##__VA_ARGS__
BF_ASSERT(BF__E(,i,tl,1,tr,((a)(b))fs,(c)(d)), (,i,tl,1,tr,((a)(b))fs,a,(b)(c)(d)))







// Converts instructions into an executable instruction sequences with nested loops.
// So "G,I,B,D,G,B,D,E,D,G,I,E" is turned into "(G)(I)(B)((D)(G)(B)((D)(E))(D)(G)(I)(E))".
#define BF_TO_CODE(...) BF_CM(,,,,,,TO_CODE,__VA_ARGS__,TO_CODE_Q,~)


#define BF_EQUAL_TO_CODE_Q_TO_CODE_Q ,1
#define BF_EQUAL_B_B ,1
#define BF_EQUAL_E_E ,1

// Branches to BF_TO_CODE... for different values of f
#define BF__TO_CODE(P,o,fs,_1,_2,_3,f,...) BF_PCAT(BF_TO_CODE, \
		BF_PCAT(BF_EQUAL(TO_CODE_Q,P##f), \
		BF_PCAT(BF_EQUAL(B,P##f), \
		        BF_EQUAL(E,P##f)))) \
	(,P##f,P##o,P##fs,,,,TO_CODE,P##__VA_ARGS__)

// Default: just append the instruction to the sequence
#define BF_TO_CODE000(P,x,o,...) (,P##o(P##x),P##__VA_ARGS__)
// TO_CODE_Q: stop and output code
#define BF_TO_CODE100(P,x,o,...) )P##o
// B: push output to fs
#define BF_TO_CODE010(P,x,o,fs,...) (,,(P##o(P##x))P##fs,P##__VA_ARGS__)
// E: pop from fs to the output and parenthesize the old output
#define BF_TO_CODE001(P,x,o,fs,...) (,BF_SEQ_AT_1(,P##fs)(P##o(P##x)),BF_EAT P##fs,P##__VA_ARGS__)

BF_ASSERT(BF_TO_CODE(1,2,3,B,4,5,B,6,7,E,B,8,9,E,10,E),
          (1)(2)(3)(B)((4)(5)(B)((6)(7)(E))(B)((8)(9)(E))(10)(E)))






// Combines continues sequences of I's and D's to a single _i,n, so "I,I,D,I,I" turns into "_i,3".
// This is run before execution to optimize the code.
#if 0
#define BF_SUM(...) __VA_ARGS__
#else
#define BF_SUM(f,...) BF_SCAN(BF_TUPLE_EAT2 BF_CM(,(,),0,,,,BF_SUM_SWITCH(f),f,__VA_ARGS__,SUM_Q,))

#define BF_SUM_SWITCH_SUM_Q ,SUM_Q
#define BF_SUM_SWITCH_I ,SUM_I
#define BF_SUM_SWITCH_D ,SUM_D
#define BF_SUM_CHECK(...) BF_CHECK_N(,__VA_ARGS__,SUM_DEFAULT,)
#define BF_SUM_SWITCH(f) BF_SUM_CHECK(BF_SUM_SWITCH_##f)
BF_ASSERT(BF_SUM_SWITCH(I), SUM_I)
BF_ASSERT(BF_SUM_SWITCH(D), SUM_D)
BF_ASSERT(BF_SUM_SWITCH(x), SUM_DEFAULT)

#define BF_SUM_EXPAND0(x) _i,x,
#define BF_SUM_EXPAND1(x)
#define BF_SUM_EXPAND(x) BF_PCAT(BF_SUM_EXPAND,BF_IS_0(x))(x)

#define BF__SUM_DEFAULT(P,o,x,_1,_2,_3,f1,f2,...) (,(,BF_PSCAN P##o,BF_SUM_EXPAND(P##x)P##f1),0,,,,BF_SUM_SWITCH(P##f2),P##f2,P##__VA_ARGS__)
BF_ASSERT(BF__SUM_DEFAULT(,(,A),0,,,,X,Y,Z), (,(,A,X),0,,,,SUM_DEFAULT,Y,Z))
BF_ASSERT(BF__SUM_DEFAULT(,(,A),4,,,,X,Y,Z), (,(,A,_i,4,X),0,,,,SUM_DEFAULT,Y,Z))

#define BF__SUM_I(P,o,x,_1,_2,_3,f1,f2,...) (,P##o,BF_INC(P##x),,,,BF_SUM_SWITCH(P##f2),P##f2,P##__VA_ARGS__)
#define BF__SUM_D(P,o,x,_1,_2,_3,f1,f2,...) (,P##o,BF_DEC(P##x),,,,BF_SUM_SWITCH(P##f2),P##f2,P##__VA_ARGS__)
BF_ASSERT(BF__SUM_I(,(,),5,,,,I,D,Z), (,(,),6,,,,SUM_D,D,Z))
BF_ASSERT(BF__SUM_D(,(,),5,,,,D,I,Z), (,(,),4,,,,SUM_I,I,Z))
BF_ASSERT(BF__SUM_D(,(,),5,,,,D,X,Z), (,(,),4,,,,SUM_DEFAULT,X,Z))

#define BF__SUM_Q(P,o,x,_2,_3,_4,f,...) )P##o
BF_ASSERT((BF_SUM(I,I,D,X,Y,Z,D,D,D,Q)), (_i,1,X,Y,Z,_i,fd,Q))

#define BF___i(P,i,tl,t,tr,fs,...) (,P##i,P##tl,BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__))(P##t),P##tr,P##fs,BF_SCAN(BF_SPLAT BF_EAT P##__VA_ARGS__))
BF_ASSERT(BF___i(,i,tl,2,tr,fs,(7)(a)(b)), (,i,tl,9,tr,fs,a,(b)))

#endif





// Merges instructions whenever possible and replaces some combinations of
// instructions with specialized, faster implementations.
// This is run before execution to optimize the code.
#if 0
#define BF_MERGE(...) __VA_ARGS__,
#elif 1
#define BF_MERGE(...) BF_SCAN(BF_TUPLE_EAT2 BF_CM(,(,),,,,,MERGE0,__VA_ARGS__,,,,,))

#define BF_MERGE1(P,o,a1,...)               (,(,BF_PSCAN P##o,P##a1)                                         ,,,,,BF_PCAT(MERGE,BF_IS_EMPTY(,P##a1)),P##__VA_ARGS__)
#define BF_MERGE12(P,o,a1,a2,...)           (,(,BF_PSCAN P##o,BF_PTUPLE_AT_1(BF_MERGE_12_##a1##a2))          ,,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE13(P,o,a1,a2,a3,...)        (,(,BF_PSCAN P##o,BF_PTUPLE_AT_1(BF_MERGE_13_##a1##a3))          ,,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE13_2(P,o,a1,a2,a3,...)      (,(,BF_PSCAN P##o,BF_PTUPLE_AT_1(BF_MERGE_13_##a1##a3))          ,,,,,MERGE0,P##a2,P##__VA_ARGS__)
#define BF_MERGE123(P,o,a1,a2,a3,...)       (,(,BF_PSCAN P##o,BF_PTUPLE_AT_1(BF_MERGE_123_##a1##a2##a3))     ,,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE124(P,o,a1,a2,a3,a4,...)    (,(,BF_PSCAN P##o,BF_PTUPLE_AT_1(BF_MERGE_124_##a1##a2##a4))     ,,,,,MERGE0,P##__VA_ARGS__)
#define BF_MERGE124_3(P,o,a1,a2,a3,a4,...)  (,(,BF_PSCAN P##o,BF_PTUPLE_AT_1(BF_MERGE_124_##a1##a2##a4))     ,,,,,MERGE0,P##a3,P##__VA_ARGS__)

#define BF__MERGE1(P,o,...) )P##o
#define BF__MERGE0(P,o,_1,_2,_3,_4,...) BF_PCAT(BF_MERGE,BF_MERGE_DO124(,P##__VA_ARGS__))(,P##o,P##__VA_ARGS__)


#define BF_MERGE_DO1_0 1
#define BF_MERGE_DO1_1 12
#define BF_MERGE_DO12_0(P,a1,a2) BF_PCAT(BF_MERGE_DO1_,BF_CHECK(BF_MERGE_12_##a1##a2))
#define BF_MERGE_DO12_1(...) 13
#define BF_MERGE_DO12_2(...) 13_2
#define BF_MERGE_DO13_0(P,a1,a2,a3) BF_PCAT(BF_MERGE_DO12_,BF_CHECK(BF_MERGE_13_##a1##a3))(,P##a1,P##a2)
#define BF_MERGE_DO13_1(...) 123
#define BF_MERGE_DO123_0(P,a1,a2,a3) BF_PCAT(BF_MERGE_DO13_,BF_CHECK(BF_MERGE_123_##a1##a2##a3))(,P##a1,P##a2,P##a3)
#define BF_MERGE_DO123_1(...) 124
#define BF_MERGE_DO123_3(...) 124_3
#define BF_MERGE_DO124(P,a1,a2,a3,a4,...) BF_PCAT(BF_MERGE_DO123_,BF_CHECK(BF_MERGE_124_##a1##a2##a4))(,P##a1,P##a2,P##a3)


#define BF_MERGE_12_L_i _Li,1
#define BF_MERGE_12_R_i _Ri,1
#define BF___Li(P,i,tl,t,tr,fs,...) (,P##i,BF_TAPE_EAT P##tl,BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__)(BF_TAPE_FST(,P##tl))),(P##t)P##tr,P##fs,BF_SCAN(BF_SPLAT BF_EAT P##__VA_ARGS__))
#define BF___Ri(P,i,tl,t,tr,fs,...) (,P##i,(P##t)P##tl,BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__)(BF_TAPE_FST(,P##tr))),BF_TAPE_EAT P##tr,P##fs,BF_SCAN(BF_SPLAT BF_EAT P##__VA_ARGS__))

#define BF_MERGE_13__iL _iL,2
#define BF_MERGE_13__iR _iR,2
#define BF___iL(P,i,tl,t,tr,fs,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_FST(,P##tl),(BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__))(P##t))P##tr,P##fs,BF_SCAN(BF_SPLAT BF_EAT P##__VA_ARGS__))
#define BF___iR(P,i,tl,t,tr,fs,...) (,P##i,(BF_PCAT(BF_ADD_,BF_SEQ_AT_1(,P##__VA_ARGS__))(P##t))P##tl,BF_TAPE_FST(,P##tr),BF_TAPE_EAT P##tr,P##fs,BF_SCAN(BF_SPLAT BF_EAT P##__VA_ARGS__))

#define BF_MERGE_123_L_i1 LI,1
#define BF_MERGE_123_L_iff LD,1
#define BF_MERGE_123_R_i1 RI,1
#define BF_MERGE_123_R_iff RD,1
#define BF__LI(P,i,tl,t,tr,fs,...) (,P##i,BF_TAPE_EAT P##tl,BF_PINC(BF_TAPE_FST(,P##tl)),(P##t)P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)
#define BF__LD(P,i,tl,t,tr,fs,...) (,P##i,BF_TAPE_EAT P##tl,BF_PDEC(BF_TAPE_FST(,P##tl)),(P##t)P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)
#define BF__RI(P,i,tl,t,tr,fs,...) (,P##i,(P##t)P##tl,BF_PINC(BF_TAPE_FST(,P##tr)),BF_TAPE_EAT P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)
#define BF__RD(P,i,tl,t,tr,fs,...) (,P##i,(P##t)P##tl,BF_PDEC(BF_TAPE_FST(,P##tr)),BF_TAPE_EAT P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)

#define BF_MERGE_123__i1L IL,1
#define BF_MERGE_123__iffL DL,1
#define BF_MERGE_123__i1R IR,1
#define BF_MERGE_123__iffR DR,1
#define BF__IL(P,i,tl,t,tr,fs,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_FST(,P##tl),(BF_INC(P##t))P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)
#define BF__DL(P,i,tl,t,tr,fs,...) (,P##i,BF_TAPE_EAT P##tl,BF_TAPE_FST(,P##tl),(BF_DEC(P##t))P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)
#define BF__IR(P,i,tl,t,tr,fs,...) (,P##i,(BF_INC(P##t))P##tl,BF_TAPE_FST(,P##tr),BF_TAPE_EAT P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)
#define BF__DR(P,i,tl,t,tr,fs,...) (,P##i,(BF_DEC(P##t))P##tl,BF_TAPE_FST(,P##tr),BF_TAPE_EAT P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)

#define BF_MERGE_12__i1 I,1
#define BF_MERGE_12__iff D,1

#define BF_MERGE_124_B_iE _0,1
#define BF___0(P,i,tl,t,tr,fs,...) (,P##i,P##tl,0,P##tr,P##fs,BF_SPLAT P##__VA_ARGS__)


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

#define BF___R0(P,i,tl,t,tr,fs,...) (,P##i,BF_FX(BF_L0a,tl,BF_L0_DO(t,tr)),P##fs,BF_SPLAT P##__VA_ARGS__)
#define BF___L0(P,i,tl,t,tr,fs,...) (,P##i,BF_FX(BF_R0a,tr,BF_L0_DO(t,tl)),P##fs,BF_SPLAT P##__VA_ARGS__)

BF_ASSERT(BF___L0(,,(3)(2)(0)(1)(_),4,(5)(6)(0)(7)(8)(_),,(Q)), (,,(1)(_),0,(2)(3)(4)(5)(6)(0)(7)(8)(_),,Q,))
BF_ASSERT(BF___R0(,,(3)(2)(0)(1)(_),4,(5)(6)(0)(7)(8)(_),,(Q)), (,,(6)(5)(4)(3)(2)(0)(1)(_),0,(7)(8)(_),,Q,))
BF_ASSERT(BF___L0(,,(3)(2)(1)(_),4,(5)(6)(7)(8)(_),,(Q)), (,,(_),0,(1)(2)(3)(4)(5)(6)(7)(8)(_),,Q,))
BF_ASSERT(BF___R0(,,(3)(2)(1)(_),4,(5)(6)(7)(8)(_),,(Q)), (,,(8)(7)(6)(5)(4)(3)(2)(1)(_),0,(_),,Q,))

#endif

#endif





#ifndef BF_DEBUG
#define BF(input,...) BF_FORMAT(BF_CM(,BF_TO_CODE input,(0)(_),0,(0)(_),,BF_SCAN(BF_SPLAT BF_TO_CODE(BF_MERGE(BF_SUM(__VA_ARGS__,Q))))))
#define BF_RAW(input,...) BF_CM(,BF_TO_CODE input,(0)(_),0,(0)(_),,BF_SCAN(BF_SPLAT BF_TO_CODE(BF_MERGE(BF_SUM(__VA_ARGS__,Q)))))
#else
#define BF(input,...) BF_CM_DBG(,BF_TO_CODE input,(0)(_),0,(0)(_),,BF_SCAN(BF_SPLAT BF_TO_CODE(BF_MERGE(BF_SUM(__VA_ARGS__,Q)))))
#endif



#ifdef BF_DO_ASSERT
	return 0;
}

#endif
