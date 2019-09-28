// 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。

class Solution {
public:
    int Fibonacci(int n) {
        if(n==0 || n==1) return n;
        
        int i, p = 0, q = 1, res = 0;
        for(i=2; i<=n; ++i) {
            res = p+q;
            p = q;
            q = res;
        }
        return res;
    }
};
