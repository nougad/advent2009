
#include <stdbool.h>
#include "SDL.h"

// In this file we define all global variables for the whole project. All
// variables definied here can be accessed from all other source files.

// Global variables and definitions
extern SDL_Surface *screen; // Screen to paint on
extern SDL_Event event; // Event storage
extern bool gameRunning; // Set this variable to false to shutdown the game


// Constants

// Screen size
static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;

