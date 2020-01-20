//
// Created by VladPC on 20/01/2020.
//

#include <Windows.h>
#include <cstdio>
#include <tuple>
#include <vector>
#include <functional>
#include <console.hpp>
#include <string>
#include <utility>

using namespace std;

class Menu {
 private:
  bool running{};
  int itemsCount{};
  int currentItem{};

 public:
  using CallbackType = function<void()>;
  using ActionType = tuple<string, CallbackType>;
  using CallbacksType = vector<ActionType>;

  string name;
  Console console;
  COORD CursorPosition{};
  CallbacksType callbacks;
  ActionType exitAction{"Exit", []() {}};

  explicit Menu(string name, Console console, ActionType exitAction, CallbacksType callbacks);

  void init();
  void gotoXY(int x, int y);
};
