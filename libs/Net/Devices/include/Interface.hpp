#pragma once
#include <Types.hpp>
#include "../../platform.hpp"

class Interface {
public:
    Interface(u16 id, Utils::IFace::Types type = Utils::IFace::Types::ETHERNET);
    ~Interface();

    u16 getId();
    Utils::IFace::Types getType();
    u32 getDelay();
    u32 getSpeed();
private:
    u16 m_nId;
    Utils::IFace::Types m_enType;
    u32 m_uiDelay = 100;
    u32 m_uiSpeed = 100000;
};