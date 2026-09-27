// "prg.c++"
// written by rezoid.

// <https://www.github.com/quxrzd/er1600>

// this software is dedicated to the public domain.
// attribution would be appreciated.



// INCLUDES & DEFINITIONS
#include "er1600.h++"
#include <iostream>
#include <iomanip>

#define MEM (1u << 16)

// hex-representation macro:
#define HEX(num) "0x" << setfill('0') << \
                 setw(num) << uppercase << hex

using namespace std;



uint8_t mem[MEM] = {0x00};
uint8_t status = er1600NORMAL;

uint8_t er1600::exR(uint32_t adr)
{
        return mem[adr & (MEM - 1)];
}
void er1600::exW(uint32_t adr, uint8_t val)
{
        mem[adr & (MEM - 1)] = val;
}



int main(int argc, char **argv)
{
        cout << "## er1600 implementation program\n";
        cout << "## <https://www.github.com/quxrzd/er1600>";
        cout << "\n\n";

        er1600 rz1600;
        rz1600.rst();

        // (todo): allow importing of .bin files:
        mem[0x0008] = 0b00000001; // "hlt".
        mem[0x0008] = 0b10101010; // illegal instruction.



        while (true)
        {
                if (status != er1600NORMAL) { break; }

                // location of byte memory:
                cout << HEX(6) << rz1600.get('I') << " ";
                // byte in memory:
                cout << HEX(2) << \
                (int)rz1600.exR(rz1600.get('I')) << "\n";

                status = rz1600.cyc();
        }

        cout << "!! ";
        if (status == er1600FAKEOP)
        {
                cout << "illegal instruction.";
        }
        else
        if (status == er1600TERMOP)
        {
                cout << "halt engaged.";
        }
        else
        {
                cout << "unknown error.";
        }

        cout << "\n++ system terminated.\n";
}
