/*
 * Author: robot
 * Source : https://leetcode.cn/problems/gas-station/
 */
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // O(n^2) 暴力法
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (size_t i = 0; i < gas.size(); i++) {
            int rest = gas[i] - cost[i];
            int index = (i + 1) % gas.size();
            // 当前剩余油量大于0，则进行模拟看是否可以跑一圈，此时起点是i
            while (rest > 0 && index != i) {
                rest += gas[index] - cost[index];
                index = (index + 1) % gas.size();
            }
            // 如果跑完一圈后，rest >= 0，则认为成立
            if (rest >= 0 && index == i) {
                return i;
            }
        }
        return -1;
    }
    // O(n) 贪心法
    // 如果gas的总和小于cost总和，那么无论从哪里出发，一定是跑不了一圈的
    // i从0开始，如果算出最终差值的和大于等于0，则说明从0开始可以跑完一圈
    // 如果累加的最小值是负数，汽车就要从非0节点出发，从后向前，看哪个节点能这个负数填平，能把这个负数填平的节点就是出发节点。
    int canCompleteCircuit_v2(vector<int>& gas, vector<int>& cost) {
        int cursum = 0;
        int min = INT_MAX; // 从起点出发油箱里的油量最小值
        for (size_t i = 0; i < gas.size(); i++) {
            int rest = gas[i] - cost[i];
            cursum += rest;
            if (cursum < min) {
                min = cursum;
            }
        }
        if (cursum < 0) {
            return -1;
        }
        if (min >= 0) {
            return 0;
        }
        for (size_t i = gas.size() - 1; i >= 0; i--) {
            int rest = gas[i] - cost[i];
            min += rest;
            if (min >= 0) {
                return i;
            }
        }
        return -1;
    }
    // O(n) 贪心法
    int canCompleteCircuit_v3(vector<int>& gas, vector<int>& cost) {
        int cur_sum = 0;
        int total_sum = 0;
        int res = 0;
        for (size_t i = 0; i < gas.size(); i++) {
            int rest = gas[i] - cost[i];
            total_sum += rest;
            cur_sum += rest;
            if (cur_sum < 0) { // 必须将加和大于等于0的地方作为起点
                res = i + 1;
                cur_sum = 0;
            }
        }
        if (total_sum < 0) { // gas 和 cost的差值和必须大于等于0
            return -1;
        }
        return res;
    }
};