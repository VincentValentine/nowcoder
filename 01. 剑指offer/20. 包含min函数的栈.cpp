// 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数，时间复杂度应为O(1).

class Solution {
public:
    stack<int> res, st;
    
    void push(int value) {
        st.push(value);
        
        if(res.empty() || value<res.top()) res.push(value);
        else if(!res.empty())res.push(res.top());
    }
    
    void pop() {
        st.pop();
        res.pop();
    }
    int top() {
        return res.top();
    }
    int min() {
        return top();
    }
};
