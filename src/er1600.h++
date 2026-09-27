// "er1600.h++"
// written by rezoid.

// <https://www.github.com/quxrzd/er1600>

// this software is dedicated to the public domain.
// attribution would be appreciated.



// INCLUDES & DEFINITIONS
#include <cstdint>

#ifndef ER1600_H
#define ER1600_H

#define FLGAAA 0x01
#define FLGBBB 0x02
#define FLGCCC 0x04
#define FLGDDD 0x08
#define FLGEEE 0x10
#define FLGFFF 0x20
#define FLGGGG 0x40
#define FLGHLT 0x80

enum ERRORTYPE
{
        er1600NORMAL,
        er1600FAKEOP,
        er1600TERMOP,
};



// er1600 CLASS
class er1600
{
private:
        // external variables:
        uint16_t  A, B, C, D;
        uint32_t  Q, R, I, S;
        uint8_t   F;
        // internal variables:
        uint8_t   o;

        // MICROCODE FUNCTIONS
        void inc(uint32_t &reg, uint32_t val);
        void dec(uint32_t &reg, uint32_t val);
        void set(uint32_t &reg, uint8_t val);
public:
        void rst(void);
        uint8_t cyc(void);
        uint8_t exR(uint32_t adr);
        void exW(uint32_t adr, uint8_t val);
        uint32_t get(char reg);
};

#endif
