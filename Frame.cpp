#include "Frame.h"
#include "Sprite.h"
#include <SDL/SDL.h>

void CFrame::load(char *path)
{

    img = SDL_LoadBMP(path);
    SDL_SetColorKey(img, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(img -> format, 255, 0, 0));
    img =SDL_DisplayFormat(img);
}

void CFrame::unload()
{

    SDL_FreeSurface(img);
}
