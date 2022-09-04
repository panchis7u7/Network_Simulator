#pragma once
#include <string.h>

namespace Utils {
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