#pragma once
#include <map>
#include <Interface.hpp>
#include <Types.hpp>

class Device; 
class Slot {
public:
    friend class Device;
    u16 getId();
    Interface* getInterfaceById(u8 id);
    std::map<u8, Interface*> getInterfaces();
private:
    Device* m_devParent;
    Slot(Device* parent, u16 id, Utils::IFace::Types types = Utils::IFace::Types::ETHERNET);
    ~Slot();
    u16 m_nId;
    std::map<u8, Interface*> m_mInterfaces;
};