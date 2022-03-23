<h1 align="center"> GOL   <img src="https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white"/></p>

<h2 align="center"> Manual install: </h2>
```console
$ git clone https://github.com/FlynnOwen/GOL-C.git
$ cd GOL-C
$ make
$ make install
```

<img align="left" width="410" height="410" src="images/GOLc.gif"/>

## Usage:

```console
$ GOL {optional arguements}
```

### Possible Optional Arguements
To pass an optional arguement when running GOL-C, simply add the arguement when running the above.

```console
-e {Number of evolutions e.g 100} (Number of steps to evolve for (default 100))
-t {Time between evolutions e.g 1} (Number of seconds between each evolution (default 0))
-s {Random seed value e.g 100} (The random seed to use to generate the initial cells (default 1))
-c {ASCII character e.g B} (The ASCII character used to represent a living cell (default O))
-g (whether to set the initial state as a glider gun)
```

## Additional Notes
Conway's Game of Life is a well known problem in the area of cellular automata.

It was shown to be Turing Complete (meaning it can simulate any Turing Machine) when Paul Rendenll built a Turing Machine using a pre-defined board state in [2001](https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.386.7806&rep=rep1&type=pdf]).

By regarding Gliders as 'bits' and a collection of patterns (glider guns, glider eaters and more), it's possible to emulate logic gates and memory latches. Try running the application in this repository with the *-g* option to see a glider gun in action!
