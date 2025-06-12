#include <iostream>
#include "src/Manager.hpp"

int main() {
    Manager manager;
    repeat: // GOTO from line 24
    std::cout << "Welcome to ASCIIFrame!" << '\n' << '\n';
    std::cout << "1. Start" << '\n';
    std::cout << "2. Exit" << '\n';
    char option;
    std::cin >> option;

    if (option == '1') {
        manager.start();
    } else if (option == '2') {
        exit(0);
    } else {
        std::cout << "Invalid option! Type 1 or 2!" << '\n';
        manager.clear(); // Clears the screen
        goto repeat;
    }
}