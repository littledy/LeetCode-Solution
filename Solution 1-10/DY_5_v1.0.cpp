//5. Longest Palindromic Substring
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Longest Palindromic Substring.
//Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Longest Palindromic Substring.
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)   return s;
        int start = 0, max_len = 0;
        int i = 0;
        while (i < s.size()){
            int r_ptr = i;
            int l_ptr = i;
            //找出重复字串
            while (r_ptr < s.size()-1 && s[r_ptr] == s[r_ptr+1])    r_ptr++;
            i = r_ptr+1;
            //以重复字串为中心进行扩展（如果存在），不存在就以循环开始时的i值进行扩展
            while (r_ptr < s.size()-1 && l_ptr >0 && s[r_ptr+1] == s[l_ptr-1]){
                r_ptr++;
                l_ptr--;
            }
            int new_len = r_ptr - l_ptr + 1;
            if (new_len > max_len){
                start = l_ptr;
                max_len = new_len;
            }
        }
        return s.substr(start,max_len);
    }
};
