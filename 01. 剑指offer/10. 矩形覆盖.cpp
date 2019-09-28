// 我们可以用 2*1 的小矩形横着或者竖着去覆盖更大的矩形。请问用 n 个 2*1 的小矩形无重叠地覆盖一个 2*n 的大矩形，总共有多少种方法？

class Solution {
public:
    int rectCover(int number) {
        if(number==0 || number==1 || number==2) return number;
        
        int p = 1, q = 2, i, res;
        for(i=3; i<=number; ++i) {
            res = p+q;
            p = q;
            q = res;
        }
        return res;
    }
};
