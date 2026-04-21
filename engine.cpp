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
  // end early if text.length > Screen::textbox_string_max_length
  // ^ i'm assuming the string passed in will be less though, bc this function
  // will be private after testing, and then it'll be called from within a function,
  // which will call another function to check beforehand.

  // call draw with a delay until done drawing string
}
