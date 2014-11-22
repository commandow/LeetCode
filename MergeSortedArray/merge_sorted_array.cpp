#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        
        int idx_a = 0;
        int idx_b = 0;
        
        int a_size = m;
        int b_size = n;

        while (idx_a < a_size && idx_b < b_size)
        {
            if (A[idx_a] < B[idx_b])
            {
                idx_a++;
            }
            else
            {
                idx_b++;
                memmove(A + idx_a + 1, A + idx_a, (a_size - idx_a) * sizeof(int));
                A[idx_a ++] = B[idx_b - 1];
                a_size ++;
            }
        }

        if (idx_a == a_size)
        {
            memmove(A + a_size, B + idx_b, (n - idx_b) * sizeof(int));
        }
    }
};

int main(int argc, char **argv)
{

    int f;
    cin >> f;
}