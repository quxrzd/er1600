// "er1600.cxx"
// written by rezoid.

// <codeberg.org/rezoid/er1600>

// this software is dedicated to the public
// domain. attribution would be appreciated.


#include "er1600.hxx"


void ER1600::rst(void)
{
    A = B = C = D = 0x0000;
    Q = R = I = S = 0x000000;
    F = 0x00;
}

void ER1600::exe(void)
{
    I += 0x01;
    I &= 0xFFFFFF;
}

uint32_t ER1600::get(char reg)
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
