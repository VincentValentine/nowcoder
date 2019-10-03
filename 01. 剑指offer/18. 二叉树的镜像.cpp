// 操作给定的二叉树，将其变换为源二叉树的镜像。

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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr) return ;
        if(pRoot->left==nullptr && pRoot->right==nullptr) return ;
        
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left); Mirror(pRoot->right);
    }
};
