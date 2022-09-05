#include <iostream>
#include <Router.hpp>
#include <Types.hpp>

using namespace Utils::IFace;

int main() {
    std::cout << "Hello World!" << std::endl;
    Router rtr = Router("R1");
    Router rtr2 = Router("R2", { ETHERNET, ETHERNET });
    return 0;
}