#include "Sprite.h"


CSprite::CSprite(int nc)
{

    sprite = new CFrame[nc];
    nframes = nc;
    cont = 0;
}

CSprite::CSprite()
{

    int nc = 1;
    sprite = new CFrame[nc];
    nframes = nc;
    cont = 0;
}
void CSprite::finalize()
{

    int i;
    for(i = 0; i <= nframes-1; i++)
	{
        sprite[i].unload();
	}
}

void CSprite::addframe(CFrame frame)
{

    if(cont < nframes)
	{
        sprite[cont] = frame;
        cont++;
    }
}

void CSprite::selframe(int nc)
{

    if(nc <= cont)
	{
        state = nc;
	}
}
void CSprite::draw(SDL_Surface *superficie){

    SDL_Rect dest;

    dest.x = posx;
    dest.y = posy;

    SDL_BlitSurface(sprite[state].img, NULL, superficie, &dest);
}

int CSprite::colision(CSprite sp)
{

    int w1, h1, w2, h2, x1, x2, y1, y2;

    w1 = getw();
    h1 = geth();
    x1 = getx();
    y1 = gety();

    w2 = sp.getw();
    h2 = sp.geth();
    x2 = sp.getx();
    y2 = sp.gety();

    if(((x1 + w1) > x2) && ((y1 + h1) > y2) && ((x2 + w2) > x1) && ((y2 + h2) > y1))
	{
        return TRUE;
    } else 
		{
			return FALSE;
	 }
}	