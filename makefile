OBJS     = main.o particles.o
SOURCE   = main.cpp particles.cpp
HEADER   = particles.h
CC       = g++
FLAGS    = -Wall -c

# -g for  debugging  mode ; -c for  objects  file  creation

all: physics

physics: main.o particles.o
	$(CC) -o physics main.o particles.o

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

particles.o: particles.cpp
	$(CC) $(FLAGS) particles.cpp

# clean  house
clean:
	rm -f $(OBJS) physics