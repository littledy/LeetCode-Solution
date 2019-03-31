/*11. Container With Most Water
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.*/

//思路：容器面积的最大值总是在2端取到，因此想要面积最大，则两端的高度更高，每次更新两端中较小的高度。
//Runtime: 20 ms, faster than 98.37% of C++ online submissions for Container With Most Water.
//Memory Usage: 9.7 MB, less than 99.86% of C++ online submissions for Container With Most Water.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size()-1;
        while (i < j) {
            water = max(water, min(height[i],height[j])*(j-i));
            height[i] > height[j] ? j--:i++;
        }
        return water;
    }
};
