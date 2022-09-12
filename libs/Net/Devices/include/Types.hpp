#pragma once
#include <string.h>

namespace Utils {

    namespace Models {
        typedef enum TCPIP_HEADERS {
            ETHERNET_HEADER = 0,
            IP_HEADER = 14,
            TCP_HEADER = 34,
            APP_HEADER =  54
        } TCPIP_HEADERS;
    }

    namespace IFace {
        typedef enum Types {
            SERIAL = 0,
            ETHERNET = 1,
            FAST_ETHERNET = 2,
            GIGABIT_ETHERNET = 3,
            TEN_GIGABIT_ETHERNET = 4
        } Types;

        static constexpr const char* StringTypes[5] = {
            "Serial",
            "Ethernet",
            "Fast Ethernet",
            "Gigabit Ethernet",
            "Ten Gigabit Ethernet"
        };
    }
};