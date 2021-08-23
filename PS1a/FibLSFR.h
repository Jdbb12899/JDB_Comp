#include <string>
#include <iostream>

using namespace std;

class FibLFSR {
public:
    FibLFSR(string seed);
    ~FibLFSR();
    int step();
    int generate(int k);
    friend ostream& operator<< (ostream &out, const FibLFSR& fiblfsr);
private:
    string Seed;//stores seed
    int rightMost;//stores rightmost
};
