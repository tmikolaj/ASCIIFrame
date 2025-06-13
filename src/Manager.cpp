#include "Manager.hpp"

void Manager::start() {
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

    Window window(x, y);
    window.run();
}
