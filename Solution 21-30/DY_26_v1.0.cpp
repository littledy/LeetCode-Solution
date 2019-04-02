/*
26. Remove Duplicates from Sorted Array
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/
//Runtime: 24 ms, faster than 99.09% of C++ online submissions for Remove Duplicates from Sorted Array.
//Memory Usage: 9.9 MB, less than 99.34% of C++ online submissions for Remove Duplicates from Sorted Array.
//Note: ��������ֵn-count������ȻΪint������������Ϊ����ȥ�غ��nums��ǰn-countֵ����Ȼ������©����ֱ��ͳ��nums�еĲ��ظ�Ԫ�ظ����ˡ�
//˼·��countͳ�������ظ��ĸ�������nums[i]����ǰһ��ֵ����ȣ�Ϊ��i-count�����ظ���ֵ����n-countΪ���в��ظ�Ԫ�صĸ�����

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
