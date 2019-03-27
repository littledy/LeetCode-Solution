//思路：首先建立一个无序表num_id保存输入数组nums，无序表中的每个元素有2个值，
//第一个是key，第二个是value，可以通过key快速索引到value，在这题对应的就是数组下
//标为Key,对应的元素值为value，注意每个元素只能利用一次，所以要避免数组值重复利用。
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //无序表，第一个是key，第二个是value，可以通过key快速索引到value
        unordered_map<int,int> num_id;
        //将nums的值赋给num_id
        for (int i = 0; i < nums.size(); i++)
        {
            num_id[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int res = target - nums[i];

            //如果res在num.id中，返回指向res的迭代器，非空，返回num_id.end()
            auto it = num_id.find(res);

            //确保nums的值未被重复使用
            if (it != num_id.end() && i!=it->second) return vector<int>{i,it->second};

            /*第二种思路，不需要先创建num_id保存输入数组，判断不存在则加入num_id，可
            保证不重复，i在it->second后面遍历，所以顺序是it->second,i;
            int res = target - nums[i];
            auto it = num_id.find(res);
            if(it != num_id.end()) return vector<int>{it->second, i};
            num_id[ nums[i] ] = i;
            */
        }
        return vector<int>();
    }
};
