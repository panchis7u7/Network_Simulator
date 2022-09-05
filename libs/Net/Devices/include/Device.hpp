#pragma once
#include <string>
#include <vector>
#include <Slot.hpp>
#include <Types.hpp>
#include "../../platform.hpp"

class Device {
public:
    LIBEXP std::string getHostname();
    LIBEXP std::vector<Slot*> getSlots();
protected:
    Device(std::string hostname);
    Device(std::string hostname, std::vector<Utils::IFace::Types> slot_types);
    virtual ~Device();
private:
    std::string m_sHostname;
    std::vector<Slot*> m_vSlots;
};