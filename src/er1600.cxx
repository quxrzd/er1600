// "er1600.cxx"
// written by rezoid.

// <codeberg.org/rezoid/er1600>

// this software is dedicated to the public
// domain. attribution would be appreciated.


#include "er1600.hxx"


void er1600::rst(void)
{
    A = B = C = D = 0x0000;
    Q = R = I = S = 0x000000;
    t = o = F = 0x00;
}

uint8_t er1600::cyc(void)
{
    o = rzR(I);

    switch (o)
    {
        // "nop"
        case 0x00:
            // confused this shit earlier as trm.
            I += 0x01;
            break;

        // "trm"
        case 0x01:
            I += 0x01;
            F |= FLGHLT;
            return er1600HALTOP;

        default:
            return er1600FAKEOP;
    }
        I &= 0xFFFFFF;
        return er1600NORMAL;
}

uint32_t er1600::get(char reg)
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
        default:  return 0;
    }
}
