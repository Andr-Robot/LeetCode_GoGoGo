/*
 * Author: robot
 * Source : https://leetcode.cn/problems/max-area-of-island/
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        bool is_ok = (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size());
        if (!is_ok) return 0;
        if (grid[r][c] != 1) return 0;
        grid[r][c] = 2;
        return 1 + dfs(grid, r, c + 1) + dfs(grid, r, c - 1) + dfs(grid, r + 1, c) + dfs(grid, r - 1, c);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                if (1 == grid[i][j]) {
                    int area = dfs(grid, i, j);
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};