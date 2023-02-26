/*
 * Author: robot
 * Source : https://leetcode.cn/problems/sliding-window-maximum
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 使用优先队列来保存窗口内的数字，由于需要取出窗口内的最大值，则需要采用大顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for (int i = 0; i < k; i++) {
            pq.push(pair<int, int>(nums[i], i));
        }
        vector<int> res;
        res.push_back(pq.top().first);
        for (int i = k; i < nums.size(); i++) {
            pq.push(pair<int, int>(nums[i], i));
            // 大顶堆的顶部如果不在滑动窗口内，则删除
            while (pq.top().second <= i - k) {
                pq.pop();
            }
            res.push_back(pq.top().first);
        }
        return res;
    }
};