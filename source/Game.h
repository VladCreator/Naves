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


	ESTADO Estado;//Bien
	
	void MotorEstados();
	void Inicializacion();
	void Juego();
	void Terminado();
	void Finalizacion();
	void Pintado();
	void Actualizado();

};

