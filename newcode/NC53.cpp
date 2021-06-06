//删除链表的倒数第n个节点

/*
给定一个链表，删除链表的倒数第 nn 个节点并返回链表的头指针
例如，
给出的链表为: 1→2→3→4→5,n=2.
删除了链表的倒数第 n 个节点之后,链表变为1→2→3→5.

备注：
题目保证 n 一定是有效的
请给出请给出时间复杂度为\ O(n) O(n) 的算法
*/


  struct ListNode {
 	int val;
 	struct ListNode *next;
  };

#include <cstdlib>
class Solution
{
public:
    /**
         * 
         * @param head ListNode类 
         * @param n int整型 
         * @return ListNode类
         */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
            return nullptr;
        // write code here
        int size = 0;
        ListNode *p = head;
        while (p)
        {
            size++;
            p = p->next;
        }

        int step = size - n;

        ListNode *pre = (ListNode *)malloc(sizeof(ListNode));
        pre->next = head;
        ListNode *ret = pre;
        ListNode *current = head;
        while (step > 0)
        {
            pre = current;
            current = current->next;
            step--;
        }
        pre->next = current->next;
        free(current);
        head = ret->next;
        free(ret);
        return head;
    }
};