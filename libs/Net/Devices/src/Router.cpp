#include <Router.hpp>

Router::Router(std::string hostname): Device(hostname) { init(); }
Router::Router(std::string hostname, std::vector<Utils::IFace::Types> slots_type): Device(hostname, slots_type) { 
    init(); 
}
Router::~Router() {}

void Router::init() {
    LDEBUG_CODE_EXECUTION("Router device with name: \'%s\' was created successfuly!", getHostname().c_str());
    LDEBUG_CODE_EXECUTION("\'%s\' has the following interfaces: ", getHostname().c_str());

    std::vector<Slot*> slots = getSlots();
    LDEBUG_CODE_EXECUTION("Building %i slots with 4 interfaces each.", slots.size());
    for(auto& slot : slots) {
        Interface** ifaces = slot->getInterfaces();
        for(u16 i = 0; i < 4; ++i) {
            LDEBUG_CODE_EXECUTION("%s%i/%i", Utils::IFace::StringTypes[ifaces[i]->getType()], ifaces[i]->getSlotId(), ifaces[i]->getId());
        }
    }
}