/*
28. Implement strStr()
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's
strstr() and Java's indexOf().
*/

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Implement strStr().
//Memory Usage: 9 MB, less than 99.42% of C++ online submissions for Implement strStr().
//思路：暴力穷举，注意只需要比较从0到hayback.size()-needle.size()开始的字符串

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (needle == "") return 0;
        for (int i = 0; i <= m-n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i+j] != needle[j])
                    break;
            }
            if (j == n)
                return i;
        }
        return -1;
    }
};
