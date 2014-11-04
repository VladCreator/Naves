#include "Game.h"
#include "Sprite.h"
#include "Frame.h"
#include <SDL.h>
#include <conio.h> 

/* Hecho
#define WIDTH 420 /// Crea un archivo llamado Config.h y mete esto
#define HEIGHT 360 // ---> Confing.h
#define BPP 24// ---> Confing.h
*/

/*Hecho
SDL_Surface *image, *screen;// ---> Game.h
SDL_Rect dest;// ---> Game.h
Uint8 *keys;// ---> Game.h
int background;// ---> Game.h
int HNave,WNave;// ---> Game.h
int H = 0;// ---> Game.h
int W = 0;// ---> Game.h
*/

/*Hecho
CFrame Upnave;// ---> Game.h
CSprite Nave;// ---> Game.h
bool salirJuego;// ---> Game.h
struct nave{// ---> Game.h
	int x,y;// ---> Game.h
} minave;// ---> Game.h
SDL_Event event;// ---> Game.h
*/

Game::Game(void){
	atexit(SDL_Quit);
	Estado = ESTADO_INICIALIZACION;
	minave.x = 50;
	minave.y = 10;
}

Game::~Game(void){
}
void Game::Finalizacion()
{
	atexit(SDL_Quit);
}
void Game::MotorEstados()
{
	
	while(Estado != ESTADO_FINALIZACION )
	{
		
		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) {
				Estado = ESTADO_FINALIZACION;
			}
		}
		switch(Estado)
		{
		case ESTADO_INICIALIZACION: //INICIALIZAR
			Inicializacion();
			Estado = ESTADO_JUEGO;
			break;

		case ESTADO_JUEGO: //JUGAR
			Juego();
			Pintado();
			break;

		case ESTADO_TERMINADO: //SALIR
			salirJuego = true;
			break;
		};
		Actualizado();
	}
}


void Game::Inicializacion()
{

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("No se ha podido iniciar SDL: %s\n", SDL_GetError());
		exit(1);
	}
	screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_HWSURFACE);
	
	SDL_WM_SetCaption("Mi primer juego", "s");
	if(screen == NULL)
	{
		printf("No se ha podido establecer el modo de vídeo: %s\n", SDL_GetError());
		exit(1);
	}

	Upnave.load("Nave.bmp");	

	H = Upnave.img ->h;
	W = Upnave.img ->w;
}

void Game::Juego()
{
	Nave.setx(minave.x);
	Nave.sety(minave.y);

	//SDL_Flip(screen);

	keys = SDL_GetKeyState(NULL);

	if(keys[SDLK_UP] && minave.y > 0){minave.y = minave.y - (1);}
	if(keys[SDLK_DOWN] && minave.y < HEIGHT - H){minave.y = minave.y + (1);}
	if(keys[SDLK_LEFT] && minave.x > 0) {minave.x = minave.x - (1);}
	if(keys[SDLK_RIGHT] && minave.x <  WIDTH - W) {minave.x = minave.x + (1);}
}
void Game::Pintado()
{
	Nave.addframe(Upnave);
	Nave.draw(screen);
}
void Game::Actualizado()
{
	SDL_Flip(screen);
}
