#pragma once
#include <string>
#include <vector>
#include <Interface.hpp>
#include <Types.hpp>
#include "../../platform.hpp"

class Device {
public:
    LIBEXP std::string getHostname();
    LIBEXP std::vector<Interface*> getInterfaces();
protected:
    Device(std::string hostname);
    Device(std::string hostname, std::vector<Utils::IFace::Types> interfaces);
    virtual ~Device();
private:
    std::string m_sHostname;
    std::vector<Interface*> m_vInterfaces;
};