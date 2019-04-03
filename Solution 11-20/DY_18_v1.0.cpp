/*
18. 4Sum
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums
such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.
*/

//Runtime: 28 ms, faster than 83.62% of C++ online submissions for 4Sum.
//Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for 4Sum.
//思路：与3Sum的思路相同，先将数组排序，然后固定前2个值，移动后2个值的位置。
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)    return vector<vector<int>>();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size()-3; i++) {
            for (int j = i+1; j < nums.size()-2; j++) {
                int t = target-nums[i]-nums[j];
                int begin = j+1, end = nums.size()-1;
                while (begin < end) {
                    int sum = nums[begin] + nums[end];
                    if (sum < t)
                        begin++;
                    else if (sum > t)
                        end--;
                    else {
                        vector<int> v(4,0);
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[begin];
                        v[3] = nums[end];
                        res.push_back(v);

                        while (begin < end && nums[begin] == v[2]) begin++;
                        while (begin < end && nums[end] == v[3]) end--;
                    }
                }
                while (j<nums.size()-2 && nums[j+1]==nums[j]) j++;
            }
            while (i<nums.size()-3 && nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};
