#include <Router.hpp>

Router::Router(std::string hostname): Device(hostname) { init(); }
Router::Router(std::string hostname, std::vector<Utils::IFace::Types> slots_type): Device(hostname, slots_type) { 
    init(); 
}
Router::~Router() {}

void Router::connect(std::string local_interface, Device* device, std::string end_interface) {
    LDEBUG_CODE_EXECUTION("Device 1: %s, Device 2: %s.", getHostname().c_str(), device->getHostname().c_str());
    std::regex formatting("[\\D\\s]+|[0-9]", std::regex_constants::ECMAScript | std::regex_constants::icase);
    auto matches_begin_loc_iface = std::sregex_iterator(local_interface.begin(), local_interface.end(), formatting);
    auto matches_begin_end_iface = std::sregex_iterator(end_interface.begin(), end_interface.end(), formatting);
    auto matches_end = std::sregex_iterator();

    if(std::distance(matches_begin_loc_iface, matches_end) == 4 && std::distance(matches_begin_end_iface, matches_end) == 4) {
        std::regex identifier_separator_regex("\\d+", std::regex_constants::ECMAScript | std::regex_constants::icase);
        std::smatch match;

        u8 local_iface_identifiers[2], end_iface_identifiers[2];
        std::regex_token_iterator<std::string::iterator> rend;

        u8 i = 0;
        std::regex_token_iterator<std::string::iterator> local_it(local_interface.begin(), local_interface.end(), identifier_separator_regex);
        while(local_it != rend) {
            local_iface_identifiers[i] = (u8)std::stoi(*local_it++);
            ++i;
        }

        i = 0;
        std::regex_token_iterator<std::string::iterator> end_it(end_interface.begin(), end_interface.end(), identifier_separator_regex);
        while(end_it != rend) {
            end_iface_identifiers[i] = (u8)std::stoi(*end_it++);
            ++i;
        }

        Slot* local_requested_slot = device->getSlotbyId(local_iface_identifiers[0]);
        Interface* local_requested_iface = local_requested_slot->getInterfaceById(local_iface_identifiers[1]);

        Slot* end_requested_slot = device->getSlotbyId(end_iface_identifiers[0]);
        Interface* end_requested_iface = end_requested_slot->getInterfaceById(end_iface_identifiers[1]);

        LDEBUG_CODE_EXECUTION("Selected the interface \'%s%i/%i\' from router \'%s\'.", 
            Utils::IFace::StringTypes[local_requested_iface->getType()], 
            local_iface_identifiers[0],
            local_iface_identifiers[1],
            getHostname().c_str());

        LDEBUG_CODE_EXECUTION("Selected the interface \'%s%i/%i\' from router \'%s\'.", 
            Utils::IFace::StringTypes[end_requested_iface->getType()], 
            end_iface_identifiers[0],
            end_iface_identifiers[1],
            device->getHostname().c_str());
    }

    //std::regex ethernet_regex("^E+\D*", std::regex_constants::ECMAScript | std::regex_constants::icase);
}

void Router::init() {
    LDEBUG_CODE_EXECUTION("Router device with name: \'%s\' was created successfuly!", getHostname().c_str());
    LDEBUG_CODE_EXECUTION("\'%s\' has the following interfaces: ", getHostname().c_str());

    std::map<u8, Slot*> entries = getSlots();
    LDEBUG_CODE_EXECUTION("Building %i slots with 4 interfaces each.", entries.size());
    for(auto& entry : entries) {
        std::map<u8, Interface*> iface_map = entry.second->getInterfaces();
        for(auto& iface_entry : iface_map)
            LDEBUG_CODE_EXECUTION("%s%i/%i", Utils::IFace::StringTypes[iface_entry.second->getType()], iface_entry.second->getSlotId(), iface_entry.second->getId());
    }
}