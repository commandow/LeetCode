#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:

    int is_balance(TreeNode *root, bool &is_balanced) {

        if (root == NULL)
        {
            is_balanced = true;
            return 0;
        }

        bool this_balanced = true;
        bool right_balanced = false;
        bool left_balanced = false;
        int left_depth = is_balance(root->left, left_balanced);
        int right_depth = is_balance(root->right, right_balanced);

        int diff = left_depth - right_depth;
        if (diff < -1 || diff > 1)
        {
            this_balanced = false;
        }

        if (left_balanced 
            && right_balanced
            && this_balanced)
        {
            is_balanced = true;
        }

        return (left_depth > right_depth ? left_depth : right_depth) + 1;
    }

    bool isBalanced(TreeNode *root) {

        bool is_balanced = false;
        is_balance(root, is_balanced);

        return is_balanced;
    }
};

int main(int argc, char **argv)
{
    TreeNode r(1);
    TreeNode l1(2);
    TreeNode l2(3);

    r.left = &l1;
    l1.right = &l2;

    Solution test;
    bool ret = test.isBalanced(&r);

    cout << ret << endl;

    int f;
    cin >> f;
}