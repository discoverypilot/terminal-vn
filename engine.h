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

struct Color {
  static const int black = 30;
  static const int red = 31;
  static const int green = 32;
  static const int yellow = 33;
  static const int blue = 34;
  static const int magenta = 35;
  static const int cyan = 36;
  static const int white = 37;
};

struct BackgroundColor {
  static const int black = 40;
  static const int red = 41;
  static const int green = 42;
  static const int yellow = 43;
  static const int blue = 44;
  static const int magenta = 45;
  static const int cyan = 46;
  static const int white = 47;
};

struct TextEffect {
  static const int reset = 0;
  static const int bold = 1;
  static const int underline = 4;
  static const int inverse = 7;
  static const int bold_off = 21;
  static const int underline_off = 24;
  static const int inverse_off = 27;
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
