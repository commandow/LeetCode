#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

        if (l1 == NULL)
        {
            return l2;
        }

        if (l2 == NULL)
        {
            return l1;
        }
                
        ListNode *head;
        if (l1->val > l2->val)
        {
            head = l2;
            l2 = l2->next;
        }
        else
        {
            head = l1;
            l1 = l1->next;
        }

        ListNode *listnode = head;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                listnode->next = l2;
                l2 = l2->next;
            }
            else
            {
                listnode->next = l1;
                l1 = l1->next;
            }

            listnode = listnode->next;
        }

        if (l1)
        {
            listnode->next = l1;
        }
        else
        {
            listnode->next = l2;
        }

        return head;
    }
};

int main(int argc, char **argv)
{
    ListNode l1(2);
    ListNode l2(1);

    Solution test;
    test.mergeTwoLists(&l1, &l2);

    int f;
    cin >> f;
}