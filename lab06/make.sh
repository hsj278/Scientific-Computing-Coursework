#!/bin/sh

# File: make.sh used to build phys 2660 library and a test program

# make object file for our library
g++ -O -Wall -c hist.cpp
g++ -O -Wall -c random.cpp

# create the library
ar -csr libp2660.a hist.o random.o

# clean up, we no longer need the object files
rm -f *.o

# build the test program
# -L. defines a new directory to look for library files
#     in this case "." or the current directory
#     normally the compiler looks in /usr/lib, etc...
#     to find the libraries it needs
# -lp2660 means we must link w/ the library called libp2660.a
#     to get the code for our custom functions
#      Note the syntax. The "lib" prefix is assumed to be part 
#            of the library's name

g++ -O -Wall test_hist.cpp -o test_hist -L. -lp2660


