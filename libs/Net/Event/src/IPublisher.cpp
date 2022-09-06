#include <IPublisher.hpp>

template <class T, int observerListSize>
IPublisher<T, observerListSize>::IPublisher() { m_vObservers.reserve(observerListSize); }

template <class T, int observerListSize>
IPublisher<T, observerListSize>::~IPublisher() {}

template <class T, int observerListSize>
void IPublisher<T, observerListSize>::attach(IObserver* observer) { m_vObservers.push_back(observer); }

template <class T, int observerListSize>
void IPublisher<T, observerListSize>::detach(IObserver* observer) { 
    //m_vObservers.erase(std::remove(m_vObservers.begin(), m_vObservers.end(), observer), m_vObservers.end());
    observer->update();
}

template <class T, int observerListSize>
void IPublisher<T, observerListSize>::notify() {
    for(auto& observer : m_vObservers)
        observer->update();
}

template <class T, int observerListSize>
T IPublisher<T, observerListSize>::getState() { return m_tState; }

template class IPublisher<Ethernet802d3, 1>;