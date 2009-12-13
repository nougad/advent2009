
#ifndef DRAW_H
#define DRAW_H

/* Draw a single pixel on the surface with the given color. This is the basic
 * function to paint on the screen. We will be use this function for all paint
 * stuff.
 */
void drawPixel(int x, int y, int color);

/* Some basic shapes
 */
void drawLine(int x1, int y1, int x2, int y2, int color);
void drawRect(int x1, int y1, int x2, int y2, int color, bool filled);
void drawCircle(int x, int y, int radius, int color, bool filled);


int* generateTerrain(float peakheight, float flatness);
 
/*
 * This function will be called for every frame. Here you can actual draw things
 * on the screen.
 */
void drawScreen();

#endif

