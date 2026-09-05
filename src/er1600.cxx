// "er1600.cxx"
// written by rezoid.

// <codeberg.org/rezoid/er1600>


#include "er1600.hxx"


void ER1600::rst()
{
    A = 0x0000;
    B = 0x0000;
    C = 0x0000;
    D = 0x0000;
    F = 0x00;
    G = 0x00000000;
    H = 0x00000000;
    X = 0x00000000;
    Y = 0x00000000;
}

void ER1600::exe()
{
    X += 0x01;
    X &= 0xFFFFFF;
}

uint32_t ER1600::get(char reg)
{
    switch (reg)
    {
        case 'A': return A;
        case 'B': return B;
        case 'C': return C;
        case 'D': return D;
        case 'F': return F;
        case 'G': return G;
        case 'H': return H;
        case 'X': return X;
        case 'Y': return Y;

        default: return 0;
    }
}
