#include "engine.h"

void Canvas::assignBorders() {
  for (int x = 0; x < SCREEN_WIDTH; ++x) {
    canvas[x][0] = "═";
    canvas[x][SCREEN_HEIGHT - 1] = "═";
    canvas[x][SCREEN_HEIGHT - 1 - TEXTBOX_HEIGHT] = "═";
  }

  for (int y = 0; y < SCREEN_HEIGHT; ++y) {
    canvas[0][y] = "║";
    canvas[SCREEN_WIDTH-1][y] = "║";
  }

  canvas[0][0] = "╔";
  canvas[0][SCREEN_HEIGHT-1] = "╚";
  canvas[SCREEN_WIDTH - 1][0] = "╗";
  canvas[SCREEN_WIDTH-1][SCREEN_HEIGHT-1] = "╝";
  canvas[0][SCREEN_HEIGHT - 1 - TEXTBOX_HEIGHT] = "╠";
  canvas[SCREEN_WIDTH - 1][SCREEN_HEIGHT - 1 - TEXTBOX_HEIGHT] = "╣";
}

Canvas::Canvas() {
  for (int y = 0; y < SCREEN_HEIGHT; ++y) {
    for (int x = 0; x < SCREEN_WIDTH; ++x) {
      canvas[x][y] = " ";
    }
  }
  assignBorders();
}

void Canvas::draw() {
  clear();
  for (int y = 0; y < SCREEN_HEIGHT; ++y) {
    for (int x = 0; x < SCREEN_WIDTH; ++x) {
      std::cout << canvas[x][y];
    }
    std::cout << "\n";
  }
  std::cout << std::flush;
}
