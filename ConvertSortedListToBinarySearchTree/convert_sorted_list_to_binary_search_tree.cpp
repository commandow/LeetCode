#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 // ÖÐÐò±éÀú
class Solution {
public:

    int count_size(ListNode *node)
    {
        int size = 0;
        while (node)
        {
            size++;
            node = node->next;
        }

        return size;
    }

    TreeNode *generate_nodes(int n)
    {
        if (n == 0)
        {
            return NULL;
        }

        TreeNode *node = new TreeNode(0);
        node->left = generate_nodes(n / 2);

        node->val = list_node->val;
        list_node = list_node->next;

        node->right = generate_nodes(n - n / 2 - 1);

        return node;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        list_node = head;
        int size = count_size(head);
        TreeNode *root = generate_nodes(size);

        return root;
    }

    ListNode *list_node;
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