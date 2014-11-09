#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
                int size = digits.size();

        if (digits[size - 1] < 9)
        {
            digits[size - 1] += 1;
            return digits;
        }

        // 是否需要进位
        bool carry = true;

        for (int i = size - 1; i >= 0; i --)
        {
            if (!carry)
            {
                break;
            }

            if (digits[i] == 9)
            {
                carry = true;

                // 进位后，原位置0
                digits[i] = 0;

                if (i == 0)
                {
                    // 数组首个数字进位后，需要新插入数字首位
                    digits.insert(digits.begin(), 1);
                }
            }
            else
            {
                // 不进位，就退出了
                carry = false;
                digits[i] += 1;
            }
        }

        return digits;
    }
};

int main(int argc, char **argv)
{
    Solution test;
    vector<int> v;
    vector<int> v_res;

    int v1 = 9;
    int v2 = 9;
    int v3 = 80;

    v.push_back(v3);
    v.push_back(v2);
    v.push_back(v1);

    v_res = test.plusOne(v);

    for (int i = 0; i < v_res.size(); i ++)
    {
        cout << v_res[i];
    }

    cout << endl;

    int a;
    cin >> a;

    return 0;
}