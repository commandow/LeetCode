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
int reverse(int x) {
   int ret = 0;
   while (x != 0) {
      // handle overflow/underflow
      if (abs(ret) > 214748364) {
         return 0;
      }
      ret = ret * 10 + x % 10;
      x /= 10;
   }
   return ret;
}
};

int main(int argc, char **argv)
{
    int x = 1463847412;
    Solution test;
    int ret = test.reverse(x);
    cout << ret << endl;

    int f;
    cin >> f;
}