// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 例如输入前序遍历序列 {1, 2, 4, 7, 3, 5, 6, 8} 和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建二叉树并返回。

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if(pre.size()==0 || vin.size()==0) return nullptr;

        return helper(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }

    TreeNode* helper(vector<int> pre, int preL, int preR, vector<int> vin, int inL, int inR) {
        TreeNode *root = new TreeNode(pre[preL]);

        if(preL==preR && inL==inR) return root;
        int i, leftLen;
        for(i = inL; i<=inR&&vin[i]!=root->val; ++i);
        leftLen = i-inL;
        if(leftLen > 0) root->left = helper(pre, preL+1, preL+leftLen, vin, inL, inL+leftLen-1);
        if(leftLen < inR-inL) root->right = helper(pre, preL+leftLen+1, preR, vin, inL+leftLen+1, inR);
        return root;
    }
};
