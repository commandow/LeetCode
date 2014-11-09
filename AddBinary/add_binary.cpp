#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
                
        int a_len = a.length();
        int b_len = b.length();

        int max_len = a_len > b_len ? a_len : b_len;

        // ÊÇ·ñ½øÎ»£¿
        bool forword = false;

        string result;
        string tmp;

        for (int i = 0; i < max_len; i ++)
        {
            bool this_foward = false;
            tmp.clear();

            if (i < a_len && i < b_len)
            {
                if (a[a_len - i - 1] == '1'
                    && b[b_len - i - 1] == '1')
                {
                    this_foward = true;
                    if (forword == false)
                    {
                        tmp = "0";
                    }
                    else
                    {
                        tmp = "1";
                    }
                }
                else if ((a[a_len - i - 1] == '1' && b[b_len - i - 1] == '0')
                         || a[a_len - i - 1] == '0' && b[b_len - i - 1] == '1')
                {
                    if (forword == true)
                    {
                        this_foward = true;
                        tmp = "0";
                    }
                    else
                    {
                        tmp = "1";
                    }
                }
                else
                {
                    if (forword == true)
                    {
                        tmp = "1";
                    }
                    else
                    {
                        tmp = "0";
                    }
                }
            }
            else
            {
                if (i < a_len)
                {
                    if (forword  )
                    {
                        if (a[a_len - i - 1] == '1')
                        {
                            this_foward = true;
                            tmp = "0";
                        }
                        else
                        {
                            tmp = "1";
                        }
                    }
                    else
                    {
                        tmp = a[a_len - i - 1];
                    }
                }
                else if (i < b_len)
                {
                    if (forword)
                    {
                        if (b[b_len - i - 1] == '1')
                        {
                            this_foward = true;
                            tmp = "0";
                        }
                        else
                        {
                            tmp = "1";
                        }
                    }
                    else
                    {
                        tmp = b[b_len - i - 1];
                    }
                }
            }

            tmp += result;
            if (this_foward)
            {
                forword = true;
            }
            else
            {
                forword = false;
            }

            result = tmp;
        }

        if (forword)
        {
            string tmp = "1";
            tmp += result;
            result = tmp;
        }

        return result;
    }
};

int main(int argc, char **argv)
{
    string a = "1110111001";
    string b = "110011";

    Solution test;
    string result = test.addBinary(a, b);

    cout << result << endl;

    int c;
    cin >> c;

    return 0;
}