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
    ListNode *swapPairs(ListNode *head) {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *p1 = head;
        ListNode *p2 = head->next;
        ListNode *p3 = head->next->next;

        p2->next = p1;
        p1->next = swapPairs(p3);

        return p2;
    }
};

int main(int argc, char **argv)
{
    int f;
    cin >> f;
}