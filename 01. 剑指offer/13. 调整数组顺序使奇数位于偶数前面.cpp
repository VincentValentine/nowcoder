// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分。
// 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
// 若不必保证相对位置不变，则可利用双指针，交换数组元素。

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int i, len = array.size();
        if(len == 0) return ;
        
        queue<int> even, odd;
        for(i=0; i<len; ++i) {
            if(array[i] & 1) odd.push(array[i]);
            else even.push(array[i]);
        }
        for(i=0; i<len&&!odd.empty(); ++i) {
            array[i] = odd.front();
            odd.pop();
        }
        for(; i<len&&!even.empty(); ++i) {
            array[i] = even.front();
            even.pop();
        }
    }
};
