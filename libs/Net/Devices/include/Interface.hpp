#pragma once
#include <platform.hpp>
#include <Types.hpp>
#include <IObserver.hpp>
#include <IPublisher.hpp>

class Interface: IObserver, IPublisher<Ethernet802d3, 1> {
public:
    Interface(u8 slotId, u8 id, Utils::IFace::Types type = Utils::IFace::Types::ETHERNET);
    ~Interface();

    u8 getSlotId();
    u8 getId();
    Utils::IFace::Types getType();
    u32 getDelay();
    u32 getSpeed();
    void update() override;
private:
    u8 m_nSlotId;
    u8 m_nId;
    Utils::IFace::Types m_enType;
    u32 m_uiDelay = 100;
    u32 m_uiSpeed = 100000;
};