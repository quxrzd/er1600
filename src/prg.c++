// "prg.c++"
// written by rezoid.

// <https://www.github.com/quxrzd/er1600>

// this software is dedicated to the public domain.
// attribution appreciated; not required.


// INCLUDES & DEFINITIONS:
#include <iostream>
#include <fstream>
#include "er1600/er1600.h++"

#define MEM (1u << 16)

using namespace std;


uint8_t mem[MEM] = {0x00};
uint8_t status = NORMAL;


// memory implementations:
uint8_t er1600::exR(uint32_t adr)
{
        return mem[adr & (MEM - 1)];
}
void    er1600::exW(uint32_t adr, uint8_t val)
{
        mem[adr & (MEM - 1)] = val;
}


// MAIN FUNCTION:
int main(void)
{
        cout << "## er1600 implementation program\n";
        cout << "## <http://www.github.com/quxrzd/er1600>";
        cout << "\n\n";

        er1600 rz1600;
        rz1600.rst();

        // unrealistic, but whatever.
        rz1600.exW(0x0000, 0b00001000);
        rz1600.exW(0x0001, 0b11111111);
        rz1600.exW(0x0002, 0b11101110);
        rz1600.exW(0x0003, 0b00000001);


        // execution loop:
        while (true)
        {
                if (status != NORMAL) { break; }

                printf("0x%06X: ", rz1600.get('I'));
                printf("0b%08B\n", \
                rz1600.exR(rz1600.get('I')));

                status = rz1600.cyc();
        }


        // error handler:
        cout << "\n!! ";
        if (status == FAKEOP)
        {
                cout << "illegal instruction.";
        }
        else
        if (status == TERMOP)
        {
                cout << "halt engaged.";
        }
        else
        {
                cout << "unknown error.";
        }

        cout << "\n## status info:\n";
        printf("++ A: 0x%04X\n", rz1600.get('A'));
        printf("++ B: 0x%04X\n", rz1600.get('B'));
        printf("++ C: 0x%04X\n", rz1600.get('C'));
        printf("++ D: 0x%04X\n", rz1600.get('D'));
        printf("++ Q: 0x%06X\n", rz1600.get('Q'));
        printf("++ R: 0x%06X\n", rz1600.get('R'));
        printf("++ I: 0x%06X\n", rz1600.get('I'));
        printf("++ S: 0x%06X\n", rz1600.get('S'));
        printf("++ F: 0b%08B\n", rz1600.get('F'));

        cout << "!! system terminated.\n";
}
