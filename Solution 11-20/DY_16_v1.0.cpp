/*
16. 3Sum Closest
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.
*/

//Runtime: 8 ms, faster than 100.00% of C++ online submissions for 3Sum Closest.
//Memory Usage: 8.8 MB, less than 98.61% of C++ online submissions for 3Sum Closest.
//˼·�����15�����ƣ�Ҳ���Ƚ�������࣬Ȼ��̶���һ�������ڶ������͵������������ƶ����������֮�ʹ���target���ڶ���������ƶ���С�������������ǰ
//�ƶ���ÿ�αȽ�target�����������͵�ǰ��target��ӽ���ֵ�Ĳ�ֵ����abs()�Ƚϡ�

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)    return 0;
        sort(nums.begin(),nums.end());
        int closest = nums[0]+nums[1]+nums[2];
        for (int i = 0; i < nums.size()-2; i++) {
            if (i>0 && nums[i]==nums[i-1])  continue;
            int begin = i+1, end = nums.size()-1;
            while (begin < end) {
                int sum = nums[i]+nums[begin]+nums[end];
                if (sum == target)  return sum;
                if (abs(target-sum) < abs(target-closest))
                    closest = sum;
                if (sum > target)
                    end--;
                else
                    begin++;
            }
        }
        return closest;
    }
};
