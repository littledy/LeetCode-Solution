//1. Two Sum
//Runtime: 12 ms, faster than 92.32% of C++ online submissions for Two Sum.
//Memory Usage: 10.3 MB, less than 40.12% of C++ online submissions for Two Sum.
//˼·�����Ƚ���һ�������num_id������������nums��������е�ÿ��Ԫ����2��ֵ��
//��һ����key���ڶ�����value������ͨ��key����������value���������Ӧ�ľ���������
//��ΪKey,��Ӧ��Ԫ��ֵΪvalue��ע��ÿ��Ԫ��ֻ������һ�Σ�����Ҫ��������ֵ�ظ����á�
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //�������һ����key���ڶ�����value������ͨ��key����������value
        unordered_map<int,int> num_id;
        //��nums��ֵ����num_id
        for (int i = 0; i < nums.size(); i++)
        {
            num_id[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int res = target - nums[i];

            //���res��num.id�У�����ָ��res�ĵ��������ǿգ�����num_id.end()
            auto it = num_id.find(res);

            //ȷ��nums��ֵδ���ظ�ʹ��
            if (it != num_id.end() && i!=it->second) return vector<int>{i,it->second};

            /*�ڶ���˼·������Ҫ�ȴ���num_id�����������飬�жϲ����������num_id����
            ��֤���ظ���i��it->second�������������˳����it->second,i;
            int res = target - nums[i];
            auto it = num_id.find(res);
            if(it != num_id.end()) return vector<int>{it->second, i};
            num_id[ nums[i] ] = i;
            */
        }
        return vector<int>();
    }
};
