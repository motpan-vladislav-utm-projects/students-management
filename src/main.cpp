#include <windows.h>
#include <cstdio>

CONSOLE_SCREEN_BUFFER_INFO csbi;
HANDLE hStdOutput;
BOOL bUsePause;

int main() {
    hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!GetConsoleScreenBufferInfo(hStdOutput, &csbi)) {
        printf("GetConsoleScreenBufferInfo failed: %lu\n", GetLastError());
        return EXIT_FAILURE;
    }

    // if cursor position is (0,0) then use pause
    bUsePause = ((!csbi.dwCursorPosition.X) &&
                 (!csbi.dwCursorPosition.Y));

    // only pause if running in separate console window.
    if (bUsePause) {
        printf("\nPress any key to exit...\n");
        getchar();
    }

    return EXIT_SUCCESS;
}