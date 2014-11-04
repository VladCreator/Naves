#pragma once
#include <SDL.h>
#include "Frame.h"

class CSprite
{
private:

	int posx, posy;
	int state;
	int nframes;
	int cont;
public:

	SDL_Surface *sprite;
	//CFrame *sprite;///ACT6: Envez de CFrame, vas a llamarlo simplemente image del tipo SDL_Surface*.
	CSprite(int nf);
	CSprite();
	void finalize();
	//void addframe(CFrame frame);//ACT6: Ya no se usa.
	void selframe(int nf);
	int frames() {return cont;}
	void setx(int x) {posx=x;}
	void sety(int y) {posy=y;}
	void addx(int c) {posx+=c;}
	void addy(int c) {posy+=c;}
	int getx() {return posx;}
	int gety() {return posy;}
	int getw() {return sprite->w;}
	int geth() {return sprite->h;}
	void draw(SDL_Surface *superficie);
	int colision(SDL_Surface *imagen);//ACT6, vas a usar sprite/imagenes para comparar coliciones.

	//	~CSprite(void);
};
