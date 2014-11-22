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


 class Solution{

public:
    TreeNode *build_tree(vector<int>::iterator &inoder_begin,
                                     vector<int>::iterator &inoder_end,
                                     vector<int>::iterator &postorder_begin,
                                     vector<int>::iterator &postorder_end)
    {
        vector<int>::iterator tmp = inoder_end;

        if (inoder_begin == inoder_end)
        {
            return NULL;
        }

        tmp = postorder_end;
        TreeNode *root = new TreeNode(*(-- tmp));

        vector<int>::iterator left_inorder_begin = inoder_begin;
        vector<int>::iterator right_inorder_end = inoder_end;
        vector<int>::iterator left_inorder_end;
        vector<int>::iterator right_inorder_begin;

        vector<int>::iterator left_postorder_begin = postorder_begin;
        vector<int>::iterator left_postorder_end;
        vector<int>::iterator right_postorder_begin;

        tmp = postorder_end;
        vector<int>::iterator right_postorder_end = --tmp;

        for (vector<int>::iterator iter = inoder_begin; iter != inoder_end; iter ++)
        {
            if (*iter == root->val)
            {
                left_inorder_end = iter;
                right_inorder_begin = ++iter;
                break;
            }
        }

        if (right_inorder_begin == right_inorder_end)
        {
            left_postorder_end = tmp;
            right_postorder_begin = tmp;
        }
        else
        {
            for (vector<int>::iterator iter = postorder_begin; iter != postorder_end; iter ++)
            {
                tmp = find(left_inorder_begin, left_inorder_end, *iter);
                if (tmp == left_inorder_end)
                {
                    left_postorder_end = iter;
                    right_postorder_begin = iter;
                    break;
                }
            }
        }

        root->left = build_tree(left_inorder_begin, left_inorder_end, left_postorder_begin, left_postorder_end);
        root->right = build_tree(right_inorder_begin, right_inorder_end, right_postorder_begin, right_postorder_end);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        vector<int>::iterator inorder_begin= inorder.begin();
        vector<int>::iterator inorder_end = inorder.end();
        vector<int>::iterator postorder_begin = postorder.begin();
        vector<int>::iterator postorder_end = postorder.end();
        
        build_tree(inorder_begin, inorder_end, postorder_begin, postorder_end);
    }
    
 };

 // 这个方法每次递归需要创建Vector的临时变量
 // 会用较多内存，不推荐，但方法和用iterator替
 // 代的情况相同
class SolutionOne{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0
            || postorder.size() == 0)
        {
            return NULL;
        }

        int size = postorder.size();

        TreeNode *root = new TreeNode(postorder[size - 1]);

        vector<int> left_inorder;
        vector<int> right_inorder;

        vector<int> left_postorder;
        vector<int> right_postorder;

        for (vector<int>::iterator iter = inorder.begin(); iter != inorder.end(); iter ++)
        {
            if (*iter == root->val)
            {
                left_inorder.assign(inorder.begin(), iter);
                right_inorder.assign((++iter), inorder.end());
                break;
            }
        }

        if (!right_inorder.empty())
        {
            for (vector<int>::iterator iter = postorder.begin(); iter != postorder.end(); iter ++)
            {
                for (int i = 0; i < right_inorder.size(); i ++)
                {
                    if (*iter == right_inorder[i])
                    {
                        left_postorder.assign(postorder.begin(), iter);
                        right_postorder.assign(iter, (--postorder.end()));
                    }
                }
            }
        }
        else
        {
            left_postorder.assign(postorder.begin(), (--postorder.end()));
        }

        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);

        return root;
    }
};

int main(int argc, char **argv)
{
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    vector<int> b;
    b.push_back(2);
    b.push_back(1);

    Solution test;
    TreeNode *root = test.buildTree(a, b);

    int f;
    cin >> f;
}