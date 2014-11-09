#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    // 检查一个字符串是否为回文
    bool check_palindrome(string s)
    {
        int size = s.size();
        for (int i = 0; i < size/2; i ++)
        {
            if (s[i] != s[size - i - 1])
            {
                return false;
            }
        }

        return true;
    }

    void find_partition_sln(string s, 
                                        vector<string> &sln, 
                                        vector<vector<string> > &result)
    {
        // 边界结束条件
        if (s.size() == 0)
        {
            // 能到这，说明找到了一个可能的解，前面的子串都是符合条件的
            result.push_back(sln);
        }

        int size = s.size();

        // 把字符串从第一个位置到最后一个位置，依次进行分隔
        // 并在每一种情况下，利用深度搜索找到合适的解
        for (int i = 1; i <= size; i ++)
        {
            string front;
            string remain;

            front.assign(s, 0, i);
            remain.assign(s, i, size - i);

            if (check_palindrome(front))
            {
                // front符合条件
                sln.push_back(front);

                // 寻找以front开头的可行解，深度优先
                find_partition_sln(remain, sln, result);

                // 重新开始下一个查找
                sln.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> sln;
        vector<vector<string> > result;
        
        find_partition_sln(s, sln, result);

        return result;
    }
};

int main(int argc, char **argv)
{
    Solution test;
    string s = "fsfddfsf";

    vector<vector<string>> result;
    result = test.partition(s);

    for (int i = 0; i < result.size(); i ++)
    {
        cout << "string:";

        for (int j = 0; j < result[i].size(); j ++)
        {
            cout << "\""
                << result[i][j].c_str()
                << "\",";
        }

        cout << endl;
    }

    int a;
    cin >> a;
}