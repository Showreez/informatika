#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;

int main() {
    float x = 13.625f;
    unsigned int bits;
    memcpy(&bits, &x, sizeof(x));

    cout << bitset<32>(bits) << endl;

    return 0;
}
