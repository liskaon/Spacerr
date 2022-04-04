#include "shot.h"
#include "sprite.h"

Shot::Shot(SDL_Renderer* ren, const int parX, const int parY) :
	srcRect({ 0 }),
	destRect({ 0 })
{
	renderer = ren;
	ObjTexture =  LoadSprite("assets/shot.png");
	x = parX;
	y = parY;
}

Shot::~Shot()
{
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