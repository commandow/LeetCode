#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

/***********************************************
    the first solution uses too much memory
************************************************/
class FirstSolution {
public:
    int numDistinct(string s, string t) {
                
        int len = s.length();
        int sub_len = t.length();

        // 缓存下所有可能的字符串
        list<string> possible_strs;
        vector<int> dp(len + 1, 0);
        
        list<string> copy_list;
        for (int i = 0; i < len; i ++)
        {
            char cur_ch = s[i];
            string empty_str;

            int match_num = 0;
            copy_list.clear();

            // 对所有可能的字符串进行遍历，看看能产生多少的匹配量，并更新可能的字符串list
            for (list<string>::iterator iter = possible_strs.begin(); iter != possible_strs.end(); iter ++)
            {
                iter->append(1, cur_ch);
                int  str_len = iter->length();
                if (iter->compare(0, str_len, t, 0, str_len) != 0)
                {
                    *iter = iter->substr(0, str_len - 1);

                    str_len = iter->length();
                    for (int m = str_len - 1; m >= 0; m --)
                    {
                        if ((*iter)[m] != cur_ch)
                        {
                            break;
                        }

                        copy_list.push_back(*iter);
                    }

                    continue;
                }

                if (str_len == sub_len)
                {
                    match_num++;
                }
            }

            for (list<string>::iterator iter = copy_list.begin(); iter != copy_list.end(); iter ++)
            {
                possible_strs.push_back(*iter);
            }

            if (s[i] == t[0])
            {
                string new_str;
                new_str.assign(1, s[i]);
                possible_strs.push_back(new_str);
            }

            dp[i + 1] = dp[i] + match_num;
        }

        return dp[len];
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
                
        int len = s.length();
        int sub_len = t.length();

        vector<vector<int> > dp;

        // 初始化二维数组
        vector<int> tmp;
        for (int i = 0; i <= len; i ++)
        {
            tmp.clear();
            for (int j = 0; j <= sub_len; j ++)
            {
                if (j == 0)
                {
                    // 初始化，当子串为空串，只有一种情况可以转换，就是把自已的数据删除掉
                    tmp.push_back(1);
                }
                else
                {
                    tmp.push_back(0);
                }
            }
            dp.push_back(tmp);
        }

        for (int i = 0; i < len; i ++)
        {
            for (int j = 0; j < sub_len; j ++)
            {
                if (s[i] == t[j])
                {
                    dp[i + 1][j + 1] = dp[i][j + 1] + dp[i][j];
                }
                else
                {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                }
            }
        }

        return dp[len][sub_len];
    }
};

int main(int argc, char **argv)
{
    Solution test;
    string s = "aacaacca";
    string t = "ca";

    int ret = test.numDistinct(s, t);

    cout << ret << endl;

    int f;
    cin >> f;
}