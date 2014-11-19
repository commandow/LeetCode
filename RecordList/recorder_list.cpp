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

class FirstSolution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL 
            || head->next == NULL
            || head->next->next == NULL)
        {
            return;
        }

        ListNode *save_node = head->next;

        ListNode *this_node;
        ListNode *next;
        this_node = head;
        next = head->next;

        while (next->next)
        {
            this_node = next;
            next = next->next;
        }

        next->next = save_node;
        head->next = next;
        this_node->next = NULL;

        reorderList(save_node);
    }
};

// 将下半段截取倒序后，再做合并
class Solution {
public:
    void reorderList(ListNode *head) {

        int list_len = 0;

        ListNode *next = head;
        while (next)
        {
            list_len++;
            next = next->next;
        }

        int half = list_len / 2 + 1;

        int pos = 0;
        next = head;
        ListNode *last = head;
        ListNode *tmp = NULL;
        ListNode *lst2 = NULL;

        while (next)
        {
            pos++;
            tmp = next->next;

            if (pos == half)
            {
                last->next = NULL;
                next->next = NULL;
            }

            if (pos > half)
            {
                next->next = last;
            }

            last = next;
            next = tmp;

            lst2 = last;
        }

        ListNode *lst1 = head;
        ListNode *last_node = head;
        while (lst1 && lst2)
        {
            ListNode *tmp1 = lst1->next;
            ListNode *tmp2 = lst2->next;
            lst1->next = lst2;
            lst2->next = tmp1;

            last_node = lst2;

            lst1 = tmp1;
            lst2 = tmp2;
        }

        if (lst1)
        {
            last_node->next = lst1;
        }

        if (lst2)
        {
            last_node->next = lst2;
        }
    }
};

int main(int argc, char **argv)
{
    ListNode h1(1);
    ListNode h2(2);
    ListNode h3(3);
// ListNode h4(4);

    h1.next = &h2;
    h2.next = &h3;
//    h3.next = &h4;

    Solution test;
    test.reorderList(&h1);

    int f;
    cin >> f;
}