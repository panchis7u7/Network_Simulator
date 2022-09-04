#pragma once
#include <string>
#include <vector>
#include <Logger.hpp>
#include <Interface.hpp>
#include <Device.hpp>

class Router: public Device {
public:
    LIBEXP Router(std::string hostname);
    LIBEXP Router(std::string hostname, std::vector<Utils::IFace::Types> interfaces);
    LIBEXP ~Router() override;
private:
    void init();
};