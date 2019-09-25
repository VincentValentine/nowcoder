// 输入一个链表，按链表从尾到头的顺序返回一个ArrayList.

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head == nullptr) return {};
        
        vector<int> res;
        
        helper(head, res);
        
        return res;
    }
    
    void helper(ListNode *cur, vector<int> &res) {
        if(cur->next != nullptr) helper(cur->next, res);
        
        res.push_back(cur->val);
    }
};
