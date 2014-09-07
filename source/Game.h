#include <SDL.h>
#pragma once



class Game
{
	 enum ESTADO { INICIALIZACION,JUEGO,FINALIZACION };
	 enum GRAFICA { PINTANDO,ACTUALIZANDO };
public:
	Game(void);
	~Game(void);


	 ESTADO Estado;
	GRAFICA Grafica;

	void MotorEstados();
	 void Inicializacion();
	 void Juego();
	 void Finalizacion();
	 void Pintado();
	 void Actualizado();
};

