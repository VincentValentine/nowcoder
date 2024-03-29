// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode *last = nullptr;
        
        helper(pRootOfTree, &last);
        
        TreeNode *head = last;
        while(head!=nullptr && head->left!=nullptr) head = head->left;
        
        return head;
    }
    
    void helper(TreeNode *node, TreeNode **last) {
        if(node == nullptr) return ;
        
        TreeNode *cur = node;
        if(cur->left != nullptr) helper(cur->left, last);
        cur->left = *last;
        if(*last != nullptr) (*last)->right = cur;
        *last = cur;
        if(cur->right != nullptr) helper(cur->right, last);
    }
};
