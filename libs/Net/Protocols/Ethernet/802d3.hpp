#pragma once

typedef struct Ethernet802d3 {
    char preamble[7];
    char SFD;
    char dest_addr[6];
    char src_addr[6];
    char len[2];
    char data[1500];
    u32 CRC;
} Ethernet802d3;