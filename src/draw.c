
#include "SDL.h"
#include <math.h>
#include <stdbool.h>
#include "draw.h"
#include "config.h"


void drawPixel(int x, int y, int color) {
  unsigned int *p = (unsigned int*)screen->pixels;

  int lineOffset = y * (screen->pitch/4);
  p[lineOffset+x] = color;
}

int _sign(float a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}

float _random(float from, float to) {
  return ((to-from)*((float)rand()/RAND_MAX))+from;
}

void drawLine(int x1, int y1, int x2, int y2, int color) {
  float u, s, v, d1x, d1y, d2x, d2y, m, n;
  int x = x1, y = y1;

  u = x2-x1;
  v = y2-y1;

  d1x = d2x = _sign(u);
  d1y = _sign(v);
  d2y = 0;
  m = abs(u);
  n = abs(v);

  if (m <= n) {
    d2x = 0;
    d2y = _sign(v);
    m = abs(v);
    n = abs(u);
  }

  s = (int)(m/2);

  for (int i=0; i<round(m); i++) {
    drawPixel(x, y, color);
    s += n;
    if (s >= m) {
      s -= m;
      x += d1x;
      y += d1y;
    } else {
      x += d2x;
      y += d2y;
    }
  }
}

void drawRect(int x1, int y1, int x2, int y2, int color, bool filled) {
  int tmp;

  if (x1 > x2) { tmp = x1; x2 = x1; x1 = tmp; }
  if (y1 > y2) { tmp = y1; y2 = y1; y1 = tmp; }
  
  if (filled) {
    for (int i=y1; i<=y2; i++) drawLine(x1, i, x2, i, color);
  } else {
    drawLine(x1, y1, x2, y1, color);
    drawLine(x1, y1, x1, y2, color);
    drawLine(x2, y1, x2, y2, color);
    drawLine(x1, y2, x2, y2, color);
  }
}

// TODO: Write some code in here!
void drawCircle(int x, int y, int radius, int color, bool filled) {
}

int* generateTerrain(float peakheight, float flatness) {
  time_t start; srand(start);

  float offset = (float)SCREEN_HEIGHT/2;
  float r1 = _random(1.0, 5.0);
  float r2 = _random(1.0, 5.0);
  float r3 = _random(1.0, 5.0);
  int *yvals = (int*)malloc(SCREEN_WIDTH*sizeof(int));
  printf("r1=%f, r2=%f, r3=%f\n", r1, r2, r3);

  for (int x=0; x<SCREEN_WIDTH; x++) {
    float y;
    y  = peakheight/r1*sin((x/flatness*r1)+r1);
    y += peakheight/r2*sin((x/flatness*r2)+r2);
    y += peakheight/r3*sin((x/flatness*r3)+r3);
    y += offset;
    yvals[x] = (int)y;
  }

  return &(yvals[0]);
}

void drawScreen() {
  Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255);
  for (int x=0; x<SCREEN_WIDTH; x++) drawLine(x, terrain[x], x, SCREEN_HEIGHT, white);
}

