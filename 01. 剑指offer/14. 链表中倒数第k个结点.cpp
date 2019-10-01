// 输入一个链表，输出该链表中倒数第k个结点。

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==nullptr || k==0) return nullptr;
        
        ListNode *p = pListHead, *q = p;
        for(int i=0; i<k-1; ++i) {
            if(q->next != nullptr) q = q->next;
            else return nullptr;
        }
        for(; q->next!=nullptr; p=p->next, q=q->next);
        return p;
    }
};
