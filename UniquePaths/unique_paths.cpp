#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // init                 
        vector<vector<int> > dp;
        vector<int> tmp;
        for (int i = 0; i < m; i ++)
        {
            tmp.clear();
            for (int j = 0; j < n; j ++)
            {
                if (i == 0)
                {
                    tmp.push_back(1);
                }
                else
                {
                    tmp.push_back(0);
                }
            }

            dp.push_back(tmp);
        }

        for (int i = 1; i < m; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                for (int m = 0; m <= j; m ++)
                {
                    dp[i][j] += dp[i - 1][m];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main(int argc, char **argv)
{
    int f;
    cin >> f;
}