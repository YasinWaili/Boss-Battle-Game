dprog: main.o Game.o Character.o Player.o Boss.o HealthBar.o Projectile.o
	g++ -o prog main.o Game.o Character.o Player.o Boss.o HealthBar.o Projectile.o -lsfml-graphics -lsfml-window -lsfml-system

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

HealthBar.o: HealthBar.cpp HealthBar.h
	g++ -c HealthBar.cpp

Projectile.o: Projectile.cpp Projectile.h
	g++ -c Projectile.cpp

# List.o: List.h
# 	g++ -c List.cpp

clean:
	rm -f *.o prog
