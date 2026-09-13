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
uppercase << hex
using namespace std;


uint8_t mem[65536] = {0x00};

uint8_t er1600::rzR(uint32_t adr)
{
        return mem[adr];
}

void er1600::rzW(uint32_t adr, uint8_t val)
{
        mem[adr] = val;
}


int main(void)
{
        er1600 rz1600;
        rz1600.rst();

        mem[0x0000] = 0b00000000;
        mem[0x0024] = 0b01010101; /* tester shit
        or whatever. */
        mem[0x0022] = 0b00000001;

        uint8_t status;

        while (true)
        {
                status = rz1600.cyc();
                if (status == er1600FAKEOP || \
                status == er1600HALTOP) { break; }

                cout << rz1600.get('I') << "\n";
        }

        if (status == er1600FAKEOP)
        {
                cout << "illgeal instruction\n";
        } else if (status == er1600HALTOP)
        {
                cout << "system halted.\n";
        }

}
