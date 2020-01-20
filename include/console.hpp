//
// Created by VladPC on 20/01/2020.
//

/*
    Color      Background    Foreground
    -----------------------------------
    Black            0           0
    Blue             1           1
    Green            2           2
    Cyan             3           3
    Red              4           4
    Magenta          5           5
    Brown            6           6
    White            7           7
    Gray             -           8
    Intense Blue     -           9
    Intense Green    -           10
    Intense Cyan     -           11
    Intense Red      -           12
    Intense Magenta  -           13
    Yellow           -           14
    Intense White    -           15
*/

#include <windows.h>

class Console {
 private:
  WORD DEFAULT_ATTRIBUTES{};

 public:
  HANDLE handle;

  static int const BG_BLACK = 0;
  static int const BG_BLUE = 1;
  static int const BG_GREEN = 2;
  static int const BG_CYAN = 3;
  static int const BG_RED = 4;
  static int const BG_MAGENTA = 5;
  static int const BG_BROWN = 6;
  static int const BG_WHITE = 7;

  static int const BLACK = 0;
  static int const BLUE = 1;
  static int const GREEN = 2;
  static int const CYAN = 3;
  static int const RED = 4;
  static int const MAGENTA = 5;
  static int const BROWN = 6;
  static int const WHITE = 7;
  static int const GRAY = 8;
  static int const INTENSE_BLUE = 9;
  static int const INTENSE_GREEN = 10;
  static int const INTENSE_CYAN = 11;
  static int const INTENSE_RED = 12;
  static int const INTENSE_MAGENTA = 13;
  static int const YELLOW = 14;
  static int const INTENSE_WHITE = 15;

  explicit Console(HANDLE console);
  void setColor(int foreground = WHITE, int background = BG_BLACK);
  void resetColor();
  void clear();
};
