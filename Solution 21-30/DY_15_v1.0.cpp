/*15. 3Sum
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:The solution set must not contain duplicate triplets.*/

//Runtime: 100 ms, faster than 94.96% of C++ online submissions for 3Sum.
//Memory Usage: 15.6 MB, less than 97.70% of C++ online submissions for 3Sum.
//思路：先将数组排序。首先固定第一个数(i)的值，第二个(front)和第三个数(back)的值可变，且这两数的和等于第一个数的相反数，设为目标值。
//如果这2数和大于目标值，则front需要变大，即向右移动，小于目标值则back向左移动。直到相等则将这3个数存入vector然后push进result。
//判断重复：front与vector[1]比较，相等则右移，back与vector[2]比较，相等则左移，i与i+1的值比较，相等则右移。

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

                    //处理第2个数可能出现的重复情况
                    while (front < back && nums[front] == triplet[1]) front++;

                    while (front < back && nums[back] == triplet[2]) back--;
                }
            }
            while (i < nums.size()-1 && nums[i+1] == nums[i])   i++;
        }
        return res;
    }
};
