/*
29. Divide Two Integers
Given two integers dividend and divisor, divide two integers without using
multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.

Note:
    #Both dividend and divisor will be 32-bit signed integers.
    #The divisor will never be 0.
    #Assume we are dealing with an environment which could only store integers within
     the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem,
     assume that your function returns 231 − 1 when the division result overflows.
*/

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Divide Two Integers.
//Memory Usage: 8.2 MB, less than 99.69% of C++ online submissions for Divide Two Integers.
/*思路：计算n* 2^power最接近m的值，若相等则result=power，否则remainder=m-n* 2^power
result = power+ (remainder==1)?1:0。即最后的余数比n小则除的结果为0，相等则再加1。*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long long res = 0;
        long long m = abs((long long) dividend);
        long long n = abs((long long) divisor);
        while (m>=n) {
            long long s = n, power = 1;
            while ((s<<1) <= m)  { s<<=1; power<<=1; }
            res += power;
            m-=s;
        }
        if ((dividend>0) ^ (divisor>0)) res = -res;
        return res;
    }
};

