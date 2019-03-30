//暴力枚举法，思路可行，可以run出结果，但是超出时间限制，待改进
class Solution {
public:
    string longestPalindrome(string s) {
        vector<string> v;
        string ans = "";
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++)
                v.push_back(s.substr(i,j-i+1));
        }
        for (int i = 0; i < v.size(); i++) {
            string p = "";
            for (auto c:v[i]) {
                p+=c;
            }
            if (p.size()>1){
                int k = 0;
                while ((p[k] == p[p.size()-k-1]) && k <= p.size()/2-1)
                    k++;
                if ((k == p.size()/2) && max_len < p.size()) {
                    max_len = p.size();
                    ans = p;
                }
            }
            if (max_len == 0)
                ans = p;
        }
        return ans;
    }
};
