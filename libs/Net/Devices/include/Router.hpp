#pragma once
#include <string>
#include <vector>
#include <regex>
#include <iterator>
#include <Logger.hpp>
#include <Slot.hpp>
#include <Device.hpp>

class Router: public Device {
public:
    LIBEXP Router(std::string hostname);
    LIBEXP Router(std::string hostname, std::vector<Utils::IFace::Types> slots_type);
    LIBEXP ~Router() override;
    void connect(std::string local_interface, Device* device, std::string end_interface) override;
private:
    void init();
};