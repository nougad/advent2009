
#include <stdio.h>
#include <stdbool.h>
#include "SDL.h"
#include "config.h"
#include "draw.h"

int main(int argc, char **argv) {
  // Initialize SDL and open up a screen
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  // the main game loop
  while (gameRunning == true) {
    // Check for events
    if (SDL_PollEvent(&event)) {
      // Make it possible to close the game window
      if (event.type == SDL_QUIT) gameRunning = false;
    }

    // Draw the stuff on the screen and "flip" th the next frame
    drawScreen();
    SDL_Flip(screen);
  }

  SDL_Quit();
  return 0;
}

