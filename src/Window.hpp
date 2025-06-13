#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>
#ifdef _WIN32
#include <conio.h>
#else
#include <ncurses.h>
#endif

class Window {
private:
    int m_x;
    int m_y;
    std::vector<std::vector<char>> frame;

    void runNcurses();
    void runConioh();
    void display();
    char changeCharacter();
public:
    Window(int x, int y);
    ~Window() = default;
    void run();
};

#endif //WINDOW_HPP
