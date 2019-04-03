/*
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

//Runtime: 8 ms, faster than 99.93% of C++ online submissions for Two Sum.
//Memory Usage: 9.3 MB, less than 94.38% of C++ online submissions for Two Sum.
//思路：先用一个数组保存输入数组数组，对输入数组排序，然后首尾两端向中间移动，如果存在解，则找出目标值对应的原数组的下标（防止重复），
//若无则返回空vector

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return vector<int>();
        vector<int> num,res;
        num = nums;
        sort(nums.begin(),nums.end());
        int begin = 0, end = nums.size()-1;
        while (begin < end) {
            int sum = nums[begin] + nums[end];
            if (sum < target) begin++;
            else if (sum > target)  end--;
            else {
                for (int i=0; i<num.size(); i++){
                    if (num[i] == nums[begin]) {
                        res.push_back(i);
                        break;
                    }
                }
                for (int i=0; i<num.size(); i++){
                    if (num[i] == nums[end] && i!=res[0]) {
                        res.push_back(i);
                        break;
                    }
                }
                return res;
            }
        }
        return res;
    }
};
