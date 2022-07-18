/*
 * Author: robot
 * Source : https://leetcode.cn/problems/next-permutation/
 */
#include <iostream>
#include <vector>
using namespace std;

// 下一个排列
class Solution {
   public:
    // 因为需要找到大于当前排列的最小的排列，所以这里得从地位开始搜索，假设总长为n
    // 1. 由于降序的地方调换顺序只会使数值变小，所以我们得找到第一个升序的地方i
    // 2. 为了得到【最小】，那么就需要在[i + 1, n)中搜索第一个大于a[i]的数和a[i]进行调换
    // 3. 为了保持最小，则还需要让[i + 1, n)保持升序，由于本身是降序的，所以只需要调用reverse函数即可
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // 从右向左寻找第一个升序的位置
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= i && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};