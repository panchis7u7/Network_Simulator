#include <Device.hpp>

Device::Device(std::string hostname): m_sHostname(hostname) {
    for(int i = 0; i < 2; ++i)
        m_mSlots.insert({i, new Slot(i)});
}

Device::Device(std::string hostname, std::vector<Utils::IFace::Types> slots_type): m_sHostname(hostname) {
    int index = 0;
    for(auto& slot_type : slots_type) {
        m_mSlots.insert({index, new Slot(index, slot_type)});
        ++index;
    }
}

Device::~Device() {
    LDEBUG_CODE_EXECUTION("Destructor called on \'%s\'", getHostname().c_str());
    //for(std::map<u8, Slot*>::iterator it = m_mSlots.begin(); it != m_mSlots.end(); ++it)
    //    m_mSlots.erase(it);
    LDEBUG_CODE_EXECUTION("Destructor ended on \'%s\'", getHostname().c_str());
}

Slot* Device::getSlotbyId(u8 id) { return m_mSlots[id]; }

//--------------------------------------------------------------------------------------------
// Getters and Setters.
//--------------------------------------------------------------------------------------------

std::string Device::getHostname() { return m_sHostname; }
std::map<u8, Slot*> Device::getSlots() { return m_mSlots; }