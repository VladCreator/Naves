#include "Game.h"
#include "Sprite.h"
#include "Frame.h"
#include <SDL.h>
#include <conio.h> 

#define WIDTH 420
#define HEIGHT 360
#define BPP 24

SDL_Surface *image, *screen;
SDL_Rect dest;
Uint8 *keys;
int background;
int HNave,WNave;
int H = 0;
int W = 0;

CFrame Upnave;
CSprite Nave;
bool salirJuego;
struct nave{
	int x,y;
} minave;
SDL_Event event;

Game::Game(void){
	atexit(SDL_Quit);
	Estado = ESTADO_INICIALIZACION;
	Sub_Estado = PINTANDO;
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
	//Estado es del enum 
	while(Estado != ESTADO_FINALIZACION )
	{
		//CORREGIDO
		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) {
				Estado = ESTADO_FINALIZACION;//ACT5: Primero debes de FINALIZAR y luego SALIR
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
			switch (Sub_Estado)
			{
			case  PINTANDO:
				Pintado();
				Sub_Estado = ACTUALIZANDO;
				break;
			case ACTUALIZANDO:
				Actualizado();
				Estado = ESTADO_JUEGO;
				Sub_Estado = PINTANDO;
				break;
			case SALIR:
				break;
			}
			break;

		case ESTADO_TERMINADO: //SALIR
			salirJuego = true;
			break;
		};

		/*
		switch (Estado)
		{
		case ESTADO_INICIALIZACION:
		Inicializacion();
		Estado = ESTADO_JUEGO;//Correcto ya que cargas todo, aqui envias al estado JUEGO
		break;
		case ESTADO_JUEGO:
		Juego();
		//ACT5: Un subestado depende de la vida de un estado, por lo que no necesita su propio While.
		switch (Sub_Estado)
		{
		case  PINTANDO:
		Pintado();
		Sub_Estado = ACTUALIZANDO;//ACT5: No es necesario
		break;
		case ACTUALIZANDO:
		Actualizado();
		Estado = ESTADO_JUEGO;
		break;
		}
		break;

		case ESTADO_FINALIZACION:
		Finalizacion();
		break;
		}
		Sub_Estado+1;
		//ACT5: Aqui puedes agregar que el estado Sub_Estado++, cambie al siguiente. 
		*/
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
	//Cambiar Nombre de la Ventana
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

	//ACT5: Puedes ir descomentando este codigo haber si funciona el teclado.
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
