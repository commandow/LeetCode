#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

/*
To solve this problem using only constant space, you have to rethink how the numbers are being represented in computers -- using bits.

If you sum the ith bit of all numbers and mod 3, it must be either 0 or 1 due to the constraint of this problem where each number must appear either three times or once. This will be the ith bit of that "single number".

A straightforward implementation is to use an array of size 32 to keep track of the total count of ith bit.
We can improve this based on the previous solution using three bitmask variables:

ones: as a bitmask to represent the ith bit had appeared once.
twos: as a bitmask to represent the ith bit had appeared twice.
threes: as a bitmask to represent the ith bit had appeared three times.
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0;
        int twos = 0;
        int threes = 0;

        for (int i = 0; i < n; i ++)
        {
            twos |= ones & A[i];
            ones ^= A[i];
            threes = ones & twos;

            ones &= ~threes;
            twos &= ~threes;
        }

        return ones;
    }
};

int main(int argc, char **argv)
{
    int f;
    cin >> f;
}