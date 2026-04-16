//#include "engine.h"
#include <iostream>
#include <ostream>

#define SCREEN_WIDTH 96 // should be small enough to render w/o wrapping
#define SCREEN_HEIGHT ((((SCREEN_WIDTH / 2) / 4) * 3)) // 4:3 image ratio accounting for ASCII character dimensions

int main() {
  std::cout << "\033[H\033[2J" << std::flush;

  std::cout << "\033[30;42m" << " hello world";
  for (int i = 12; i < SCREEN_WIDTH; ++i) {
    std::cout << " ";
  }
  std::cout << "\033[0m";
  std::cout << "\n";


  std::cout << "\033[40m";
  for (int y = 1; y <= SCREEN_HEIGHT - 1; ++y) {
    for (int x = 1; x <= SCREEN_WIDTH; ++x) {
      
      std::cout << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\033[0m" << std::flush;


  return 0;
}
