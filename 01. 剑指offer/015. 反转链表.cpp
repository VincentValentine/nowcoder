// 输入一个链表，反转链表后，输出新链表的表头。

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	    val(x), next(NULL) { }
};*/

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr) return pHead;
        
        ListNode *cur = pHead, *pre = nullptr, *pNext = pre, *head = pre;
        while(cur != nullptr) {
            pNext = cur->next;
            if(pNext == nullptr) head = cur;
            cur->next = pre; pre = cur; cur = pNext;
        }
        return head;
    }
};
