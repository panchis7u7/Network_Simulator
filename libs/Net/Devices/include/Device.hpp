#pragma once
#include <string>
#include <map>
#include <Logger.hpp>
#include <platform.hpp>
#include <Slot.hpp>
#include <Types.hpp>

class Device {
public:
    LIBEXP std::string getHostname();
    LIBEXP std::map<u8, Slot*> getSlots();
    Slot* getSlotbyId(u8 id);
protected:
    Device(std::string hostname);
    Device(std::string hostname, std::vector<Utils::IFace::Types> slot_types);
    virtual ~Device() = 0;
    void virtual connect(std::string local_interface, Device* device, std::string end_interface) = 0;
private:
    std::string m_sHostname;
    std::map<u8,Slot*> m_mSlots;
};