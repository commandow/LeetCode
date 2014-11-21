#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL)
        {
            return 0;
        }

        char *p = const_cast<char *>(s);

        int len = 0;
        for (; *p; p++)
        {
            if (*p == ' ')
            {
                while(*p && *p == ' ')
                {
                    p++;
                }
                
                if (*p == 0)
                {
                    return len;
                }
                
                len = 1;
                continue;
            }

            if (!((*p <= 'Z' && *p >= 'A')
                || (*p <= 'z' && *p >= 'a')))
            {
                len = 0;

                while (*p && *p != ' ')
                {
                    p++;
                }

                if (*p == 0)
                {
                    return 0;
                }

                continue;
            }

            len++;
        }
        
        return len;
    }
};

int main(int argc, char **argv)
{
    Solution test;

    int len = test.lengthOfLastWord(" a");

    cout << len << endl;

    int f;
    cin >> f;
}