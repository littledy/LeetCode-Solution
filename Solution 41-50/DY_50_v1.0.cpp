//Runtime: 12 ms, faster than 15.95% of C++ online submissions for Pow(x, n).
//Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Pow(x, n).
//ע��intȡ�����ܻ������������long long�ͱ���n��ֵ��
//�ݹ����
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
        if (q%2 == 0)   return myPow(x*x,q/2);  //qΪż���ݹ���㣬����������
        return x*myPow(x,q-1);
    }
};
