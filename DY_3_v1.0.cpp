class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        int longest = 0, interval = 0;

        //������СΪ128��ֵȫΪ-1��vector����¼��ǰ�ַ���һ�γ��ֵ�λ��
        //��ΪASCII��Ϊ0-127�����Դ�������Ϊ128
        vector<int> last_occur(128,-1);

        for (int i = 0; i < s.size(); i++)
        {
            //last_occur[s[i]]�е�s[i]��Ϊ��Ӧ�ַ���ASCII��
            if (i - last_occur[s[i]] <= interval)
            {
                interval = i - last_occur[s[i]];
            }
            else
                interval++;
            last_occur[s[i]] = i;

            //��¼���ֵ������
            longest = max(longest,interval);
        }
        return longest;
    }
};
