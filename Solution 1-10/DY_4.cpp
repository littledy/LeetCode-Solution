//将2个排好序的数组合并为一个排好序的数组，利用归并算法的原理，每次从2个数组中取出最小的数放入
//第三个数组，直至2个数组均为空

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        size_t i(0), j(0);

        //当nums1和nums2均非空时
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                nums3.push_back(nums1[i++]);
                //nums3.push_back(nums1[i]);
                //i++;
            }
            else
            {
                nums3.push_back(nums2[j++]);
                //nums3.push_back(nums2[j]);
                //j++;
            }
        }

        //此时nums2为空，把nums1剩下的值push进nums3
        while (i < nums1.size())
        {
            nums3.push_back(nums1[i++]);
            //nums3.push_back(nums1[i]);
            //i++;
        }

        //此时nums1为空，把nums2剩下的值push进nums3
        while (j < nums2.size())
        {
            nums3.push_back(nums2[j++]);
            //nums3.push_back(nums2[j]);
            //j++;
        }

        //nums3长度为偶数，输出中间2个数的平均值，为奇数输出中间值，/2.0转化为double型
        if (nums3.size()%2 != 0)
            return nums3[nums3.size()/2];
        else
            return (nums3[nums3.size()/2] + nums3[nums3.size()/2-1])/2.0;
    }
};
