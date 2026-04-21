#include "engine.h"

int main() {
  Canvas canvas;
  
  std::string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."; 

  canvas.drawText(text);

  return 0;
}
