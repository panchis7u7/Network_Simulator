#include <Router.hpp>

Router::Router(std::string hostname): Device(hostname) { init(); }
Router::Router(std::string hostname, std::vector<Utils::IFace::Types> interfaces): Device(hostname, interfaces) { 
    init(); 
}
Router::~Router() {}

void Router::init() {
    LDEBUG_CODE_EXECUTION("Router device with name: \'%s\' was created successfuly!", getHostname().c_str());
    LDEBUG_CODE_EXECUTION("\'%s\' has the following interfaces: ", getHostname().c_str());

    std::vector<Interface*> ifaces = getInterfaces();
    LDEBUG_CODE_EXECUTION("Building %i interfaces: ", ifaces.size());
    for(auto& iface : ifaces) {
        LDEBUG_CODE_EXECUTION("%s%i", Utils::IFace::StringTypes[iface->getType()], iface->getId());
    }
}