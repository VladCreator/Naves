#pragma once
#include <SDL/SDL.h>
#include "Frame.h"

class CSprite
{
	 private:

        int posx, posy;
        int state;
        int nframes;
        int cont;
public:
		CFrame *sprite;
        CSprite(int nf);
        CSprite();
        void finalize();
        void addframe(CFrame frame);
        void selframe(int nf);
        int frames() {return cont;}
        void setx(int x) {posx=x;}
        void sety(int y) {posy=y;}
        void addx(int c) {posx+=c;}
        void addy(int c) {posy+=c;}
        int getx() {return posx;}
        int gety() {return posy;}
        int getw() {return sprite[state].img->w;}
        int geth() {return sprite[state].img->h;}
        void draw(SDL_Surface *superficie);
        int colision(CSprite sp);
		
//	~CSprite(void);
};
