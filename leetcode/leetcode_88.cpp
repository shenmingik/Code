/*
题目描述：
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。
*/

/*
思路一：合并后排序
*/
#if 0
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int j=0,i=m;j<nums2.size();i++,j++)
        {
            nums1[i]=nums2[j];
        }
        sort(nums1.begin(),nums1.end());
    }
};
#endif

/*
思路二：从尾部三指针
*/
#if 0
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int tail = m+n-1;

        while(i>=0 && j>=0)
        {
            if(nums2[j]>=nums1[i])
            {
                nums1[tail--] = nums2[j--];
            }
            else
            {
                nums1[tail--]=nums1[i--];
            }
        }
        while(j>=0) nums1[tail--] = nums2[j--];
    }
};
#endif