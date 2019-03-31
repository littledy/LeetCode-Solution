/*14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".*/

//Runtime: 8 ms, faster than 98.70% of C++ online submissions for Longest Common Prefix.
//Memory Usage: 8.7 MB, less than 99.82% of C++ online submissions for Longest Common Prefix.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())   return "";
        int len = strs[0].size();
        string ans = "";
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() < len)   len = strs[i].size();
        }
        bool flag = true;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {flag = false; break;}
            }
            if (flag == false)  break;
            else ans += strs[0][i];
        }
        return ans;
    }
};
