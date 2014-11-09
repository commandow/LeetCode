#include <vector>
#include <iostream>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int sqrt(int x) {

        unsigned int res = 0;
        int bit = 1 << 15;

        while (bit > 0)
        {
            res |= bit;
            if (res * res > x)
            {
                res ^= bit;
            }

            bit >>= 1;
        }

        return res;
    }
};


int main(int argc, char **argv)
{
    Solution test;

    int out = test.sqrt(2147395599);
    cout << out << endl;

    int f;
    cin >> f;
}