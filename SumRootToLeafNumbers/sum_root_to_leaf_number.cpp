#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <math.h>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    void sum_numbers(TreeNode *root, int num, int &sum)
    {
        if (root == NULL)
        {
            return ;
        }

        if (root->left == NULL
            && root->right == NULL)
        {
            num = num * 10 + root->val;
            sum += num;
            return;
        }

        int left = num * 10 + root->val;
        int right = num * 10 + root->val;

        sum_numbers(root->left, left, sum);
        sum_numbers(root->right, right, sum);
    }

    int sumNumbers(TreeNode *root) {
        int sum = 0;
        sum_numbers(root, 0, sum);

        return sum;
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