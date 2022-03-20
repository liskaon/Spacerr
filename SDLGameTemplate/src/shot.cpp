#include "shot.h"
#include "sprite.h"

Shot::Shot(SDL_Renderer* ren, const int parX, const int parY)
{
	renderer = ren;
	ObjTexture =  LoadSprite("assets/shot.png");
	x = parX;
	y = parY;
}

void Shot::Update()
{
	

	srcRect.h = 10;
	srcRect.w = 30;
	srcRect.x = x;
	srcRect.y = y;

	destRect.h = 10;
	destRect.w = 30;
	srcRect.x = x;
	srcRect.y = y;
}

void Shot::Render()
{
	SDL_RenderCopy(renderer, ObjTexture.texture, &srcRect, &destRect);
}