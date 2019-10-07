// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出 Yes, 否则输出 No. 假设输入的数组的任意两个数字都互不相同。

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> &sequence) {
        if(sequence.size() == 0) return false;
        return helper(sequence, 0, sequence.size()-1);
    }
    
    bool helper(vector<int> &sequence, int left, int right) {
        int i, j, root = sequence[right];
        bool seL = true, seR = true;
        
        for(i=left; i<=right-1; ++i) if(sequence[i] > root) break;
        for(j=i; j<=right-1; ++j) if(sequence[j] < root) return false;
        if(i > left) seL = helper(sequence, left, i-1);
        if(j < right) seR = helper(sequence, j, right-1);
        return seL&&seR;
    }
};
