#include "stdio.h"

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// 两个链表，从头节点（低位）一直往高位进行遍历
		// 注意进位+1的原则即可

		if (l1 == NULL && l2 == NULL)
		{
			return NULL;
		}

		ListNode *head = NULL;
		ListNode *tail = NULL;
		bool if_carry = false;  // 首次是最低位相加，自然是不进位
		while (l1 != NULL && l2 != NULL)
		{
			int sum = (if_carry ? l1->val + l2->val + 1 : l1->val + l2->val);
			int val = sum;
			if (sum >= 10)
			{
				if_carry = true;
				val = sum - 10;
			}
			else
			{
				if_carry = false;
			}

			// 添加新链表的节点
			ListNode *node = new ListNode(val);
			if (head == NULL)
			{
				// 头节点，后续直接当作返回值
				head = node;
				tail = node;
			}
			else
			{
				tail->next = node;
				tail = node;
			}

			l1 = l1->next;
			l2 = l2->next;
		}

		ListNode *remain = (l1 == NULL ? l2 : l1);

		while (remain != NULL)
		{
			int sum = (if_carry ? remain->val + 1 : remain->val);
			int val = sum;
			if (sum >= 10)
			{
				if_carry = true;
				val = sum - 10;
			}
			else
			{
				if_carry = false;
			}

			// 添加新链表的节点
			ListNode *node = new ListNode(val);
			if (head == NULL)
			{
				// 头节点，后续直接当作返回值
				head = node;
				tail = node;
			}
			else
			{
				tail->next = node;
				tail = node;
			}

			remain = remain->next;
		}

		// 如果最后还进位了
		if (if_carry)
		{
			ListNode *node = new ListNode(1);
			tail->next = node;
			tail = node;
		}

		return head;
	}
};

int main()
{
	Solution sln;
	sln.addTwoNumbers(NULL, NULL);
}