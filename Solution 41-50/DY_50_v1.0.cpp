//Runtime: 12 ms, faster than 15.95% of C++ online submissions for Pow(x, n).
//Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Pow(x, n).
//注意int取反可能会溢出，所以用long long型保存n的值。
//递归计算
class Solution {
public:
    double myPow(double x, int n) {
        long long int p = n;
        long long int q = p;
        if (p < 0)
        {
            x = 1/x;
            q = -p;
        }
        if (q==0 || x==1) return 1;
        if (q%2 == 0)   return myPow(x*x,q/2);  //q为偶数递归计算，减少运算量
        return x*myPow(x,q-1);
    }
};
