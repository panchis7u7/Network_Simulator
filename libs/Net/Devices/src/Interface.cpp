#include <Interface.hpp>

Interface::Interface(u8 slotId, u8 id, Utils::IFace::Types type): m_nSlotId(slotId), m_nId(id), m_enType(type) {}

Interface::~Interface() {}

//--------------------------------------------------------------------------------------------
// Getters and Setters.
//--------------------------------------------------------------------------------------------

u8 Interface::getSlotId() { return m_nSlotId; }
u8 Interface::getId() { return m_nId; }
Utils::IFace::Types Interface::getType() { return m_enType; }
u32 Interface::getDelay() { return m_uiDelay; }
u32 Interface::getSpeed() { return m_uiSpeed; }