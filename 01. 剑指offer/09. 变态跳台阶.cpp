// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

class Solution {
public:
    int jumpFloorII(int number) {
        int i, res = 1;
        
        for(i=0; i<number-1; ++i) res *= 2;
        
        return res;
    }
};
