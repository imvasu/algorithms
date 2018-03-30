# Algorithms

## Overview
This repository contains algorithms implemented in C/C++.


## Contents

* `problems` - C++ algorithms
* `solutions` - solutions to C++ algorithms
* `tests` - Unit Tests to test functionality of SDK

## Requirements

* GNU C++ Compiler (g++) version 4.2 or above for 32/64-bit architectures
* Any Linux x86 distribution based on glibc 2.20+
* If using macOS - LLVM version 8.0.0 or above
* cmake version 3.0 or above

Before building the solutions, check if cmake is installed. If not, you can get it using package manager

```sh
$ sudo apt-get install cmake
$ cmake -v
```
Also, ensure your system has all the tools (g++, make, libc, git etc) to build c++ code. If not, you can install them using

```sh
$ sudo apt-get install build-essential
$ sudo apt-get install git
```

## Dependencies

* cgreen - Tests are written using [cgreen](https://github.com/cgreen-devs/cgreen) unit testing framework to verify SDK
  functionality. cgreen repo will be downloaded, compiled and linked to tests as part of build step.

## Platforms

SDK has been built and tested on below platforms.
* Linux x86 32/64 bit architectures
* macOS 10.12 and above

SDK can be built on other platforms as long the compiler has support for ISO C++ standard C++98/C++03.

## Build Targets

Below are the targets that can be built using this repository.

* `algorithms`
* `tests` - Tests are built as executable linking cgreen library.


## <a id="Installation"></a>Installation

All the targets can be built from root directory using the below commands.

```sh
$ git clone https://github.com/imvasu/algorithms.git
$ cd algorithms
$ mkdir build
$ cd build
$ cmake ..
$ make
```

if `build` directory is created outside of the root directory, then pass the path of root directory to cmake command.

Only sdk and sample targets are built by default. To build tests, run

```sh
$ cmake .. -DBUILD_TESTS=1
$ make
```

You can also build individual targets using below commands

```sh
$ make algorithms
$ make tests
```

## How to Use

Best place to understand the usage of SDK is to run the tests. Please refer [README](tests) of tests on how to run and verify algorithms


