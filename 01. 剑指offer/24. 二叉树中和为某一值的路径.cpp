// 输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

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
    vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
        vector<int> path;
        vector<vector<int>> res;
        
        if(root == nullptr) return res;
        helper(res, path, root, expectNumber);
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int> &path, TreeNode *root, int expectNumber) {
        path.push_back(root->val);
        
        if(root->left==nullptr && root->right==nullptr) {
            int i, sum = 0;
            for(i=0; i<path.size(); ++i) sum += path[i];
            if(sum == expectNumber) res.push_back(path);
        }
        if(root->left != nullptr) helper(res, path, root->left, expectNumber);
        if(root->right != nullptr) helper(res, path, root->right, expectNumber);
        path.pop_back();
        return ;
    }
};
