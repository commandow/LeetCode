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
    void init_vec(TreeNode *root,
                        int level, 
                        vector<vector<int> > &vec)
    {
        if (root == NULL)
        {
            return;
        }

        if (level > vec.size() )
        {
            vector<int> tmp;
            vec.push_back(tmp);
        }

        init_vec(root->left, level + 1, vec);
        init_vec(root->right, level + 1, vec);
    }

    void level_order_bottom(TreeNode *root,
                                          int level,
                                          vector<vector<int> > &vec)
    {
        if (root == NULL)
        {
            return;
        }

        level_order_bottom(root->left, level + 1, vec);
        level_order_bottom(root->right, level + 1, vec);

        int size = vec.size();
        vec[size - level].push_back(root->val);
    }

    vector<vector<int> > levelOrderBottom(TreeNode *root) {

        vector<vector<int> > vec;
        init_vec(root, , vec);
        level_order_bottom(root, 1, vec);

        return vec;
    }
};

int main(int argc, char **argv)
{
    TreeNode r(3);
    TreeNode l1(9);
    TreeNode r1(20);
    r.left = &l1;
    r.right = &r1;

    TreeNode l2(15);
    TreeNode r2(7);
    r1.left = &l2;
    r1.right = &r2;

    Solution test;
    test.levelOrderBottom(&r);

    int f;
    cin >> f;
}