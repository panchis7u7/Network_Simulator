#pragma once
#include <Interface.hpp>
#include <Types.hpp>

class Slot {
public:
    friend class Device;
    u16 getId();
    Interface* getInterfaceById(u8 id);
    Interface** getInterfaces();
private:
    Slot(u16 id, Utils::IFace::Types types = Utils::IFace::Types::ETHERNET);
    ~Slot();
    u16 m_nId;
    Interface* m_vInterfaces[4];
};