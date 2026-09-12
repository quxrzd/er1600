// "er1600.hxx"
// written by rezoid.

// <https://codeberg.org/rezoid/er1600>

// this software is dedicated to the public
// domain. attribution would be appreciated.


#ifndef ER1600_H
#define ER1600_H

#include <cstdint>


class ER1600
{
private:
        uint16_t  A, B, C, D;
        uint32_t  Q, R, I, S;
        uint8_t   F;
public:
        void rst(void);
        void exe(void);
        uint8_t rzR(uint32_t adr);
        void rzW(uint32_t adr, uint8_t val);
        uint32_t get(char reg);
};


#endif
