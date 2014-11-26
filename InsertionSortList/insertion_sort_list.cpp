#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <math.h>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        
    }
};

int main(int argc, char **argv)
{
    TreeNode r(0);
    TreeNode l(1);

    r.left = &l;
    Solution test;
    int ret = test.sumNumbers(&r);
    cout << ret << endl;

    int f;
    cin >> f;
}