#include "src/Manager.hpp"
#include "src/Window.hpp"

int main() {
    Manager manager;
    bool cont = manager.menu();
    if (cont) {
        std::pair<int, int> dimensions = manager.start();
        Window window(dimensions.first, dimensions.second, manager);
        window.run();
    } else {
        exit(0);
    }
}