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
		// ����������ͷ�ڵ㣨��λ��һֱ����λ���б���
		// ע���λ+1��ԭ�򼴿�

		if (l1 == NULL && l2 == NULL)
		{
			return NULL;
		}

		ListNode *head = NULL;
		ListNode *tail = NULL;
		bool if_carry = false;  // �״������λ��ӣ���Ȼ�ǲ���λ
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

			// ���������Ľڵ�
			ListNode *node = new ListNode(val);
			if (head == NULL)
			{
				// ͷ�ڵ㣬����ֱ�ӵ�������ֵ
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

			// ���������Ľڵ�
			ListNode *node = new ListNode(val);
			if (head == NULL)
			{
				// ͷ�ڵ㣬����ֱ�ӵ�������ֵ
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

		// �����󻹽�λ��
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