//合并有序链表

/*
将两个有序的链表合并为一个新链表，要求新的链表是通过拼接两个链表的节点来生成的，且合并后新链表依然有序。
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    /**
         * 
         * @param l1 ListNode类 
         * @param l2 ListNode类 
         * @return ListNode类
         */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // write code here
        ListNode *ret = new ListNode;
        ListNode *p = ret;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                ret->next = l1;
                l1 = l1->next;
            }
            else
            {
                ret->next = l2;
                l2 = l2->next;
            }
            ret = ret->next;
        }

        if (l1)
        {
            ret->next = l1;
        }
        if (l2)
        {
            ret->next = l2;
        }
        return p->next;
    }
};