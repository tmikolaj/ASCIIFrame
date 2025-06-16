#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <utility>
#include <vector>

class Manager {
private:
    int fps;
public:
    Manager();
    ~Manager() = default;
    std::pair<int, int> start();
    bool menu();
    void playAnimation(const std::vector<std::vector<std::vector<char>>>& a);
};

#endif //MENU_HPP
