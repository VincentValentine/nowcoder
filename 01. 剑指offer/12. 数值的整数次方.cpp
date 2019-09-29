// 给定一个 double 类型的浮点数 base 和 int 类型的整数 exponent, 求 base 的 exponent 次方。

// 保证 base 和 exponent 不同时为 0

class Solution {
public:
    double Power(double base, int exponent) {
        if(base==0.0 && exponent<0) return 0.0;
        
        int flag = true, absExponent = exponent;
        double res;
        if(exponent < 0) { flag = false; absExponent *= -1; }
        res = helper(base, absExponent);
        if(!flag) res = 1.0/res;
        return res;
    }
    
    double helper(double base, int exponent) {
        if(exponent == 0) return 1;
        if(exponent == 1) return base;
        
        double res = helper(base, exponent>>1);
        res *= res;
        if((exponent&1) == 1) res *= base;
        return res;
    }
};
