#include <iostream>

#include "Game.h"
/*------------------------------------------------------------

Temat projektu:Podróbka Space Invaders

Wersja ostateczna


------------------------------------------------------------*/





/*------------------------------------------------------------

Program glowny

------------------------------------------------------------*/
int main() {
	Game game;
	srand(time(NULL));
	
	//Game loop
	while (game.otwarta()) 
	{

		//Update
		game.update();	//Wyczyść starą ramkę

		//Render
		game.render();	//Podaj narysowane do ramki
	}

	return 0;
}