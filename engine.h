#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#ifndef ENGINE_H
#define ENGINE_H

struct Screen {
  static const int width = 96;
  static const int height = width/2/4*3; // 36
  static const int textbox_height = 7;
  static const int textbox_padding = 1;
  static const int border_width = 1;

  static const int inner_textbox_height = textbox_height - ((textbox_padding + border_width) * 2);
  static const int inner_textbox_width = width - ((textbox_padding + border_width) * 2);
  static const int textbox_string_max_length = inner_textbox_width * inner_textbox_height;

  static const int inner_width = width - border_width * 2;
  static const int inner_height = height - textbox_height - border_width * 2;
  static const int fullscreen_height = height - border_width * 2;

  static const int text_start_index_x = 0 + border_width + textbox_padding;
  static const int text_start_index_y = (height - 1 - textbox_height) + border_width; 
  static const int text_end_index_x = (width - 1) - (border_width + textbox_padding);
  static const int text_end_index_y = (height - 1) - border_width;
};

class Canvas {
private:
  std::string canvas[Screen::width][Screen::height];
  void assignBorders();
  void draw();
  void clear() { std::cout << "\033[H"; };
  void clearStartup() { std::cout << "\033[2J"; };
  void resetCursor() {};
public:
  Canvas();
  void drawText(std::string text);
};

#endif
