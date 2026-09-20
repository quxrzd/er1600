// "prg.cxx"
// written by rezoid.

// <https://codeberg.org/rezoid/er1600>

// this software is dedicated to the public domain.
// attribution would be appreciated.




// === includes & definitions ===
#include <iostream>
#include <iomanip>
#include "er1600.hxx"

#define MEM (1 << 16)
#define HEX(num) "0x" << setfill('0') << \
setw(num) << uppercase << hex
using namespace std;



// === er1600 function implementations ===
uint8_t mem[MEM] = {0x00};

uint8_t er1600::exR(uint32_t adr)
{
        return mem[adr & (MEM - 1)];
}

void er1600::exW(uint32_t adr, uint8_t val)
{
        mem[adr & (MEM - 1)] = val;
}


// === main function ===
int main(void)
{
        cout << "er1600 test program.\n" << \
        "written by rezoid.\n";

        er1600 rz1600;
        rz1600.rst();

        // hardcoded program of sorts.
        mem[0x0000] = 0b00000000; // nop
        mem[0x0024] = 0b10101010; // illegal instruction.
        mem[0x0032] = 0b00000001; // trm

        // so that we can get the status value.
        uint8_t status = er1600NORMAL;

        while (true)
        {
                if (status != er1600NORMAL) { break; }
                cout << HEX(6) << rz1600.get('I');   \
                cout << " " << HEX(2) <<	     \
                (int)rz1600.exR(rz1600.get('I'))     \
                << "\n";
                status = rz1600.cyc();
        }

        if (status == er1600FAKEOP)
        {	cout << "illegal instruction; ";
        } else if (status == er1600TERMOP)
        {	cout << "halt bit set; ";
        } else
        {	cout << "unknown error; ";
        }

        cout << "system terminated.\n";

}
