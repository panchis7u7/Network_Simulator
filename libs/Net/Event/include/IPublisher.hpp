#pragma once
#include <platform.hpp>
#include <vector>
#include <algorithm>
#include <IObserver.hpp>
#include <Ethernet/802d3.hpp>

template <class T, int observerListSize>
class IPublisher {
public:
    inline void attach(IObserver* observer);
    inline void detach(IObserver* observer);
    inline void notify();
    inline T getState();
protected:
    IPublisher();
    virtual ~IPublisher() = 0;
private:
    std::vector<IObserver*> m_vObservers;
    T m_tState;
    u8 m_nObserverCount = observerListSize;
};