#ifdef _WIN32
#include <windows.h> // for Sleep()
#define USE_SLEEP
#else
#include <unistd.h> // for usleep
#define USE_USLEEP
#endif
#include "Manager.hpp"

Manager::Manager() : fps(0) {

}
std::pair<int, int> Manager::start() {
    std::cout << "Choose the dimensions of the window" << '\n';
    int x, y;
    std::cout << "X: "; std::cin >> x;
    std::cout << "Y: "; std::cin >> y;
    if (x < 5) {
        std::cout << "Changed x to 5 (minimum value)!" << '\n';
        x = 5;
    } else if (y < 5) {
        std::cout << "Changed y to 5 (minimum value)!" << '\n';
        y = 5;
    } else if (x > 250) {
        std::cout << "Changed x to 250 (maximum value)!" << '\n';
        x = 250;
    } else if (y > 100) {
        std::cout << "Changed y to 100 (maximum value)!" << '\n';
        y = 100;
    }
    std::cout << '\n' << "This is how the cursor looks like: @" << '\n';
    std::cout << "Press 'q' to exit" << '\n';
    std::cout << "Press any key to continue" << '\n';
    std::cin.ignore();
    std::cin.get();

    return { x, y };
}
bool Manager::menu() {
    // true means continue and false exit
    std::cout << "Welcome to ASCIIFrame!" << '\n' << '\n';
    while (true) {
        std::cout << "1. Start" << '\n';
        std::cout << "2. Exit" << '\n';
        char choice;
        std::cin >> choice;

        if (choice == '1') {
            return true;
        } else if (choice == '2') {
            return false;
        } else {
            std::cout << "Invalid choice!" << '\n' << '\n';
        }
    }
}
void Manager::playAnimation(const std::vector<std::vector<std::vector<char>>>& a) {
    char option;
    if (fps != 0) {
        std::cout << "Would you like to change the frames per second value? (t/n): ";
        std::cin >> option;
    }
    if (fps == 0 || option == 't') {
        std::cout << "Please set frames per second: ";
        std::cin >> fps;
        if (fps < 1) {
            std::cout << "Set frames per second to 1 (minimum value)!" << '\n';
            fps = 1;
        } else if (fps > 60) {
            std::cout << "Set frames per second to 60 (maximum value)!" << '\n';
            fps = 60;
        }
    }
    int frameDelay = 1000000 / fps;
    int frameCount = a.size();
    int frameHeight = a[0].size();
    int frameWidth = a[0][0].size();

#ifdef USE_SLEEP
    system("cls");
#else
    system("clear");
#endif

    for (int i = 0; i < frameCount; i++) {
        // Top border
        std::cout << '+';
        for (int j = 0; j < frameWidth; j++) {
            std::cout << '-';
        }
        std::cout << '+' << '\n';

        // Frame content
        for (int j = 0; j < frameHeight; j++) {
            std::cout << '|';
            for (int k = 0; k < frameWidth; k++) {
                std::cout << a[i][j][k];
            }
            std::cout << '|' << '\n';
        }

        // Bottom border
        std::cout << '+';
        for (int j = 0; j < frameWidth; j++) {
            std::cout << '-';
        }
        std::cout << '+' << '\n';

#ifdef USE_SLEEP
        Sleep(frameDelay / 1000);
        system("cls");
#else
        usleep(frameDelay);
        system("clear");
#endif
    }
}