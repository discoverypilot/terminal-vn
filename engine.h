#include <iostream>
#include <string>

#ifndef ENGINE_H
#define ENGINE_H

#define SCREEN_WIDTH 96
#define SCREEN_HEIGHT (SCREEN_WIDTH/2/4*3)
#define TEXTBOX_HEIGHT 7
#define INNER_WIDTH (SCREEN_WIDTH-2)
#define INNER_HEIGHT (SCREEN_HEIGHT - TEXTBOX_HEIGHT - 2)
#define FULLSCREEN_HEIGHT (SCREEN_HEIGHT - 2)

class Canvas {
private:
  std::string canvas[SCREEN_WIDTH][SCREEN_HEIGHT];
  void assignBorders();
public:
  Canvas();
  void clear() { std::cout << "\033[H\033[2J"; };
  void draw();
};

#endif
