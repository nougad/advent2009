
#include "SDL.h"
#include "draw.h"
#include "config.h"


void drawPixel(int x, int y, int color) {
  unsigned int *p = (unsigned int*)screen->pixels;
  int lineOffset = y * (screen->pitch/4);
  p[lineOffset+x] = color;
}

void drawScreen() {
  Uint32 black = SDL_MapRGB(screen->format, 0xff, 0xff, 0xff);
  drawPixel(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, black);
}

