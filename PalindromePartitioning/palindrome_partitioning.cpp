#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    // ���һ���ַ����Ƿ�Ϊ����
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
        // �߽��������
        if (s.size() == 0)
        {
            // �ܵ��⣬˵���ҵ���һ�����ܵĽ⣬ǰ����Ӵ����Ƿ���������
            result.push_back(sln);
        }

        int size = s.size();

        // ���ַ����ӵ�һ��λ�õ����һ��λ�ã����ν��зָ�
        // ����ÿһ������£�������������ҵ����ʵĽ�
        for (int i = 1; i <= size; i ++)
        {
            string front;
            string remain;

            front.assign(s, 0, i);
            remain.assign(s, i, size - i);

            if (check_palindrome(front))
            {
                // front��������
                sln.push_back(front);

                // Ѱ����front��ͷ�Ŀ��н⣬�������
                find_partition_sln(remain, sln, result);

                // ���¿�ʼ��һ������
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