# the compiler:
CC = gcc

# compiler flags:
#	-g	adds debugging info to the executable file
#	-Wall	turns on most, but not all, compiler warnings
CFLAGS = -g -Wall

# linker flags
#	-lncurses	loads ncurses library
LDFLAGS = -lncurses

# the build target executable
TARGET = pow11

default: $(TARGET)

$(TARGET): grid.o term.o pow11.o main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c grid.o term.o pow11.o $(LDFLAGS)

# Object file grid.o contains grid data structure and methods
# for operating on them
grid.o: grid.h grid.c
	$(CC) $(CFLAGS) -c grid.c

term.o: grid.o term.h term.c
	$(CC) $(CFLAGS) -c term.c

pow11.o: grid.o pow11.h pow11.c
	$(CC) $(CFLAGS) -c pow11.c

# Remove any compiled file
clean:
	$(RM) $(TARGET) *.o
	