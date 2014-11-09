#include <vector>
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
    int maxDepth(TreeNode *root) {
        if (root == NULL)
        {
            return 0;
        }

        int right_length = maxDepth(root->right);
        int left_lengh = maxDepth(root->left);

        // 左右子树，看谁长，就取哪个节点的最长路径
        if (left_lengh >= right_length)
        {
            return left_lengh + 1;
        }

        return right_length + 1;
    }
};