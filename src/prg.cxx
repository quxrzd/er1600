// "prg.cxx"
// written by rezoid.

// <codeberg.org/rezoid/er1600>


#include <iostream>
using namespace std;

#include "er1600.hxx"


int main()
{
        ER1600 rz1600;
        rz1600.rst();

        while (1) {
                rz1600.exe();
                cout << rz1600.get('X') << "\n";
        }


        return 0;
}
