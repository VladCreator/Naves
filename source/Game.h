#include <SDL.h>
#pragma once
class Game
{

	 enum ESTADO { 
		 ESTADO_INICIALIZACION,
		 ESTADO_JUEGO,
		 ESTADO_FINALIZACION, 
		 ESTADO_TERMINADO};


	 enum SUBESTADO_JUEGO {
		 ACTUALIZANDO,
		 PINTANDO,
		SALIR};

public:
	Game(void);
	~Game(void);


	ESTADO Estado;//Bien
	SUBESTADO_JUEGO Sub_Estado;

	void MotorEstados();
	 void Inicializacion();
	 void Juego();
	 void Terminado();
	 void Finalizacion();
	 void Pintado();
	 void Actualizado();
	 
};

