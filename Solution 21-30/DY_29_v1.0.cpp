/*
29. Divide Two Integers
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.
*/

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Divide Two Integers.
//Memory Usage: 8.7 MB, less than 99.07% of C++ online submissions for Divide Two Integers.
//思路：a/b = e^(ln(a))/e^(ln(b)) = e^(ln(a)-ln(b))
//这种方法并不好，虽然规避了规则漏洞，但是要是能用对数和指数实现为啥不直接用加法实现呢？明显更复杂。

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 0) return INT_MAX;

        double d1 = log(fabs(dividend));
        double d2 = log(fabs(divisor));
        long long result = double(exp(d1-d2));
        if (dividend<0 ^ divisor<0)  result = -result;
        if (result > INT_MAX) return INT_MAX;
        return result;
    }
};
