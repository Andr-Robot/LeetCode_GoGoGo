/*
 * Author: robot
 * Source : https://leetcode.cn/problems/kth-largest-element-in-an-array/
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
   private:
    // 类似于快排的变种
    int quick_select(vector<int> &nums, int s, int e, int k) {
        if (s < e) {
            int l = s;
            int r = e;
            int target = nums[s];
            while (l < r) {
                while (l < r && nums[r] < target) {
                    r--;
                }
                if (l < r) {
                    nums[l] = nums[r];
                    l++;
                }
                while (l < r && nums[l] > target) {
                    l++;
                }
                if (l < r) {
                    nums[r] = nums[l];
                    r--;
                }
            }
            nums[l] = target;
            if (s < l && k < l) {
                return quick_select(nums, s, l - 1, k);
            } else if (e > l and k > l) {
                return quick_select(nums, l + 1, e, k);
            } else {
                return nums[l];
            }
        }
        return nums[s];
    }

   public:
    // 方法一：采用快速排序的方式去搜索第k个数值，逆序
    int findKthLargest(vector<int>& nums, int k) {
        // 第k大的数下标应该是k - 1
        return quick_select(nums, 0, nums.size() - 1, k - 1);
    }
    // 方法二：使用大顶堆，O(nlogn)
    int findKthLargest_v2(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> pq;  // 大顶堆
        for (size_t i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        int res = 0;
        while (k > 0) {
            res = pq.top();
            pq.pop();
            k--;
        }
        return res;
    }
};