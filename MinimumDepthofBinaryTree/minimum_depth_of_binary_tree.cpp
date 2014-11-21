#include <string>
#include <vector>
#include <list>
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
    int minDepth(TreeNode *root) {
        if (root == NULL)
        {
            return 0;
        }

        if (root->left == NULL)
        {
            return minDepth(root->right) + 1;
        }

        if (root->right == NULL)
        {
            return minDepth(root->left) + 1;
        }

        int left_depth = minDepth(root->left) + 1;
        int right_depth = minDepth(root->right) + 1;

        return left_depth > right_depth ? right_depth : left_depth;
    }
};

int main(int argc, char **argv)
{
    int f;
    cin >> f;
}