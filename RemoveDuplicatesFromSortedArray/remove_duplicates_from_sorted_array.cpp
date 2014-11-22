#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n)
    {
        if (n == 0)
        {
            return 0;
        }

        int k = 0;
        for (int i = 1; i < n; i++)
        {
            if (A[k] != A[i])
            {
                A[++k] = A[i];
            }
        }

        return k + 1;
    }
};

int main(int argc, char **argv)
{
    int a[] = { 1, 1, 2, 3 };
    Solution test;
    test.removeDuplicates(a, 4);

    int f;
    cin >> f;
}