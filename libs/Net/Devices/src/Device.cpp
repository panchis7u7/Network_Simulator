#include <Device.hpp>

Device::Device(std::string hostname): m_sHostname(hostname) {
    for(int i = 0; i < 4; ++i)
        m_vInterfaces.push_back(new Interface(i));
}

Device::Device(std::string hostname, std::vector<Utils::IFace::Types> interfaces): m_sHostname(hostname) {
    m_vInterfaces.reserve(interfaces.size());
    int index = 0;
    for(auto& interface : interfaces) {
        m_vInterfaces.push_back(new Interface(index, interface));
        ++index;
    }
}

Device::~Device() {
    for(auto& interface : m_vInterfaces)
        delete interface;
}

//--------------------------------------------------------------------------------------------
// Getters and Setters.
//--------------------------------------------------------------------------------------------

std::string Device::getHostname() { return m_sHostname; }
std::vector<Interface*> Device::getInterfaces() { return m_vInterfaces; }