/*
28. Implement strStr()
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's
strstr() and Java's indexOf().
*/

//Runtime: 8 ms, faster than 95.25% of C++ online submissions for Implement strStr().
//Memory Usage: 9.1 MB, less than 99.22% of C++ online submissions for Implement strStr().
//˼·��Ҳ�Ǳ�����٣�������substr(int n, int len)�����ж��ִ��Ƿ���ȡ�

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size(), p=0;
        while (p+n-1 < m) {
            if (haystack.substr(p,n) == needle) return p;
            while (p++ + n + 1 < m && haystack[p] != needle[0]);
        }
        /*����ֱ��
        while (p+n-1 < m) {
            if (haystack.substr(p,n) == needle) return p;
            p++;
        }�������*/

        return -1;
    }
};
