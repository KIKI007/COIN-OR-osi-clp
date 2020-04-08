# README

## Overview

OSI and CLP versions which can be compiled with cmake. 
This has been done to be used easily as an external library for Topolite and other LGG's projects.

* OSI (Open Solver Interface) provides an abstract base class to a generic linear programming (LP) solver, along with derived classes for specific solvers
* CLP (Coin-or linear programming) is an open-source linear programming solver written in C++. It provides a generic interface to solve Linear Programs.

## Content

Two solvers are accessible in this release:

* CLP
* the mosek wrapper.

## CLP documentation 

The full documentation is available here: [https://coin-or.github.io/](https://coin-or.github.io/)

## cmake setup 

### Compiling with cmake

Just follow the usual `cmake` workflow: 

```bash
$ cd COIN-OR-osi-clp
$ mkdir cmake-build
$ cd cmake-build
$ cmake --build .
```

### Installing with cmake

```bash
$ cd COIN-OR-osi-clp
$ mkdir cmake-build
$ cd cmake-build
$ cmake .. -DCMAKE_INSTALL_PREFIX=/opt/the/prefix
$ cmake --build .
$ cmake --build . --target install
```

### cmake doc

* [User interaction](https://cmake.org/cmake/help/latest/guide/user-interaction/index.html)
* [Writing CMakeLists](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

## Important changes - C++17 compatibility

In order to make the library C++17 compatible within our own projects, functions have been modified/discarded since c86b479eb39602ce838c0e1ff6d3e01a324d7563.

