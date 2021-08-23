#include <iostream>
#include <string>
#include "FibLSFR.h"
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main() {
    FibLFSR l1 = FibLFSR("00000001");
    cout << l1 << endl;

    l1.step();
    cout << l1 << endl;

    l1.step();
    cout << l1 << endl;

    l1.step();
    cout << l1 << endl;

    l1.step();
    cout << l1 << endl;

    l1.step();
    cout << l1 << endl;

    l1.step();
    cout << l1 << endl;

    l1.step();
    cout << l1 << endl;

    l1.step();
    cout << l1 << endl;

    l1.step();
    cout << l1 << endl;
    l1.step();
    cout << l1 << endl << endl;

    cout << "TEST GENERATE" << endl;
    FibLFSR l2 = FibLFSR("00000001");
    l2.generate(5);
    cout << l2 << endl;
    cout << l2 << endl;
    return 0;
}

FibLFSR::FibLFSR(string seed) {
    Seed = seed;//initialize seed as input
    int a0 = Seed[0] - 48;//initialize rightmost
    int a2 = Seed[2] - 48;
    int a3 = Seed[3] - 48;
    int a5 = Seed[5] - 48;
    int xor1 = (a3 ^ a5);
    int xor2 = (a0 ^ a2);
    rightMost = xor1 ^ xor2;
}

FibLFSR::~FibLFSR() {
    delete &Seed;
}

ostream& operator<< (ostream& out, const FibLFSR& fiblfsr) {
    out << fiblfsr.Seed << " " << fiblfsr.rightMost << endl; //print seed then rightmost
    return out;
}

int FibLFSR::step() {
    int x0 = Seed[0] - 48;//cast chars from string to ints for xor
    int x2 = Seed[2] - 48;
    int x3 = Seed[3] - 48;
    int x5 = Seed[5] - 48;
    int xor1 = (x3 ^ x5);//xor by fibonacci pattern
    int xor2 = (x0 ^ x2);
    rightMost = xor1 ^ xor2;
    char xorChar = rightMost + 48;
    Seed.erase(0, 1);//erase first bit (shift)
    Seed = Seed + xorChar;//add next character to end of seed
    return rightMost;//update rightmost

}


int FibLFSR::generate(int k) {
    int var1 = 0;
    for (int z = 0; z != k; z++) {
        int d = step();//call step function k times
        var1 += (d * pow(2, (z - 1)));//convert binary to decimal
    }
    rightMost = var1;  //update rightmost
    return rightMost; //return generated output
}
