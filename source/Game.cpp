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
struct nave{
	int x,y;
} minave;
SDL_Event event;

Game::Game(void){
	Estado = INICIALIZACION;

	minave.x = 50;
	minave.y = 10;
}

Game::~Game(void){
}
void Game::Finalizacion()
{

}
void Game::MotorEstados(){
	//Estado es del enum 
	while(Estado !=SALIR_MOTOR)//ACT4: Debe de existir un estado para esto y no el de FINALIZACION
	{
		//CORREGIDO
		if(SDL_PollEvent(&event)) //ACT4: El SDL_PollEvent No debe de ir aqui, probablemente tu Teclado no te funcione, debe de ir en game. Ya que adentro tiene un segundo WHILE
		{
			if(event.type == SDL_QUIT) {
				Estado = SALIR_MOTOR;
			}
		}

		switch (Estado)
		{///ACT4:  Se recomienda que pongas en order tus estados, primero INICIALIZACION y Luego JUEGO
			case INICIALIZACION:
				Inicializacion();
				Estado = JUEGO;//Correcto ya que cargas todo, aqui envias al estado JUEGO
			break;
			case JUEGO:
				//CORREGIDO
				Juego();//ACT4: Este juego ya no debe de ir aqui, debe de ir en su respectivo estado.
				while(Sub_Estado != SALIR)
				{
					switch (Sub_Estado)
					{
						case  PINTANDO:
							Pintado();
							 Sub_Estado = ACTUALIZANDO;
							 break;
						case ACTUALIZANDO:
							Actualizado();
							Sub_Estado = SALIR;
							Estado = JUEGO;
							break;
					}
					Sub_Estado = PINTANDO;
				}
				break;

				case FINALIZACION:
						Finalizacion();
					break;
		}
	}

} 

void Game::Inicializacion()
{
	atexit(SDL_Quit);
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("No se ha podido iniciar SDL: %s\n", SDL_GetError());
		exit(1);
	}
	screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_HWSURFACE);
	//Cambiar Nombre de la Ventana
	SDL_WM_SetCaption("Space Wide", "s");
	if(screen == NULL)
	{
		printf("No se ha podido establecer el modo de vídeo: %s\n", SDL_GetError());
		exit(1);
	}
	Upnave.load("Nave.bmp");		
}

void Game::Juego()
{
		Nave.setx(minave.x);
		Nave.sety(minave.y);
		//Upnave.load("Nave.bmp");//ACT4: En el Juego ya no se debe de cargar cosas, para eso esta el estado de INICIALIZACION
		Nave.addframe(Upnave);
		Nave.draw(screen);
		SDL_Flip(screen);
		//Upnave.unload();
		/*int H = Nave.geth();
		int W = Nave.getw();*/

		/*keys = SDL_GetKeyState(NULL);
	
	if(keys[SDLK_UP] && minave.y > 0){minave.y = minave.y - (1);}
	if(keys[SDLK_DOWN] && minave.y < HEIGHT - H){minave.y = minave.y + (1);}
	if(keys[SDLK_LEFT] && minave.x > 0) {minave.x = minave.x - (1);}
	if(keys[SDLK_RIGHT] && minave.x <  WIDTH - W) {minave.x = minave.x + (1);}*/
}
void Game::Pintado()
{
		
}
void Game::Actualizado(){
	SDL_Flip(screen);
}
/*int getEstado()
{
	return Estado;
}
void SetEstado(int n)
{
	Estado = n;
}
int getFINALIZACION()
{
	return  FINALIZACION;
}*/