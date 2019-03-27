//��2���ź��������ϲ�Ϊһ���ź�������飬���ù鲢�㷨��ԭ��ÿ�δ�2��������ȡ����С��������
//���������飬ֱ��2�������Ϊ��

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        size_t i(0), j(0);

        //��nums1��nums2���ǿ�ʱ
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

        //��ʱnums2Ϊ�գ���nums1ʣ�µ�ֵpush��nums3
        while (i < nums1.size())
        {
            nums3.push_back(nums1[i++]);
            //nums3.push_back(nums1[i]);
            //i++;
        }

        //��ʱnums1Ϊ�գ���nums2ʣ�µ�ֵpush��nums3
        while (j < nums2.size())
        {
            nums3.push_back(nums2[j++]);
            //nums3.push_back(nums2[j]);
            //j++;
        }

        //nums3����Ϊż��������м�2������ƽ��ֵ��Ϊ��������м�ֵ��/2.0ת��Ϊdouble��
        if (nums3.size()%2 != 0)
            return nums3[nums3.size()/2];
        else
            return (nums3[nums3.size()/2] + nums3[nums3.size()/2-1])/2.0;
    }
};
