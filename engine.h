#include <iostream>
#include <string>

#ifndef ENGINE_H
#define ENGINE_H

struct Screen {
  static const int width = 96;
  static const int height = (width/2/4*3);
  static const int textbox_height = 7;
  static const int inner_width = (width - 2);
  static const int inner_height = (height - textbox_height - 2);
  static const int fullscreen_height = (height - 2);
};

class Canvas {
private:
  std::string canvas[Screen::width][Screen::height];
  void assignBorders();
public:
  Canvas();
  void clear() { std::cout << "\033[H\033[2J"; };
  void draw();
};

#endif
