PROGS := game

all: $(PROGS)


game: Player.o Item.o Room.o Game.o
	g++ -g Player.o Item.o Room.o Game.o -o game

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

Room.o: Room.cpp Room.hpp
	g++ -c Room.cpp

Game.o: Game.cpp
	g++ -c Game.cpp


clean:
	rm -f $(PROGS) *.o *~
