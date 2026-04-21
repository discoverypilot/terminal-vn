#include <iostream>
#include <string>

#ifndef ENGINE_H
#define ENGINE_H

struct Screen {
  static const int width = 96;
  static const int height = (width/2/4*3);
  static const int textbox_height = 7;
  static const int textbox_padding = 1;
  static const int border_width = 1;

  static const int inner_textbox_height = textbox_height - ((textbox_padding + border_width) * 2);
  static const int inner_textbox_width = width - ((textbox_padding + border_width) * 2);
  static const int textbox_string_max_length = inner_textbox_width * inner_textbox_height;

  static const int inner_width = (width - 2);
  static const int inner_height = (height - textbox_height - 2);
  static const int fullscreen_height = (height - 2);
};

class Canvas {
private:
  std::string canvas[Screen::width][Screen::height];
  void assignBorders();
  void draw();
  void clear() { std::cout << "\033[H\033[2J"; };
public:
  Canvas();
  void drawText(std::string text);
};

#endif
