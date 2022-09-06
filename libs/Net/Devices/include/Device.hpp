#pragma once
#include <string>
#include <vector>
#include <platform.hpp>
#include <Slot.hpp>
#include <Types.hpp>

class Device {
public:
    LIBEXP std::string getHostname();
    LIBEXP std::vector<Slot*> getSlots();
protected:
    Device(std::string hostname);
    Device(std::string hostname, std::vector<Utils::IFace::Types> slot_types);
    virtual ~Device();
    virtual connect(Device* device, std::string interface);
    Slot* getSlotbyId(u8 id);
private:
    std::string m_sHostname;
    std::vector<Slot*> m_vSlots;
};