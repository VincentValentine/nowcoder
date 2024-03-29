// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(root == nullptr) return { };
        
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *cur = q.front();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            q.pop();
            res.push_back(cur->val);
        }
        return res;
    }
};
