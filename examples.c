#include "bf.c"

#ifndef __TIMER__
#define __TIMER__
#endif
BF_FX(BF_SEQ_EAT,__TIMER__)


#if 1
// https://stackoverflow.com/questions/5165772/code-for-multiplying-two-one-digit-numbers-in-brainfuck
0xc * 0xa
BF((c,a),
G,R,G,L, // input numbers at cell #1 #2
B,
  R, // go to cell #2
  B,
    D,R,I,R,I,L,L, // move data to cell #3 #4
  E,
  R,R, // go to cell #4
  B,
    D,L,L,I,R,R, // move data to cell #2
  E,
  L,L,L, //  go to cell #1
  D, // decrement cell #1
E,
R,R,O
) __TIMER__
#endif


#if 1
// https://esolangs.org/wiki/Brainfuck
hello world:
BF((0),
I,I,I,I,I,I,I,I,B,R,I,I,I,I,B,R,I,I,R,I,I,I,R,I,I,I,R,I,L,L,L,L,D,E,R,I,R,I,R,D,R,R,I,B,L,E,L,D,E,R,R,A,R,D,D,D,A,I,I,I,I,I,I,I,A,A,I,I,I,A,R,R,A,L,D,A,L,A,I,I,I,A,D,D,D,D,D,D,A,D,D,D,D,D,D,D,D,A,R,R,I,A,R,I,I,A
) __TIMER__
#endif



#if 1
// http://brainfuck.org/isort.b
#define ISORT(...) BF((__VA_ARGS__,0), R,I,B,L,B,B,R,R,I,L,L,D,E,R,B,L,L,I,L,B,D,R,R,I,B,L,E,E,R,R,R,B,R,E,L,L,D,E,L,L,L,E,R,R,B,L,L,I,R,R,D,E,L,B,R,I,L,D,E,R,B,R,R,E,L,G,E,L,L,L,B,L,I,L,E,R,B,R,O,R,E)

insertion sort:
ISORT(3,1,1,3,1,2,2,3,2) __TIMER__
ISORT(3,1,7,9,5,2,6,4,8) __TIMER__
ISORT(6,9,3,2,8,7,1,5,4,1,3,5,4,9,2,6,8,7,6,2,8,5,1,4,7,3,9) __TIMER__
ISORT(6,9,9,3,2,8,7,1,5,4,1,3,5,4,9,2,6,8,7,3,2,8,7,1,5,4,1,3,5,4,9,2,6,8,7,6,2,8,5,1,4,7,3,9) __TIMER__
#endif



#if 1
// http://brainfuck.org/sierpinski.b
sierpinski:
BF((,0),
I,I,I,I,I,I,I,I,B,R,I,R,I,I,I,I,L,L,D,E,R,I,I,R,R,I,L,B,D,B,R,R,I,L,L,D,E,I,R,R,E,R,I,B,D,L,L,L,B,D,R,B,I,B,D,E,I,R,I,I,R,R,R,D,L,L,E,L,B,L,E,R,R,I,I,I,I,I,I,B,L,L,I,I,I,I,I,R,R,D,E,I,L,L,I,I,A,B,D,E,L,L,E,R,A,R,I,B,R,R,E,R,I,E
) __TIMER__
#endif


#if 1
// http://brainfuck.org/squares.b
squares:
BF((,0),
I,I,B,R,I,I,I,I,I,L,D,E,R,B,L,I,I,I,I,I,R,D,E,I,L,I,B,R,B,R,I,R,I,L,L,D,E,I,I,R,R,B,L,L,I,R,R,D,E,R,R,R,B,D,E,I,I,R,B,D,E,I,R,R,R,I,B,B,D,E,I,I,I,I,I,I,R,R,R,E,L,L,L,B,B,L,I,I,I,I,I,I,I,I,L,I,I,R,R,D,E,I,L,A,L,B,R,D,D,D,D,L,D,E,L,E,L,L,B,R,R,R,R,R,B,R,R,R,B,D,E,I,I,I,I,I,I,I,I,I,L,B,R,D,L,D,E,I,I,I,I,I,I,I,I,I,R,B,D,B,L,D,R,D,E,I,B,L,L,L,E,E,L,B,R,I,L,D,E,R,E,L,L,D,E,L,L,D,E
) __TIMER__
#endif


#if 1
// http://brainfuck.org/392quine.b
quine:
BF((0),D,R,I,I,R,I,I,I,R,I,R,I,R,I,I,I,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,I,R,I,R,I,I,R,I,I,I,R,I,I,R,R,I,I,I,R,I,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,I,R,I,R,R,I,I,I,R,R,I,I,I,R,R,R,R,R,I,I,I,R,I,R,R,R,R,R,R,R,R,R,I,I,R,I,I,I,R,I,I,I,R,I,R,R,I,I,I,R,R,R,I,I,I,R,I,R,I,I,R,I,I,I,R,R,R,I,R,I,R,I,I,R,I,I,I,R,I,R,I,R,R,I,I,I,R,R,R,R,R,R,R,I,R,I,R,R,R,I,R,I,R,I,I,R,I,I,I,R,I,I,I,R,I,R,R,I,I,I,R,R,R,I,I,I,R,I,R,I,I,R,I,I,I,R,I,I,R,R,I,R,I,R,I,I,R,I,I,I,R,I,R,I,R,R,I,I,I,R,R,R,R,R,I,I,I,R,I,R,R,R,R,R,I,I,R,I,I,I,R,I,I,I,R,I,R,R,I,I,I,R,R,R,I,I,I,R,I,R,I,I,I,R,I,R,R,I,I,I,R,R,I,I,I,R,R,I,I,B,B,R,R,I,B,R,E,I,I,R,I,I,B,L,E,L,D,E,R,I,B,R,E,L,I,L,I,I,I,B,L,E,L,I,E,R,I,B,R,E,I,I,I,I,R,I,I,B,B,L,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,R,D,E,L,I,I,I,I,I,I,I,I,I,A,L,E) __TIMER__
#endif

