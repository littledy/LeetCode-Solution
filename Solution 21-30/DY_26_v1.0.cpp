/*
26. Remove Duplicates from Sorted Array
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/
//Runtime: 24 ms, faster than 99.09% of C++ online submissions for Remove Duplicates from Sorted Array.
//Memory Usage: 9.9 MB, less than 99.34% of C++ online submissions for Remove Duplicates from Sorted Array.
//Note: 函数返回值n-count类型虽然为int，但程序的输出为经过去重后的nums的前n-count值，不然可能钻漏洞，直接统计nums中的不重复元素个数了。
//思路：count统计所有重复的个数，则nums[i]（与前一个值不相等）为第i-count个不重复的值，而n-count为所有不重复元素的个数。

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1])   count++;
            else nums[i-count] = nums[i];
        }
        return nums.size()-count;
    }
};
