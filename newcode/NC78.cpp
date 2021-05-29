// 反转链表

/*
* 描述：
* 输入一个链表，反转链表后，输出新链表的表头。
*/

/*
* 示例：
* 输入：{1,2,3}
* 输出：{3,2,1}
*/
#include <cstdlib>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *pre = nullptr;
        ListNode *current = pHead;
        ListNode *last = pHead->next;

        while (current)
        {
            current->next = pre;
            pre = current;
            current = last;
            last = current->next;
        }
        return pre;
    }
};