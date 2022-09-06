#include <iostream>
#include <Router.hpp>
#include <Types.hpp>

using namespace Utils::IFace;

int main() {
    std::cout << "Hello World!" << std::endl;
    Router rtr = Router("R1");
    Router rtr2 = Router("R2", { ETHERNET, ETHERNET });
    rtr2.connect("Et0/1", &rtr, "Et0/3");
    return 0;
}