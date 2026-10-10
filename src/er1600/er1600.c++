// "er1600.c++"
// written by rezoid.

// <https://www.github.com/quxrzd/er1600>

// this software is dedicated to the public domain.
// attribution appreciated; not required.


// INCLUDES & DEFINITIONS
#include "er1600.h++"


// PUBLIC FUNCTIONS
void er1600::rst(void)
{
    A = B = C = D = 0x0000;
    y = z = Q = R = I = S = 0x000000;
    F = u = o = s = 0x00;
}

uint8_t er1600::cyc(void)
{
    o = (exR(I) & 0x3F);
    s = ((exR(I) & 0xC0) >> 6);
    switch(o)
    {
        // "nop": no-operation:
        case 0x00:
            inc(I, 1);
            break;

        // "trm": terminate:
        case 0x01:
            stB(F, FLGHLT, 1);
            return TERMOP;

        // "str": set register:
        case 0x08:
            inc(u, 1);
            // read word:
            if(u == 1)
            {
                y = ((exR(I + 1)) << 8 | exR(I + 2));
            }
            // set reg. to word:
            else if(u == 2)
            {
                if(s == 0)      { stV(A, y); }
                else if(s == 1) { stV(B, y); }
                else if(s == 2) { stV(C, y); }
                else if(s == 3) { stV(D, y); }
            }
            // reset and proceed:
            else if(u == 3)
            {
                inc(I, 3);
                stV(u, 0);
            }
            break;

        default:
            return FAKEOP;
    }
        return NORMAL;
}

int32_t er1600::get(char reg)
{
    switch(reg)
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
