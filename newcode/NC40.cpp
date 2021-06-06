//两个链表生成相加链表

/*
假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
给定两个这种链表，请生成代表两个整数相加值的结果链表。
例如：链表 1 为 9->3->7，链表 2 为 6->3，最后生成新的结果链表为 1->0->0->0。
*/

struct ListNode
{
    ListNode(int val_){val = val;}
    int val;
    struct ListNode *next;
};

#include <stack>
using namespace std;
class Solution
{
public:
    /**
         * 
         * @param head1 ListNode类 
         * @param head2 ListNode类 
         * @return ListNode类
         */
    ListNode *addInList(ListNode *head1, ListNode *head2)
    {
        // write code here
        stack<int> link_num1;
        stack<int> link_num2;

        while (head1)
        {
            link_num1.push(head1->val);
            head1 = head1->next;
        }
        while (head2)
        {
            link_num2.push(head2->val);
            head2 = head2->next;
        }
        int flag = 0;
        int add = 0;
        //构造返回链表
        //应该用智能指针
        ListNode *ret = new ListNode(0);
        while (!link_num1.empty() && !link_num2.empty())
        {
            add = link_num1.top() + link_num2.top();
            link_num1.pop();
            link_num2.pop();
            if (flag != 0)
            {
                add += 1;
                flag = 0;
            }
            if (add >= 10)
            {
                flag = 1;
                add -= 10;
            }
            ListNode *temp = new ListNode(add);
            temp->next = ret->next;
            ret->next = temp;
        }

        while (!link_num1.empty())
        {
            add = link_num1.top();
            if (flag != 0)
            {
                add += 1;
                flag = 0;
            }
            if (add >= 10)
            {
                flag = 1;
                add -= 10;
            }
            ListNode *temp = new ListNode(add);
            link_num1.pop();
            temp->next = ret->next;
            ret->next = temp;
        }
        while (!link_num2.empty())
        {
            add = link_num2.top();
            if (flag != 0)
            {
                add += 1;
                flag = 0;
            }
            if (add >= 10)
            {
                flag = 1;
                add -= 10;
            }
            ListNode *temp = new ListNode(add);
            link_num2.pop();
            temp->next = ret->next;
            ret->next = temp;
        }
        if (flag != 0)
        {
            ListNode *temp = new ListNode(1);
            temp->next = ret->next;
            ret->next = temp;
        }
        return ret->next;
    }
};