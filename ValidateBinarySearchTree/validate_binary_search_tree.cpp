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
 
class SolutionOne {
public:

    void check_valid_bst(TreeNode *root, bool &is_valid_bst, int &min, int &max)
    {
        if (root == NULL)
        {
            is_valid_bst = true;
            return;
        }       

        if (root->left == NULL 
            && root->right == NULL)
        {
            is_valid_bst = true;
            min = root->val;
            max = root->val;
            return;
        }

        bool left_valid_bst = true;
        bool right_valid_bst = true;
        min = root->val;
        max = root->val;

        if (root->left != NULL)
        {
            int left_min = 0;
            int left_max = 0;
            check_valid_bst(root->left, left_valid_bst, left_min, left_max);
            if (left_max >= root->val)
            {
                left_valid_bst = false;
            }
            else
            {
                max = max < left_max ? left_max : max;
                min = min < left_min ? min : left_min;
            }
        }

        if (root->right != NULL)
        {
            int right_min = 0;
            int right_max = 0;
            check_valid_bst(root->right, right_valid_bst, right_min, right_max);

            if (right_min <= root->val)
            {
                right_valid_bst = false;
            }
            else
            {
                max = max < right_max ? right_max : max;
                min = min < right_min ? min : right_min;
            }
        }

        if (left_valid_bst && right_valid_bst)
        {
            is_valid_bst = true;
        }
        else
        {
            is_valid_bst = false;
        }
    }

    bool isValidBST(TreeNode *root) {
        bool is_valid_bst = true;
        int min = 0;
        int max = 0;
        check_valid_bst(root, is_valid_bst, min, max);

        return is_valid_bst;
    }
};

class Solution
{
public:
    bool is_valid_bst(TreeNode *root, TreeNode *&prev)
    {
        if (root == NULL)
        {
            return true;
        }

        if (!is_valid_bst(root->left, prev))
        {
            return false;
        }

        if (prev != NULL 
            && prev->val >= root->val)
        {
            return false;
        }
        prev = root;

        return is_valid_bst(root->right, prev);
    }

    bool isValidBST(TreeNode *root)
    {
        TreeNode *prev = NULL;
        return is_valid_bst(root, prev);
    }
};


int main(int argc, char **argv)
{
    TreeNode r(10);
    TreeNode l1(5);
    TreeNode r1(15);
    TreeNode r11(6);
    TreeNode r12(20);

    r.left = &l1;
    r.right = &r1;
    r1.left = &r11;
    r1.right = &r12;

    Solution test;
    test.isValidBST(&r);


    int f;
    cin >> f;
}