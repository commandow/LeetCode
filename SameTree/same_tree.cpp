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

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        
        if (!(p || q))
        {
            return true;
        }

        if (!p || !q)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char **argv)
{
    int f;
    cin >> f;
}