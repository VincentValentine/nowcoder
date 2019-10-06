// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如序列 1, 2, 3, 4, 5 是某栈的压入顺序，序列 4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列。
// 但 4, 3, 5, 1, 2 就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool res = false;
        int len = pushV.size(), i = 0, j = i;
        stack<int> st;
        
        if(len!=0 && len==popV.size()) {
            while(j < len) {
                while(st.empty() || st.top()!=popV[j]) {
                    if(i == len) break;
                    st.push(pushV[i++]);
                }
                if(st.top() != popV[j]) break;
                st.pop(); ++j;
            }
        }
        if(st.empty() && j==len) res = true;
        return res;
    }
};
