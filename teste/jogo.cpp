#include <SDL/SDL.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]) 
{
    // Initialize SDL library
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }
    
    int width = 640;
    int height = 480;
    int bpp = 32;
    Uint32 flags = SDL_DOUBLEBUF | SDL_HWSURFACE;

    SDL_Surface* screen = SDL_SetVideoMode(width, height, bpp, flags);

    if (screen == NULL) 
    {
        printf("Error creating window: %s\n", SDL_GetError());
        return 1;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) 
    {
        printf("Error initializing SDL_image: %s\n", IMG_GetError());
        return 1;
    }

    SDL_WM_SetCaption("Window", NULL);

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_Flip(screen);

    SDL_Surface* sprites[9];
    string filename = "";

    // sprites[0] = IMG_Load("Idle00.png");
    // sprites[1] = IMG_Load("Idle01.png");
    sprites[0] = IMG_Load("attack02.png");
    sprites[1] = IMG_Load("attack03.png");
    sprites[2] = IMG_Load("attack04.png");
    sprites[3] = IMG_Load("attack05.png");
    sprites[4] = IMG_Load("attack06.png");
    sprites[5] = IMG_Load("attack07.png"); 
    sprites[6] = IMG_Load("attack08.png");
    sprites[7] = IMG_Load("attack09.png");
    
    Uint32 startTime = SDL_GetTicks();

    bool running = true;
    SDL_Event event;
    while (running) 
    {
        while (SDL_PollEvent(&event)) 
        {
            printf("%d", event.type);
            switch (event.type) 
            {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }

        SDL_BlitSurface(sprites[0], NULL, screen, NULL);
        for (int i = 0 ; i < 7; i++){
            SDL_BlitSurface(sprites[i], NULL, screen, NULL);
            SDL_Flip(screen);
            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
            usleep(70*1000);
        }
    }

    // Quit SDL library
    SDL_Quit();

    return 0;
}
