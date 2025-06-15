#include <stdio.h>

union Packet {
    unsigned int allData;
    struct {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } bytes;
};

int main() {
    union Packet pkt;
    pkt.allData = 0x12345678;

    printf("Bytes: %02X %02X %02X %02X\n", pkt.bytes.byte1, pkt.bytes.byte2, pkt.bytes.byte3, pkt.bytes.byte4);

    return 0;
}
