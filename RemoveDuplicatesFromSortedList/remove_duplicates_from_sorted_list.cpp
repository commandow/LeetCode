#include <string>
#include <algorithm>
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

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {

        if (head == NULL)
        {
            return NULL;
        }

        ListNode *p1 = head;
        ListNode *p2 = head;
        
        while (p1)
        {
            if (p1->val != p2->val)
            {
                p2->next = p1;
                p2 = p1;
            }
            
            p1 = p1->next;
        }

        p2->next = NULL;

        return head;
    }
};

int main(int argc, char **argv)
{
    int f;
    cin >> f;
}