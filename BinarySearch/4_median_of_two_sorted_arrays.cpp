/*
 * Author: robot
 * Source : https://leetcode.cn/problems/median-of-two-sorted-arrays/
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 寻找两个正序数组的中位数
 *
 */
class Solution {
   private:
    // 寻找第k小的位置
    double findKthNum(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        // 两个指针，记录起始位置
        int index1 = 0;
        int index2 = 0;
        while (true) {
            // 只剩一个数组，则可以在一个数组中找到第k个数字
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            // 如果 k=1，则返回两个数组首元素的最小值
            if (1 == k) {
                return min(nums1[index1], nums2[index2]);
            }
            // 分别找到两个数组的第k/2小的位置，需要防止越界
            int new_index1 = min(index1 + k / 2 - 1, m - 1);
            int new_index2 = min(index2 + k / 2 - 1, n - 1);
            int n1 = nums1[new_index1];
            int n2 = nums2[new_index2];
            if (n1 <= n2) {
                // nums1中[index1,new_index1]之间不存在第k个数，直接过滤
                k -= new_index1 - index1 + 1;
                index1 = new_index1 + 1;
            } else {
                // nums2中[index2,new_index2]之间不存在第k个数，直接过滤
                k -= new_index2 - index2 + 1;
                index2 = new_index2 + 1;
            }
        }
    }

   public:
    // 二分法的思想：一个正序数组的中位数，就是该数组第k小的数。将该数组拆成2个正序数组，就是分别在2个数组中寻找第k/2个数。
    // 如果数组a的第k/2个数，小于数组b的第k/2个数，那么数组a中从开始位置到第k/2的位置的这部分数，可以排除掉，中位数一定不在这些数中
    // 因为，假设中位数在这些数中，最极端的情况就是a的第k/2个数就是中位数，那么数组b的前k/2个数，都应该小于它。
    // 但实际上b的第k/2个数，是大于a的第k/2个数的，所以假设不成立
    // 所以，第k/2个数较小的一方，中位数一定不在它那里。
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int len = m + n;
        if (len % 2 == 0) {
            return (findKthNum(nums1, nums2, len / 2) + findKthNum(nums1, nums2, len / 2 + 1)) / 2.0;
        } else {
            return findKthNum(nums1, nums2, len / 2 + 1);
        }
    }
};