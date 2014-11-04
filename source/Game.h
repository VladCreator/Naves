#include <SDL.h>
#pragma once
class Game
{
	

	enum ESTADO { 
		ESTADO_INICIALIZACION,
		ESTADO_JUEGO,
		ESTADO_FINALIZACION, 
		ESTADO_TERMINADO
	};

public:
	Game(void);
	~Game(void);
	SDL_Surface *image, *screen;// ---> Game.h
    SDL_Rect dest;// ---> Game.h
	Uint8 *keys;// ---> Game.h
	int background;// ---> Game.h
	int HNave,WNave;// ---> Game.h
	int H ;// ---> Game.h
	int W ;// ---> Game.h

	//CFrame Upnave;// ---> Game.h

	CSprite Nave;// ---> Game.h
	bool salirJuego;// ---> Game.h
	SDL_Event event;// ---> Game.h
	struct nave{// ---> Game.h
		int x,y;// ---> Game.h
	} minave;// ---> Game.h


	ESTADO Estado;//Bien
	
	void MotorEstados();
	void Inicializacion();
	void Juego();
	void Terminado();
	void Finalizacion();
	void Pintado();
	void Actualizado();

};

