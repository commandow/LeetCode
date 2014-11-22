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
    void flatten(TreeNode *root, TreeNode *&left_last)
    {
        if (root == NULL)
        {
            return;
        }

        TreeNode *right = root->right;

        if (root->left != NULL)
        {
            root->right = root->left;
            left_last = root->right;
        }

        flatten(root->left, left_last);
        root->left = NULL;

        left_last->right = right;
        if (right != NULL)
        {
            left_last = right;
        }
        flatten(right, left_last);
    }

    void flatten(TreeNode *root) {
        flatten(root, root);
    }
};

int main(int argc, char **argv)
{
    TreeNode r(1);
    TreeNode l1(2);
    TreeNode l2(3);

    r.left = &l1;
    l1.left = &l2;
    
    Solution test;
    test.flatten(&r);

    int f;
    cin >> f;
}