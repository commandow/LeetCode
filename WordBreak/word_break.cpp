#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:

    bool wordBreak(string s, unordered_set<string> &dict) {

        int size = s.length();

        vector<bool> dp(size + 1, false);
        dp[0] = true;

        for (int i = 1; i <= size; i ++)
        {
            for (int j = 0;  j < i ; j ++)
            {
                if (dp[j] && dict.count(s.substr(j, i - j)) > 0)
                {
                    dp[i] = true;
                }
            }
        }

        return dp[size];
    }
};