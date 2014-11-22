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
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {

        ListNode *p1 = head;
        ListNode *p2 = head;

        int steps = 0;
        while (p2
               && steps < n + 1)
        {
            p2 = p2->next;
            steps++;
        }

        if (steps == n + 1)
        {
            while (p2)
            {
                p2 = p2->next;
                p1 = p1->next;
            }
            
            p1->next = p1->next->next;
        }

        if (steps < n + 1)
        {
            head = head->next;
        }

        return head;
    }
};


int main(int argc, char **argv)
{
    ListNode head(1);
    ListNode node(2);
    head.next = &node;
    Solution test;
    test.removeNthFromEnd(&head, 1);

    int f;
    cin >> f;
}