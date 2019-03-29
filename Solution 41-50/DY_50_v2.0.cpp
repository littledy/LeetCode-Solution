//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
//Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Pow(x, n).
//�ǵݹ飬��λ�ж�
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
            if (p & 1)  // &Ϊλ����������ж�pĩλΪ1����0��Ϊ1����϶�Ӧλ��ֵ
                ans *= x;
            x *= x;     //��һλ�����ֵ
            p >>= 1;    // >>����
        }
        return ans;
    }
};
