# CC and CFLAGS are varilables
CC = g++
CFLAGS = -c
AR = ar
ARFLAGS = rcv
# -c option ask g++ to compile the source files, but do not link.
# -g option is for debugging version
# -O2 option is for optimized version
DBGFLAGS = -g -D_DEBUG_ON_
OPTFLAGS = -O2

all	: bin/mps
	@echo -n ""

# optimized version
bin/mps	: planar_opt.o main_opt.o
			$(CC) $(OPTFLAGS) planar_opt.o main_opt.o -o bin/mps
main_opt.o 	   	: src/main.cpp
			$(CC) $(CFLAGS) $< -Ilib -o $@
planar_opt.o	: src/planar.cpp src/planar.h
			$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@

# DEBUG Version
dbg : bin/mps_dbg
	@echo -n ""

bin/mps_dbg	: planar_dbg.o main_dbg.o
			$(CC) $(DBGFLAGS) planar_dbg.o main_dbg.o -o bin/mps_dbg
main_dbg.o 	   	: src/main.cpp
			$(CC) $(CFLAGS) $< -Ilib -o $@
planar_dbg.o	: src/planar.cpp src/planar.h
			$(CC) $(CFLAGS) $(DBGFLAGS) $< -o $@


# clean all the .o and executable files
clean:
		rm -rf *.o lib/*.a lib/*.o bin/*
