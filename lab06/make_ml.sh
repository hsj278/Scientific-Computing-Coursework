#!/bin/sh
g++ -O -Wall -c mcomplex.cpp
g++ -O -Wall -c mfuncs.cpp
ar -csr libmylib.a mcomplex.o mfuncs.o
