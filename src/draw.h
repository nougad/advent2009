
#ifndef DRAW_H
#define DRAW_H

/*
 * Draw a single pixel on the surface with the given color. This is the basic
 * function to paint on the screen. We will be use this function for all paint
 * stuff.
 */
void drawPixel(int x, int y, int color);

/*
 * This function will be called for every frame. Here you can actual draw things
 * on the screen.
 */
void drawScreen();

#endif

