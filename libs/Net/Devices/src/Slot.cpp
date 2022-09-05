#include <Slot.hpp>

Slot::Slot(u16 id, Utils::IFace::Types type) {
    for(u8 i = 0; i < 4; i++)
        m_vInterfaces[i] = new Interface(id, i, type);
}

Slot::~Slot() {
    for(u8 i = 0; i < 4; i++)
        delete m_vInterfaces[i];
}

u16 Slot::getId() { return m_nId; }
Interface** Slot::getInterfaces() { return m_vInterfaces; }