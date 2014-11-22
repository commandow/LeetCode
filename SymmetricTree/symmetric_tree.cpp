#include <string>
#include <algorithm>
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

 // 递归版本
class Solution {
public:

    bool is_symmetric(TreeNode *left, TreeNode *right)
    {
        if (!(left || right))
        {
            return true;
        }

        if (left == NULL && right != NULL
            || left != NULL && right == NULL)
        {
            return false;
        }

        if (left->val != right->val)
        {
            return false;
        }

        return is_symmetric(left->left, right->right) && is_symmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
        {
            return true;
        }
                
        return is_symmetric(root->left, root->right);
    }
};

// 非递归解法
class Solution {
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        stack<TreeNode *> s;

        s.push(root->left);
        s.push(root->right);

        while (!s.empty())
        {
            TreeNode *left = s.top();
            s.pop();
            TreeNode *right = s.top();
            s.pop();

            if (!(left || right))
            {
                continue;
            }

            if (!left || !right)
            {
                return false;;
            }

            if (left->val != right->val)
            {
                return false;
            }

            s.push(left->right);
            s.push(right->left);
            s.push(left->left);
            s.push(right->right);
        }
    }
};

int main(int argc, char **argv)
{
    int f;
    cin >> f;
}