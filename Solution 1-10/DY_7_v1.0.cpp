class Solution {
public:
    int reverse(int x)
    {
        //ʹ��long long int y������x��ֵ������xȡ������-2^31���������,rev��ͬ��
        long long int y = x;
        long long int rev = 0;
        bool positive = true;
        if (y<0)
        {
            y = -y;
            positive = false;
        }

        //ȡ��������
        while (y!=0)
        {
            rev = rev * 10 + y % 10;
            y /= 10;
        }
        if ((rev>>31) > 0)      //>>��ʾ���Ʋ���������31λ���Դ���0����ʾ���������0
            return 0;
        if (positive)
            return (int) rev;
        else
            return (int)-rev;
    }
};
