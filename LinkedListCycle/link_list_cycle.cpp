#include <vector>
#include <iostream>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode *pt1 = head;
        ListNode *pt2 = head;
        
        int steps = 0;
        while(pt2 != NULL && pt2->next != NULL)
        {
            pt1 = pt1->next;
            pt2 = pt2->next->next;

            steps++;

            if (pt1 == pt2)
            {
                // 第一次两指针相撞时，环长=步长
                int ring_len = steps;

                pt1 = head;
                pt2 = head;

                // pt2先走一个环长，然后在下一个while中，
                // pt1和pt2一起走，再相撞的话就是环的起始点
                steps = 0;
                while (steps != ring_len)
                {
                    pt2 = pt2->next;
                    steps++;
                }

                while (pt1 != pt2)
                {
                    pt1 = pt1->next;
                    pt2 = pt2->next;
                }

                return pt2;
            }

        }

        return NULL;
    }
};

int main(int argc, char **argv)
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &b;

    Solution test;
    ListNode *ret = test.detectCycle(&a);
    if (ret)
    {
        cout << ret->val << endl;

        return 0;
    }

    cout << "not find cycle" << endl;

    int f;
    cin >> f;

    return 0;
}