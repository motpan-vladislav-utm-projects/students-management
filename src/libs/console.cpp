//
// Created by VladPC on 20/01/2020.
//

#include "console.hpp"

Console::Console(HANDLE console) {
  this->handle = console ? console : GetStdHandle(STD_OUTPUT_HANDLE);
}

void Console::setColor(int foreground, int background) {
  CONSOLE_SCREEN_BUFFER_INFO Info;
  GetConsoleScreenBufferInfo(handle, &Info);

  DEFAULT_ATTRIBUTES = Info.wAttributes;

  int color = 16 * background + foreground;
  SetConsoleTextAttribute(handle, color);
}

void Console::resetColor() {
  if (DEFAULT_ATTRIBUTES) {
    SetConsoleTextAttribute(handle, DEFAULT_ATTRIBUTES);
  }
}

void Console::clear() {
  COORD topLeft = {0, 0};
  CONSOLE_SCREEN_BUFFER_INFO screen;
  DWORD written;

  GetConsoleScreenBufferInfo(handle, &screen);
  FillConsoleOutputCharacterA(
      handle, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
  );

  FillConsoleOutputAttribute(
      handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, // NOLINT(hicpp-signed-bitwise)
      screen.dwSize.X * screen.dwSize.Y, topLeft, &written
  );

  // SetConsoleCursorPosition(handle, topLeft);
}
