#ifndef _13_MP3_13LABA_H
#define _13_MP3_13LABA_H

//заголовочный файл для хранения метаданных

unsigned int revBytes(unsigned int n) {
    return ((n >> 24) & 0x000000ff) |
           ((n >> 8) & 0x0000ff00) |
           ((n << 8) & 0x00ff0000) |
           ((n << 24) & 0xff000000);
}

typedef union tagFRAMEHEADER {
    char buffer[10];
    struct {
        unsigned char name[4];
        unsigned int size;
        unsigned short flags;
    } data;
} F_HEADER;

typedef union tagTAGHEADER {
    char buffer[12];
    struct {
        unsigned char flags;
        unsigned int size;
    } data;
} T_HEADER;

#endif //_13_MP3_13LABA_H
