//
// Created by VladPC on 20/01/2020.
//

#include "menu.hpp"

#include <cstdio>
#include <tuple>
#include <string>
#include <utility>

using namespace std;

Menu::Menu(string name, Console console, ActionType exitAction, CallbacksType callbacks)
    : name(std::move(name)), console(console), exitAction(std::move(exitAction)), callbacks(std::move(callbacks)) {}

void Menu::init() {
  console.clear();
  int listItem = 0;
  bool isCurrent;

  callbacks.push_back(exitAction);

  itemsCount = callbacks.size(); // with exit action
  running = true;

  while (running) {
    currentItem = 0;

    gotoXY(0, currentItem);
    printf("%s", name.c_str());
    currentItem += 1;

    for (ActionType const &action: callbacks) {
      string const *actionName = &get<0>(action);

      isCurrent = currentItem - 1 == listItem;
      if (isCurrent) {
        console.setColor(Console::BLACK, Console::WHITE);
      }

      currentItem += 1;
      gotoXY(0, currentItem);

      printf("%d. %s", currentItem - 1, actionName->c_str());

      if (isCurrent) {
        console.resetColor();
      }
    }

    system("pause > nul");

    if (GetAsyncKeyState(VK_DOWN) & 0x8000) { // NOLINT(hicpp-signed-bitwise)
      listItem += 1;

      if (listItem == itemsCount) {
        listItem = 0;
      }

      continue;
    }

    if (GetAsyncKeyState(VK_UP) & 0x8000) { // NOLINT(hicpp-signed-bitwise)
      listItem -= 1;

      if (listItem < 0) {
        listItem = itemsCount - 1;
      }

      continue;
    }

    if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // NOLINT(hicpp-signed-bitwise)
      gotoXY(0, itemsCount + 3);
      printf("%c[2K", 27);

      CallbackType const actionCallback = get<1>(callbacks.at(listItem));
      string const message = actionCallback();

      if (!message.empty()) {
        printf("%s", message.c_str());
      }

      if (listItem + 1 == itemsCount) {
        running = false;
      }
    }

    if (listItem + 1 != itemsCount) {
      printf("\nPress any key to continue...");
      system("pause > nul");
      console.clear();
    }
  }
}

void Menu::gotoXY(int x, int y) {
  CursorPosition.X = x;
  CursorPosition.Y = y;
  SetConsoleCursorPosition(console.handle, CursorPosition);
}
