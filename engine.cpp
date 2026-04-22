#include "engine.h"

void Canvas::assignBorders() {
  for (int x = 0; x < Screen::width; ++x) {
    canvas[x][0] = "═";
    canvas[x][Screen::height - 1] = "═";
    canvas[x][Screen::height - 1 - Screen::textbox_height] = "═";
  }

  for (int y = 0; y < Screen::height; ++y) {
    canvas[0][y] = "║";
    canvas[Screen::width-1][y] = "║";
  }

  canvas[0][0] = "╔";
  canvas[0][Screen::height-1] = "╚";
  canvas[Screen::width - 1][0] = "╗";
  canvas[Screen::width-1][Screen::height-1] = "╝";
  canvas[0][Screen::height - 1 - Screen::textbox_height] = "╠";
  canvas[Screen::width - 1][Screen::height - 1 - Screen::textbox_height] = "╣";
}

Canvas::Canvas() {
  clearStartup();
  for (int y = 0; y < Screen::height; ++y) {
    for (int x = 0; x < Screen::width; ++x) {
      canvas[x][y] = " ";
    }
  }
  assignBorders();
  draw();
}

void Canvas::draw() {
  clear();
  for (int y = 0; y < Screen::height; ++y) {
    for (int x = 0; x < Screen::width; ++x) {
      std::cout << canvas[x][y];
    }
    std::cout << "\n";
  }
  std::cout << std::flush;
}

void Canvas::drawText(std::string text) {
  int i = 0;

  for (int y = Screen::text_start_index_y; y <= Screen::text_end_index_y; ++y) {
    if (i == text.length()) break; // i know this is abysmal but i'll optimize later... right?
    for (int x = Screen::text_start_index_x; x <= Screen::text_end_index_x; ++x) {
      if (i == text.length()) break;
      canvas[x][y] = text[i];
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
      draw();
      i++;
    }
  }
}
