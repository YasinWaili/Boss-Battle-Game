dprog: main.o Game.o Character.o Player.o Boss.o
	g++ -o prog main.o Game.o Character.o Player.o Boss.o -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

Boss.o: Boss.cpp Boss.h
	g++ -c Boss.cpp

Character.o: Character.cpp Character.h
	g++ -c Character.cpp

clean:
	rm -f *.o prog
