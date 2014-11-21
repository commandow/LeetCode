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
    void level_order(TreeNode *root,
                               int level,
                               vector<vector<int> > &vec)
    {
        if (root == NULL)
        {
            return;
        }

        if (vec.size() > level)
        {
            vec[level].push_back(root->val);
        }
        else
        {
            vector<int> tmp;
            tmp.push_back(root->val);
            vec.push_back(tmp);
        }

        level_order(root->left, level + 1, vec);
        level_order(root->right, level + 1, vec);
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
            vector<vector<int> > vec;
            level_order(root, 0, vec);

            return vec;
    }
};

int main(int argc, char **argv)
{
    int f;
    cin >> f;
}