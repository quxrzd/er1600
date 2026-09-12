// "prg.cxx"
// written by rezoid.

// <codeberg.org/rezoid/er1600>

// this software is dedicated to the public
// domain. attribution would be appreciated.


#include <iostream>
#include <iomanip>
#include "er1600.hxx"

#define HEX(num) "0x" <<       \
setfill('0') << setw(num) <<   \
uppercase << hex 	       \

using namespace std;


uint8_t mem[65536] = {0x00};

uint8_t ER1600::rzR(uint32_t adr)
{
        return mem[adr];
}

void ER1600::rzW(uint32_t adr, uint8_t val)
{
        mem[adr] = val;
}


int main(void)
{
        ER1600 rz1600;
        rz1600.rst();

        rz1600.rzW(0xFFFF, 0xFF);
        cout << HEX(8) << (int)rz1600.rzR(0xFFFF) << "\n";
}
