// 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool res = false;
        
        if(pRoot1!=nullptr && pRoot2!=nullptr) {
            if(pRoot1->val == pRoot2->val) res = helper(pRoot1, pRoot2);
            if(!res) res = HasSubtree(pRoot1->left, pRoot2);
            if(!res) res = HasSubtree(pRoot1->right, pRoot2);
        }
        
        return res;
    }
    
    bool helper(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot2 == nullptr) return true;
        if(pRoot1 == nullptr) return false;
        if(pRoot1->val != pRoot2->val) return false;
        
        if(pRoot1->val == pRoot2->val) 
            return helper(pRoot1->left, pRoot2->left)&&helper(pRoot1->right, pRoot2->right);
    }
};

