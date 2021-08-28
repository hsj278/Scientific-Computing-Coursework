# for the brave...
# source files
SRC = hist.cpp random.cpp
OBJ = $(SRC:.cpp=.o)
LIB = p2660
BINSRC = test_hist.cpp
BIN = test_hist

# include directories
INCLUDES = -I.

# C++ compiler flags (-g -O2 -Wall)
CCFLAGS = -O -Wall

# compiler
CC = g++

# library paths
LDIRS = -L.

.SUFFIXES: .cpp

default: dep $(LIB) $(BIN)

$(BIN): $(LIB)
	$(CC) $(CCFLAGS) $(INCLUDES) -o $(BIN) $(BINSRC) $(LDIRS) -l $(LIB)

.cpp.o:
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

$(LIB): $(OBJ)
	ar rcs lib$(LIB).a $(OBJ)

depend: dep

# makedepend will automatically find dependencies 
# files will only be rebuilt if they or a file they depend on is
# changed
# makedep automatically writes the lower portion of this file
dep:
	makedepend -- $(CFLAGS) -- $(INCLUDES) $(SRC) $(BINSRC)

clean:
	rm -f $(OBJ) $(OUT) Makefile.bak 

# DO NOT DELETE

hist.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
hist.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
hist.o: /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h
hist.o: /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h
hist.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
hist.o: /usr/include/sys/lock.h /usr/include/sys/types.h
hist.o: /usr/include/machine/_types.h /usr/include/limits.h
hist.o: /usr/include/features.h /usr/include/sys/cdefs.h
hist.o: /usr/include/sys/features.h /usr/include/machine/types.h
hist.o: /usr/include/sys/stdio.h /usr/include/stdlib.h
hist.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
hist.o: /usr/include/string.h /usr/include/sys/string.h /usr/include/math.h
hist.o: hist.hpp
random.o: /usr/include/stdlib.h /usr/include/_ansi.h /usr/include/newlib.h
random.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
random.o: /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h
random.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
random.o: /usr/include/sys/lock.h /usr/include/machine/stdlib.h
random.o: /usr/include/alloca.h /usr/include/time.h
random.o: /usr/include/machine/time.h /usr/include/sys/types.h
random.o: /usr/include/machine/_types.h /usr/include/limits.h
random.o: /usr/include/features.h /usr/include/sys/cdefs.h
random.o: /usr/include/sys/features.h /usr/include/machine/types.h
random.o: /usr/include/math.h random.hpp
test_hist.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
test_hist.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
test_hist.o: /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h
test_hist.o: /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h
test_hist.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
test_hist.o: /usr/include/sys/lock.h /usr/include/sys/types.h
test_hist.o: /usr/include/machine/_types.h /usr/include/limits.h
test_hist.o: /usr/include/features.h /usr/include/sys/cdefs.h
test_hist.o: /usr/include/sys/features.h /usr/include/machine/types.h
test_hist.o: /usr/include/sys/stdio.h random.hpp hist.hpp
