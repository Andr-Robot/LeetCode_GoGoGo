/*
 * Author: robot
 * Source : https://leetcode.cn/problems/queue-reconstruction-by-height/
 */
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
   public:
    static bool cmp(const vector<int> &p1, const vector<int> &p2) { 
        if (p1[0] == p2[0]) {
            return p1[1] < p2[1];
        }
        return p1[0] > p2[0];
    }
    // 使用vector，vector的底层实现是线性表，insert操作的时候如果需要扩容，则会申请新的地址，并迁移原数组的值，比较耗时
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp); // 身高h逆序排列，前面高的值k升序排列
        vector<vector<int>> res;
        for (size_t i = 0; i < people.size(); i++) {
            int idx = people[i][1];
            res.insert(res.begin() + idx, people[i]);
        }
        return res;
    }
    // 使用list，list的底层实现是链表
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);  // 身高h逆序排列，前面高的值k升序排列
        list<vector<int>> res;
        for (size_t i = 0; i < people.size(); i++) {
            int idx = people[i][1];
            auto iter = res.begin();
            while (idx > 0) {
                iter++;
                idx--;
            }
            res.insert(iter, people[i]);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};