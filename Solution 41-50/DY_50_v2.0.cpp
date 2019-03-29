//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
//Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Pow(x, n).
//非递归，按位判断
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long p = n;
        if (n < 0)
        {
            long long temp = n;
            p = -temp;
            x = 1/x;
        }
        while (p)
        {
            if (p & 1)  // &为位与运算符，判断p末位为1还是0，为1则乘上对应位的值
                ans *= x;
            x *= x;     //高一位代表的值
            p >>= 1;    // >>右移
        }
        return ans;
    }
};
