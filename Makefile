.PHONY: clean
 
main.exe : main.o InputManager.o AssetManager.o StateMachine.o Asteroids.o SplashState.o MainMenuState.o Set_of_gas.o Flash.o Land.o HUD.o GameState.o GameOverState.o Falling_Asteroids.o 
	C:\TDM-GCC-32\bin\g++.exe -o main main.o Game.o AssetManager.o Asteroids.o Bird.o Collision.o StateMachine.o -o main.exe -LC:\SFML\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system
	main.exe

main.o: main.cpp  Game.o 
	C:\TDM-GCC-32\bin\g++.exe -c main.cpp -IC:\SFML\SFML-2.5.1\include -o main.o

Game.o: Game.cpp Game.hpp AssetManager.o InputManager.o StateMachine.o
	C:\TDM-GCC-32\bin\g++.exe -c Game.cpp -IC:\SFML\SFML-2.5.1\include -o Game.o

InputManager.o: InputManager.cpp InputManager.hpp
	C:\TDM-GCC-32\bin\g++.exe -c Explosion.cpp -IC:\SFML\SFML-2.5.1\include -o InputManager.o

AssetManager.o: AssetManager.cpp AssetManager.hpp
	C:\TDM-GCC-32\bin\g++.exe -c AssetManager.cpp -IC:\SFML\SFML-2.5.1\include -o AssetManager.o

StateMachine.o: StateMachine.cpp StateMachine.hpp
	C:\TDM-GCC-32\bin\g++.exe -c StateMachine.cpp -IC:\SFML\SFML-2.5.1\include -o StateMachine.o

Asteroids.o: Asteroids.cpp Asteroids.hpp Game.o
	C:\TDM-GCC-32\bin\g++.exe -c Asteroids.cpp -IC:\SFML\SFML-2.5.1\include -o Asteroids.o

Bird.o: Bird.cpp Bird.hpp Game.o land.o
	C:\TDM-GCC-32\bin\g++.exe -c Bird.cpp -IC:\SFML\SFML-2.5.1\include -o Bird.o

Collision.o: Collision.cpp Collision.hpp 
	C:\TDM-GCC-32\bin\g++.exe -c Collision.cpp -IC:\SFML\SFML-2.5.1\include -o Collision.o

# Explosion.o: Explosion.cpp Explosion.hpp
# 	C:\TDM-GCC-32\bin\g++.exe -c Explosion.cpp -IC:\SFML\SFML-2.5.1\include -o Explosion.o

Falling_Asteroids.o: Falling_Asteroids.cpp Falling_Asteroids.hpp Asteroids.o
	C:\TDM-GCC-32\bin\g++.exe -c Falling_Asteroids.cpp -IC:\SFML\SFML-2.5.1\include -o Falling_Asteroids.o

GameOverState.o: GameOverState.cpp GameOverstate.hpp Game.o
	C:\TDM-GCC-32\bin\g++.exe -c GameOverState.cpp -IC:\SFML\SFML-2.5.1\include -o GameOverState.o

GameState.o: GameState.cpp GameState.hpp Land.o Bird.o Collision.o Flash.o HUD.o Falling_Asteroids.o Set_of_gas.o
	C:\TDM-GCC-32\bin\g++.exe -c GameState.cpp -IC:\SFML\SFML-2.5.1\include -o GameState.o

HUD.o: HUD.cpp HUD.hpp
	C:\TDM-GCC-32\bin\g++.exe -c HUD.cpp -IC:\SFML\SFML-2.5.1\include -o HUD.o

Land.o: Land.cpp Land.hpp Game.o 
	C:\TDM-GCC-32\bin\g++.exe -c Land.cpp -IC:\SFML\SFML-2.5.1\include -o Land.o

Flash.o: Flash.cpp Flash.hpp Game.o  
	C:\TDM-GCC-32\bin\g++.exe -c Flash.cpp -IC:\SFML\SFML-2.5.1\include -o Flash.o

Set_of_gas.o: Set_of_gas.cpp Set_of_gas.hpp Game.o Land.o
	C:\TDM-GCC-32\bin\g++.exe -c Set_of_gas.cpp -IC:\SFML\SFML-2.5.1\include -o Set_of_gas.o
MainMenuState.o: MainMenuState.cpp MainMenuState.hpp Game.o 
	C:\TDM-GCC-32\bin\g++.exe -c MainMenuState.cpp -IC:\SFML\SFML-2.5.1\include -o MainMenuState.o

SplashState.o: SplashState.cpp SplashState.hpp
	C:\TDM-GCC-32\bin\g++.exe -c SplashState.cpp -IC:\SFML\SFML-2.5.1\include -o SplashState.o
clean:
	del -f *.o
