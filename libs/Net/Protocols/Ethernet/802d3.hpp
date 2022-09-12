#pragma once

/*
Ethernet 802.3
                                                +---------------+
                                                |      MTU      |
+----------+------+-----------+----------+------+---------------+-----+
| Preamble |  SFD | Dest_addr | Src_addr |  len |    payload    | FCS |
|    7B    |  1B  |    6B     |    6B    |  2B  |  46B - 1500B  | 4B  |
+----------+------+-----------+----------+------+---------------+-----+

Ethernet has a maximum frame size of 1518.
Ethernet Header = Dest_addr + Src_addr + len = 14Bytes + FCS = 18Bytes.
*/

template <int mtu> struct Ethernet802d3 {
    char preamble[7];
    char sfd;
    char dest_addr[6];
    char src_addr[6];
    char len[2];
    char data[mtu];
    unsigned int fcs;
};