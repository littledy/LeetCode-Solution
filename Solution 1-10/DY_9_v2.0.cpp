//���ַ���ֻ��Ҫ�Ƚ�ǰһ�����һ���ֵ���ɣ����㸴�Ӷȼ�С
//rev�����洢x��һ���ֵ
class Solution {
public:
    bool isPalindrome(int x) {
        //��x��0��ĩλΪ0����x�ز�����Ϊ����������Ϊx��reverse��x��һλ�������������©
        if (x<0 || (x!=0 && x%10==0))   return false;
        int rev = 0;

        while (x > rev)
        {
            rev = rev*10 + x%10;
            x /= 10;
        }
        //x=0������x==rev�С����x����Ϊż�����Ƚ�x==rev�����x����Ϊ�������Ƚ�x==rev/10
        return (x==rev) || (x==rev/10);
    }
};
