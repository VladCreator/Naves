#include <SDL.h>
#pragma once



class Game
{
	 enum ESTADO { ///ACT4: Es importante indicar de quien es el estado por ejemplo: ESTADO_JUEGO.
		 INICIALIZACION,
		 JUEGO,
		 FINALIZACION };//ACT4: A diferencia de lo que puedes creer FINALIZACION debe ser un estado accesible en el Loop, aqui vamos a matar todos los objetos creados.

	 enum GRAFICA { //ACT4: Tambien aqui, es importante indicar que es un estado SUBESTADO__JUEGO
		 PINTANDO,
		 ACTUALIZANDO };
public:
	Game(void);
	~Game(void);


	 ESTADO Estado;//Bien
	GRAFICA Grafica;//ACT4: MM.. esta nombre no me convence mucho.

	void MotorEstados();
	 void Inicializacion();
	 void Juego();
	 void Finalizacion();
	 void Pintado();
	 void Actualizado();
};

