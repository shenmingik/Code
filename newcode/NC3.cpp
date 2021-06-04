//链表中环的入口节点

/*
对于一个给定的链表，返回环的入口节点，如果没有环，返回null
拓展：
你能给出不利用额外空间的解法么？
*/

/*
思路：
1）同linked-list-cycle-i一题，使用快慢指针方法，判定是否存在环，并记录两指针相遇位置(Z)；
2）将两指针分别放在链表头(X)和相遇位置(Z)，并改为相同速度推进，则两指针在环开始位置相遇(Y)。
*/
#include <cstdlib>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *fast = head;
        ListNode *low = head;

        while (fast->next && fast)
        {
            fast = fast->next->next;
            low = low->next;
            //当快慢指针相遇的时候
            if (fast == low)
            {
                //一个指针从头
                fast = head;
                //它们相遇，即是环入口
                while (low != fast)
                {
                    fast = fast->next;
                    low = low->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};