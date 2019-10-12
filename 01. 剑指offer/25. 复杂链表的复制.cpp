// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。
// 返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr) return pHead;
        
        helper1(pHead);
        helper2(pHead);
        return helper3(pHead);
    }
    
    void helper1(RandomListNode* pHead) {
        while(pHead != nullptr) {
            RandomListNode *temp = new RandomListNode(pHead->label);
            temp->next = pHead->next; pHead->next = temp; pHead = temp->next;
        }
    }
    
    void helper2(RandomListNode* pHead) {
        while(pHead != nullptr) {
            RandomListNode *p = pHead->random;
            if(p != nullptr) pHead->next->random = p->next;
            pHead = pHead->next->next;
        }
    }
    
    RandomListNode* helper3(RandomListNode* pHead) {
        RandomListNode *root = pHead->next, *p = root;
        while(pHead->next->next != nullptr) {
            RandomListNode *temp = p->next;
            pHead->next = temp; p->next = temp->next;
            pHead = pHead->next; p = p->next;
        }
        pHead->next = nullptr;
        
        return root;
    }
};
