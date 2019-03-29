class Solution {
public:
    int reverse(int x)
    {
        //使用long long int y来保存x的值，以免x取反（即-2^31）发生溢出,rev亦同理
        long long int y = x;
        long long int rev = 0;
        bool positive = true;
        if (y<0)
        {
            y = -y;
            positive = false;
        }

        //取正后逆序
        while (y!=0)
        {
            rev = rev * 10 + y % 10;
            y /= 10;
        }
        if ((rev>>31) > 0)      //>>表示右移操作，右移31位若仍大于0，表示溢出，返回0
            return 0;
        if (positive)
            return (int) rev;
        else
            return (int)-rev;
    }
};
