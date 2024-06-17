CC=g++
CFLAGS=-Wall -g


gameEngine: gameEngine.o Frame.o
	$(CC) $(CFLAGS) -o gameEngine gameEngine.o Frame.o -lncurses

gameEngine.o: gameEngine.cpp
	$(CC) $(CFLAGS) -c gameEngine.cpp
	
Frame.o: Frame.cpp Frame.h
	$(CC) $(CFLAGS) -c Frame.cpp
	
all: gameEngine ;

clean:
	rm -f gameEngine gameEngine.o