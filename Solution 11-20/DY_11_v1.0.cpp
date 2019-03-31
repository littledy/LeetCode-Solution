/*11. Container With Most Water
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.*/

//Runtime: 1192 ms, faster than 22.21% of C++ online submissions for Container With Most Water.
//Memory Usage: 9.8 MB, less than 99.17% of C++ online submissions for Container With Most Water.
//笨比算法。果然思路越简单，运算就越复杂。

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        //int water = 0;
        for (int i = 0; i < height.size(); i++) {
            int area = 0;
            for (int j = i; j < height.size(); j++) {
                //water = max(water,(j-i) * min(height[i], height[j])); 这行代码运行超时，不可行
                area = (j-i) * min(height[i],height[j]);
                if (area > max_area) max_area = area;
            }
        }
        return max_area;
    }
};
