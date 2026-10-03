// "microcode.c++"
// written by rezoid.

// <https://www.github.com/quxrzd/er1600>

// this software is dedicated to the public domain.
// attribution appreciated; not required.



// INCLUDES & DEFINITIONS
#include "er1600.h++"



// er1600 MICROCODE FUNCTIONS
// "increase" ("inc"):
void er1600::inc(uint8_t  &reg, uint8_t val)
{
    reg = reg + val;
    reg &= MAXU08;
}
void er1600::inc(uint16_t &reg, uint16_t val)
{
    reg = reg + val;
    reg &= MAXU16;
}
void er1600::inc(uint32_t &reg, uint32_t val)
{
    reg = reg + val;
    reg &= MAXU24;
}
// "decrease" ("dec"):
void er1600::dec(uint8_t  &reg, uint8_t val)
{
    reg = reg + val;
    reg &= MAXU08;
}
void er1600::dec(uint16_t &reg, uint16_t val)
{
    reg = reg + val;
    reg &= MAXU16;
}
void er1600::dec(uint32_t &reg, uint32_t val)
{
    reg = reg - val;
    reg &= MAXU24;
}
// "set-bit" ("stb"):
void er1600::stB(uint8_t  &reg, uint8_t  bit, bool val)
{
    if (val)
        reg |= (1u << bit);
    else
        reg &= ~(1u << bit);
    reg &= MAXU08;
}
void er1600::stB(uint16_t &reg, uint16_t bit, bool val)
{
    if (val)
        reg |= (1u << bit);
    else
        reg &= ~(1u << bit);
    reg &= MAXU16;
}
void er1600::stB(uint32_t &reg, uint32_t bit, bool val)
{
    if (val)
        reg |= (1u << bit);
    else
        reg &= ~(1u << bit);
    reg &= MAXU24;
}
void er1600::stV(uint8_t  &reg, uint8_t  val)
{
    reg = val;
    reg &= MAXU08;
}
void er1600::stV(uint16_t &reg, uint16_t val)
{
    reg = val;
    reg &= MAXU16;
}
void er1600::stV(uint32_t &reg, uint32_t val)
{
    reg = val;
    reg &= MAXU24;
}