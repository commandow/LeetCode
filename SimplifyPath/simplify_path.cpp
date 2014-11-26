#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        char *p = const_cast<char *>(path.c_str());

        vector<string> str_vec;
        string tmp;
        while (*p)
        {
            switch (*p)
            {
                case '/':
                {
                    // case last "/"
                    if (*(p + 1) == 0)
                    {
                        if (str_vec.size() == 0)
                        {
                            str_vec.push_back("/");
                        }
                        p++;
                        break;
                    }

                    // case "//"
                    if (*(p + 1) == '/')
                    {
                        p++;
                        break;
                    }

                    // case "/./" or "/."
                    if (*(p + 1) == '.')
                    {
                        if(*(p + 2) == '/')
                        {
                            p = p + 2;
                            break;
                        }
                        
                        if(*(p + 2) == 0)
                        {
                            p = p + 2;
                            if (str_vec.size()== 0)
                            {
                              str_vec.push_back("/");  
                            }
                            break;
                        }
                    }

                    // case "/../"
                    if (*(p + 1) == '.' 
                        && *(p + 2) == '.'
                        && *(p + 3) == '/')
                    {
                        p = p + 3;
                        if (str_vec.size() > 0)
                        {
                            str_vec.pop_back();
                        }
                        break;
                    }
                    
                    // case "/.."
                    if(*(p + 1) == '.' && *(p + 2) == '.' && *(p + 3) == 0)
                    {
                        p = p + 3;
                        
                        if(str_vec.size() > 0)
                        {
                            str_vec.pop_back();
                        }
                        
                        if(str_vec.size() == 0)
                        {
                            str_vec.push_back("/");
                        }
                        break;
                    }

                    // nomal path "/abc/"
                    tmp = '/';
                    while (*++p && *p != '/')
                    {
                        tmp += *p;
                    }

                    str_vec.push_back(tmp);
                }
                default:
                {
                    break;
                }
            }
        }

        string out;
        int size = str_vec.size();
        for (int i = 0; i < size; i ++)
        {
            out += str_vec[i];
        }

        return out;
    }
};

int main(int argc, char **argv)
{
    Solution test;
    string path1 = "/../";
    string path2 = "/home//foo/";
    string path3 = "//";
    string path4 = "/..";
    string out = test.simplifyPath(path4);

    cout << out << endl;

    int f;
    cin >> f;
}