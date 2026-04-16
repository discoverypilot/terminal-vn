#include <iostream>
#include <string>

#ifndef ENGINE_H
#define ENGINE_H

#define SCREEN_WIDTH 96 // should be small enough to render w/o wrapping
#define SCREEN_HEIGHT ((((SCREEN_WIDTH / 2) / 4) * 3)) // 4:3 image ratio accounting for ASCII character dimensions
#define TEXTBOX_HEIGHT 7
#define INNER_SCREEN_WIDTH (SCREEN_WIDTH - 2)
#define INNER_SCREEN_HEIGHT (SCREEN_HEIGHT - TEXTBOX_HEIGHT - 2) // extra 2 removed for borders
#define FULL_INNER_SCREEN_HEIGHT (SCREEN_HEIGHT - 2) // for full screen scenes

class CharPixel {
private:
  char char_pixel;
public:
  CharPixel() : char_pixel('x') {};
  CharPixel(char c) : char_pixel(c) {};
  void setChar(char c) { char_pixel = c; };
  CharPixel get(int pos) { return char_pixel; };
};

class CharLine {
private:
  CharPixel *char_line;
public:
  CharLine() : char_line(new CharPixel[SCREEN_WIDTH]) {};
  CharLine(std::string str);
  CharLine(const CharLine &cl);
  void set(std::string str);
  CharPixel get(int pos) { return char_line[pos]; };
  ~CharLine() { delete[] char_line; };
};

class Screen {
private:
  CharLine *screen;
public:
  void clear() { std::cout << "\033[H\033[2J"; };
  void changeColor(int color) { std::cout << "\033[30;42m"; }; // this is a demo, needs to add actual choices in a switch
  void clearColor(int color) { std::cout << "\033[0m"; };
};

#endif
