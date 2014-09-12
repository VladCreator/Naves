#include <SDL.h>
#pragma once



class Game
{
	 enum ESTADO_JUEGO { ///ACT4: Es importante indicar de quien es el estado por ejemplo: ESTADO_JUEGO.//Corregido
		 ///ACT5: Aqui tambien me equivoque, debe ser "Estado" ën vez de "ESTADO_JUEGO"
		 INICIALIZACION,
		 JUEGO,
		 FINALIZACION, 
		 SALIR_MOTOR};//ACT4: A diferencia de lo que puedes creer FINALIZACION debe ser un estado accesible en el Loop, aqui vamos a matar todos los objetos creados.
		 //ACT5: No es necesario que le pongas MOTOR, pues al estar diciendo SALIR y al estar en tu clase Game, es el estado del GAME
		 
	 enum SUBESTADO_JUEGO { //ACT4: Tambien aqui, es importante indicar que es un estado SUBESTADO__JUEGO //Corregido
		 PINTANDO,//Act5: Primero es Actualizar y luego Pintar.
		 ACTUALIZANDO,
		SALIR};//Act5: No se necesita salir.
public:
	Game(void);
	~Game(void);


	 ESTADO_JUEGO Estado;//Bien
	SUBESTADO_JUEGO Sub_Estado;//ACT4: MM.. esta nombre no me convence mucho. //Corregido a medias

	void MotorEstados();
	 void Inicializacion();
	 void Juego();
	 void Finalizacion();
	 void Pintado();
	 void Actualizado();
	 
	 void SetEstado(ESTADO_JUEGO n);
	 int getEstado();

	 int getFINALIZACION();
};

