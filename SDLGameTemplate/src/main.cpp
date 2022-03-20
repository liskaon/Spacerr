#include "engine.h"
#include "sprite.h"
#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "shot.h"

// Forward function declarations
void Update(float dt);
void RenderFrame(float dt);

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 576

// Street texture
Sprite street;
Sprite kocka;

const int hracSirka = 256;
const int hracVyska = 256;


//=============================================================================
int main(int argc, char* argv[])
{
	if (!InitSDL())
	{
		return 1;
	}

	if (!CreateWindow("The Game", WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		return 1;
	}
	
	street = LoadSprite("assets/cyberpunk-street.png");
	kocka = LoadSprite("assets/kocka.png");
	// Push functions to the game loop
	StartLoop(Update, RenderFrame);


	FreeSprite(street);
	FreeSprite(kocka);
	CleanUp();
	return 0;
}

//=============================================================================
SDL_Rect hrac = { 30, 0, hracSirka, hracVyska };
Shot* shot;
int speed = 100;

void Update(float dt)
{
	if (IsKeyDown(SDL_SCANCODE_LEFT))
		hrac.x -= (int)(speed * dt + 0.5f);
	else if (IsKeyDown(SDL_SCANCODE_RIGHT))
		hrac.x += (int)(speed * dt + 0.5f);

	if (IsKeyDown(SDL_SCANCODE_UP))
		hrac.y -= (int)(speed * dt + 0.5f);
	else if (IsKeyDown(SDL_SCANCODE_DOWN))
		hrac.y += (int)(speed * dt + 0.5f);


	if (hrac.x + hracVyska > WINDOW_WIDTH)
	{
		hrac.x = WINDOW_WIDTH - hrac.w;
	}
	else if (hrac.x - hracSirka < 0)
	{
		hrac.x = 0 + hracSirka;
	}

	if (hrac.y - hracVyska < 0)
	{
		hrac.y = 0;
	}
	else if (hrac.y + hracVyska > WINDOW_HEIGHT)
	{
		hrac.y = WINDOW_HEIGHT - hracVyska;
	}


	// Change subsystem of project from Windows to Console
	// in order to see the stderr output
	if (IsKeyDown(SDL_SCANCODE_ESCAPE))
	{
		ExitGame();
	}
	if (IsKeyDown(SDL_SCANCODE_SPACE))
	{
		shot = new Shot(gRenderer, hrac.x, hrac.y);
	}

}

void RenderFrame(float interpolation)
{
	// Clear screen
	SDL_SetRenderDrawColor(gRenderer, 65, 105, 225, 255);
	SDL_RenderClear(gRenderer);

	// Draw sprite (scaled by factor of 3)
	int pixelAmp = 3;
	
	SDL_Rect backgroundRect = {
		0,
		0,
		street.sourceRect.w * pixelAmp,
		street.sourceRect.h * pixelAmp
	};
	SDL_RenderCopy(gRenderer, street.texture, NULL, &backgroundRect);
	SDL_RenderCopy(gRenderer, kocka.texture, NULL, &hrac);
}
