// "er1600.hxx"
// written by rezoid.

// <https://codeberg.org/rezoid/er1600>


#ifndef ER1600_H
#define ER1600_H

#include <cstdint>


class ER1600 {

private:
        int16_t   A; // general
        int16_t   B; // general
        int16_t   C; // general
        int16_t   D; // general

        uint32_t  G; // pointer
        uint32_t  H; // pointer

        uint32_t  X; // counter
        uint32_t  Y; // stack

        uint8_t   F; // flags

public:
        void rst();
        void exe();
};


#endif
