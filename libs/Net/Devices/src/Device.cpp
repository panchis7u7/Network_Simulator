#include <Device.hpp>

Device::Device(std::string hostname): m_sHostname(hostname) {
    m_vSlots.reserve(2);
    for(int i = 0; i < 2; ++i)
        m_vSlots.push_back(new Slot(i));
}

Device::Device(std::string hostname, std::vector<Utils::IFace::Types> slots_type): m_sHostname(hostname) {
    m_vSlots.reserve(slots_type.size());

    int index = 0;
    for(auto& slot_type : slots_type) {
        m_vSlots.push_back(new Slot(index, slot_type));
        ++index;
    }
}

Device::~Device() {
    for(auto& slot : m_vSlots)
        delete slot;
}

Slot* Device::getSlotbyId(std::string id) {
    
}

//--------------------------------------------------------------------------------------------
// Getters and Setters.
//--------------------------------------------------------------------------------------------

std::string Device::getHostname() { return m_sHostname; }
std::vector<Slot*> Device::getSlots() { return m_vSlots; }