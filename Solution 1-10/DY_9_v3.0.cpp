//9. Palindrome Number
//Runtime: 48 ms, faster than 94.39% of C++ online submissions for Palindrome Number.
//Memory Usage: 11.7 MB, less than 98.23% of C++ online submissions for Palindrome Number.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || (x!=0 && x%10==0))   return false;
        if (x >= 0 && x < 10)     return true;
        vector<int> v;
        while (x != 0)
        {
            v.push_back(x%10);
            x /= 10;
        }
        for (int i = 0; i <= (v.size()/2 - 1); i++)
        {
            if (v[i] != v[v.size()-1-i])
                return false;
        }
        return true;
    }
};
