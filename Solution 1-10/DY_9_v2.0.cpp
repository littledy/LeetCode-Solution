//这种方法只需要比较前一半与后一半的值即可，运算复杂度减小
//rev用来存储x后一半的值
class Solution {
public:
    bool isPalindrome(int x) {
        //若x非0且末位为0，则x必不可能为回文数，因为x的reverse比x少一位，这种情况容易漏
        if (x<0 || (x!=0 && x%10==0))   return false;
        int rev = 0;

        while (x > rev)
        {
            rev = rev*10 + x%10;
            x /= 10;
        }
        //x=0包含在x==rev中。如果x长度为偶数，比较x==rev，如果x长度为基数，比较x==rev/10
        return (x==rev) || (x==rev/10);
    }
};
