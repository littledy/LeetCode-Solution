class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        int longest = 0, interval = 0;

        //创建大小为128初值全为-1的vector，记录当前字符上一次出现的位置
        //因为ASCII码为0-127，所以创建长度为128
        vector<int> last_occur(128,-1);

        for (int i = 0; i < s.size(); i++)
        {
            //last_occur[s[i]]中的s[i]变为对应字符的ASCII码
            if (i - last_occur[s[i]] <= interval)
            {
                interval = i - last_occur[s[i]];
            }
            else
                interval++;
            last_occur[s[i]] = i;

            //记录出现的最大间隔
            longest = max(longest,interval);
        }
        return longest;
    }
};
