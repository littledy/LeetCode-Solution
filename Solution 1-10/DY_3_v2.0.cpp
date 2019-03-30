//3. Longest Substring Without Repeating Characters
//Runtime: 20 ms, faster than 95.72% of C++ online submissions for Longest Substring Without Repeating Characters.
//Memory Usage: 10.7 MB, less than 98.92% of C++ online submissions for Longest Substring Without Repeating Characters.
//���������key��value�ֱ��Ӧ�ַ����±�
//˼·��vector���ƣ������ҵ����������ͬ�ַ���Ϊ����ظ����Ӵ�
//���ܲ���vector�����ܺͶ�Ӧ�Ľṹ�й�
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char,int> m;
        int ans = -1, last = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (m.find(s[i]) != m.end() && m[s[i]] >= last)
                last = m[s[i]];
            ans = max(ans,i-last);
            m[s[i]] = i;
        }
        return ans;
    }
};
