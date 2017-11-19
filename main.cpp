#include <iostream>
using namespace std;

void descram(unsigned char &key, unsigned char &letter)
{
    unsigned char output = 0;
    unsigned short pow2 = 128;
    bool oldbit;
    for (unsigned int i = 0; i <= 7; i++)
    {
        oldbit = (letter/pow2)%2;
        output += (((key%2) ^ ((key/16)%2)) ^ oldbit) * pow2;
        key = (key >> 1) + oldbit*128;
        pow2 /= 2;
    }
    letter = output;

}

int main()
{
    unsigned char key = 5;
    unsigned short scrambled;
    unsigned char output;
    while (cin >> hex >> scrambled)
    {
        output = scrambled;
        descram(key, output);
        cout << output;
    }
    return 0;
}