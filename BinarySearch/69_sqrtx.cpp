/*
 * Author: robot
 * Source : https://leetcode.cn/problems/sqrtx/
 */
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int s = 1;
        int e = x / 2;
        while (s <= e) {
            long mid = (s + e) / 2;
            // 判断是否可以提前退出
            long long val = mid * mid;
            long long val1 = (mid + 1) * (mid + 1);
            if (val < x && val1 > x) {
                return mid;
            }
            // 正常的二分查找
            if (val > x) {
                e = mid - 1;
            } else if (val < x) {
                s = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
