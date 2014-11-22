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
    void preorder_traversal(TreeNode *root, vector<int> &vec)
    {
        if (root == NULL)
        {
            return;
        }

        vec.push_back(root->val);
        preorder_traversal(root->left, vec);
        preorder_traversal(root->right, vec);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vec;
        preorder_traversal(root, vec);

        return vec;
    }
};

int main(int argc, char **argv)
{

    int f;
    cin >> f;
}