// "microcode.c++"
// written by rezoid.

// <https://www.github.com/quxrzd/er1600>

// this software is dedicated to the public domain.
// attribution would be appreciated.



// INCLUDES & DEFINITIONS
#include "er1600.h++"



// er1600 MICROCODE FUNCTIONS
void er1600::inc(uint8_t  &reg, uint8_t val)
{
    reg = reg + val;
    reg &= 0xFF;
}
void er1600::inc(uint16_t &reg, uint16_t val)
{
    reg = reg + val;
    reg &= 0xFFFF;
}
void er1600::inc(uint32_t &reg, uint32_t val)
{
    reg = reg + val;
    reg &= 0xFFFFFF;
}
void er1600::dec(uint8_t  &reg, uint8_t val)
{
    reg = reg + val;
    reg &= 0xFF;
}
void er1600::dec(uint16_t &reg, uint16_t val)
{
    reg = reg + val;
    reg &= 0xFFFF;
}
void er1600::dec(uint32_t &reg, uint32_t val)
{
    reg = reg - val;
    reg &= 0xFFFFFF;
}
void er1600::set(uint8_t  &reg, uint8_t  bit, bool val)
{
    if (val)
        reg |= (1u << bit);
    else
        reg &= ~(1u << bit);
    reg &= 0xFF;
}
void er1600::set(uint16_t &reg, uint16_t bit, bool val)
{
    if (val)
        reg |= (1u << bit);
    else
        reg &= ~(1u << bit);
    reg &= 0xFFFF;
}
void er1600::set(uint32_t &reg, uint32_t bit, bool val)
{
    if (val)
        reg |= (1u << bit);
    else
        reg &= ~(1u << bit);
    reg &= 0xFFFFFF;
}
