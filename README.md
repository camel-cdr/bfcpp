# Optimizing Brainfuck interpreter in the C preprocessor

# Getting started

Since the preprocessor can't distinguish between the standard Brainfuck symbols, this implementation uses the following alternative instruction names:

| Original | Instruction | Description                                                       |
| ---      | ---         | ---                                                               |
| >        | R           | Move the tape head to the right                                   |
| <        | L           | Move the tape head to the left                                    |
| +        | I           | Increment the tape head                                           |
| -        | D           | Decrement the tape head                                           |
| .        | A           | Output the tape head as ASCII                                     |
|          | O           | Output the tape head as a hexadecimal number                      |
| ,        | G           | Read an input character and set the tape head to it               |
| [        | B           | Jump past the matching ] if the cell at the pointer is 0          |
| ]        | E           | Jump back to the matching [ if the cell at the pointer is nonzero |


The instructions can be executed as follows:

```c
#include "bf.c"
BF((c,a),G,R,G,L,B,R,B,D,R,I,R,I,L,L,E,R,R,B,D,L,L,I,R,R,E,L,L,L,D,E,R,R,O)
```

this program multiplies the first two inputs and outputs the result (in hex), so here that would be `0xc*0xa=0x78` so it outputs `(78)`.

Check out [examples.c](examples.c) for more examples.

## Compilers/preprocessors

The fastest preprocessor I know of is the one in [tcc](https://repo.or.cz/w/tinycc.git), so I recommend preprocessing the programs with `tcc -E -P`.
If you want to get more fine grain information of execution times, then you might want to patch tinycc with [tinycc.diff](tinycc.diff).
This adds the `__TIMER__` macro, which expands to the executed time and resets the timer, so the second `__TIMER__` in `__TIMER__ FOO __TIMER__` expands to the time it took to expand `FOO`.

For gcc make sure to use the `-ftrack-macro-expansion=0` options and for clang use the `-fmacro-backtrace-limit=1` options.
If you can't use tcc I recommend using gcc instead of clang, because it's faster, and it gives you incremental output.



# Benchmarks of similar projects

The programs tested are also present in [examples.c](examples.c).


| Program                                                          | bfcpp  | [bfi](http://www.kotha.net/bfi//) | [CPP_COMPLETE](https://github.com/orangeduck/CPP_COMPLETE) | [preprocessor_brainfuck](https://github.com/Ferdi265/preprocessor_brainfuck) |
| ---                                                              | ---    | ---                               | ---                                                        | ---                                                                          |
| [Hello World](https://esolangs.org/wiki/Brainfuck)               | 0.038s | 0.048s                            | 38s                                                        | ~20 minutes                                                                  |
| [insertion sort](http://brainfuck.org/isort.b) 1                 | 0.059s | 0.11s                             | ---                                                        | ---                                                                          |
| insertion sort 2                                                 | 0.11s  | 0.22s                             | ---                                                        | ---                                                                          |
| insertion sort 3                                                 | 0.85s  | 1.7s                              | ---                                                        | ---                                                                          |
| insertion sort 4                                                 | 2.5s   | 5.1s                              | ---                                                        | ---                                                                          |
| [sierpinski triangle](http://brainfuck.org/sierpinski.b)         | 5.9s   | 6.6s                              | ---                                                        | ---                                                                          |
| [square numbers from 0 to 10000](http://brainfuck.org/squares.b) | 13.28s | 11.45s                            | ---                                                        | ---                                                                          |
| [quine](http://brainfuck.org/392quine.b)                         | 30.9s  | 283.3s                            | ---                                                        | ---                                                                          |



# Credit
Thanks to [notfoundry](https://github.com/notfoundry) and Bacon Headcrab for helping me understand preprocessor meta programming.
Also, a thanks to [bfi](http://www.kotha.net/bfi//), for the idea of the addition lookup table and a big motivation to further optimize my implementation.


## Licensing
For all files without an integrated license [LICENSE](LICENSE) applies.


