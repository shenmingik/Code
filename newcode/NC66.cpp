//两个链表的第一个公共结点
//有缘的人终会相逢

/*
输入两个无环的单链表，找出它们的第一个公共结点。
（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
*/
#include <cstdlib>
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
    public:
        ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
            ListNode* p1 = pHead1;
            ListNode* p2 = pHead2;
            while(p1!= p2)
            {
                if(p1 == nullptr) p1 = pHead2;
                else p1 = p1->next;
                if(p2 == nullptr) p2 = pHead1;
                else p2 = p2->next;
            }
            return p1;
        }
    };