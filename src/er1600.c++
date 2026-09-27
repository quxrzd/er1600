// "er1600.c++"
// written by rezoid.

// <https://www.github.com/quxrzd/er1600>

// this software is dedicated to the public domain.
// attribution would be appreciated.



// INCLUDES & DEFINITIONS
#include "er1600.h++"



// PUBLIC FUNCTIONS
void er1600::rst(void)
{
    // external variables:
    A = B = C = D = 0x0000;
    Q = R = I = S = 0x000000;
    F = 0x00;
    // internal variables:
    o = 0x00;
}

uint8_t er1600::cyc(void)
{
    o = exR(I);

    switch (o)
    {
        // "nop"
        case 0x00:
            inc(I, 1);
            break;

        // "trm"
        case 0x01:
            set(F, FLGHLT, 1);
            return er1600TERMOP;

        default:
            return er1600FAKEOP;
    }
        return er1600NORMAL;
}

int32_t er1600::get(char reg)
{
    switch (reg)
    {
        case 'A': return A;
        case 'B': return B;
        case 'C': return C;
        case 'D': return D;
        case 'Q': return Q;
        case 'R': return R;
        case 'I': return I;
        case 'S': return S;
        case 'F': return F;
        default:  return -1;
    }
}
