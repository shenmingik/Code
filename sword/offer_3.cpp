//从尾到头打印链表

/*
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/

#include <vector>
#include <algorithm>
using namespace std;
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
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> ret;
        while (head)
        {
            ret.push_back(head->val);
            head = head->next;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
