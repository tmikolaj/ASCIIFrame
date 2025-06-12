#include "Manager.hpp"

void Manager::start() {

}
void Manager::clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
