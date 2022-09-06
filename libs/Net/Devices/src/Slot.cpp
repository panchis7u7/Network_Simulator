#include <Slot.hpp>

Slot::Slot(Device* parent, u16 id, Utils::IFace::Types type): m_devParent(parent) {
    for(u8 i = 0; i < 4; i++)
        m_mInterfaces.insert({i, new Interface(parent, id, i, type)});
}

Slot::~Slot() {
    for(std::map<u8, Interface*>::iterator it = m_mInterfaces.begin(); it != m_mInterfaces.end(); ++it)
        m_mInterfaces.erase(it);
}

Interface* Slot::getInterfaceById(u8 id) { return m_mInterfaces[id]; }

u16 Slot::getId() { return m_nId; }
std::map<u8, Interface*> Slot::getInterfaces() { return m_mInterfaces; }