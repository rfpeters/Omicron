PROGS := game

all: $(PROGS)


game: Room.o Game.o
	g++ -g Room.o Game.o -o game

Room.o: Room.cpp Room.hpp
	g++ -c Room.cpp

Game.o: Game.cpp
	g++ -c Game.cpp


clean:
	rm -f $(PROGS) *.o *~
