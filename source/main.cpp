#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "Game.h"

//SDL_Event event;
int done = 0;//ACT5: Esta variable no le asignas valor nunca

int main(int args,char* argv[])
{
	Game *juego = new Game();
	while(!done)//ACT5: Como nunca cambia el valor, nunca se saldra.
	{
		/*if(SDL_PollEvent(&event)) //ACT4: El SDL_PollEvent No debe de ir aqui, probablemente tu Teclado no te funcione, debe de ir en game. Ya que adentro tiene un segundo WHILE
		{
		if(event.type == SDL_QUIT) {done = 1;}
		}*/
		juego ->MotorEstados();

	}
	return 0;
}