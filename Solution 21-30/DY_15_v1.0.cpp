/*15. 3Sum
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:The solution set must not contain duplicate triplets.*/

//Runtime: 100 ms, faster than 94.96% of C++ online submissions for 3Sum.
//Memory Usage: 15.6 MB, less than 97.70% of C++ online submissions for 3Sum.
//˼·���Ƚ������������ȹ̶���һ����(i)��ֵ���ڶ���(front)�͵�������(back)��ֵ�ɱ䣬���������ĺ͵��ڵ�һ�������෴������ΪĿ��ֵ��
//�����2���ʹ���Ŀ��ֵ����front��Ҫ��󣬼������ƶ���С��Ŀ��ֵ��back�����ƶ���ֱ���������3��������vectorȻ��push��result��
//�ж��ظ���front��vector[1]�Ƚϣ���������ƣ�back��vector[2]�Ƚϣ���������ƣ�i��i+1��ֵ�Ƚϣ���������ơ�

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int front = i+1;
            int back = nums.size()-1;

            while (front < back) {
                int sum = nums[front] + nums[back];

                if (sum < target) {
                    front++;
                }
                else if (sum > target) {
                    back--;
                }
                else {
                    vector triplet(3,0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);

                    //�����2�������ܳ��ֵ��ظ����
                    while (front < back && nums[front] == triplet[1]) front++;

                    while (front < back && nums[back] == triplet[2]) back--;
                }
            }
            while (i < nums.size()-1 && nums[i+1] == nums[i])   i++;
        }
        return res;
    }
};
