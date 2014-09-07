programming-abstractions-in-cpp
===============================

Exercises from the book

As I follow along with Stanford's CS106B class I'm doing all the exercises in the reader:

Programming Abstractions in C++ by Eric S. Roberts.

The Stanford CPP Libraries are 32 bit and can present some problems.  Xcode or Qt Creator can get things running but it’s not perfect.  I’m searching for a simple command line solution.  So far using clang++/g++ with -l -L -I tags seems to work on a 32 bit machine but some of the library files won’t compile on my 64bit iMac unless I use Xcode which can magically force build 32 bit.  Anything that wants to use platform.h or main.h has bigtime problems.

I was able to adjust the Linux makefile to build just the ones that would work on my machine though - that helped.

example build:

g++ example.cpp -lStanfordCPPLib -L/Path/to/StanfordCPPLib/ -I/Path/to/StanfordCPPLib/ -o example

Also the graphic libraries won't work on my iMac so most of these assignments are skipped.