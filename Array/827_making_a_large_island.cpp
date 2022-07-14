/*
 * Author: robot
 * Source : https://leetcode.cn/problems/making-a-large-island/
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 最大人工岛
// 1. 通过dfs去统计每块岛屿的面积，并将面积缓存下来
// 2. 遍历海洋，找到相邻陆地面积最大的海洋格子
class Solution {
   private:
    bool check(vector<vector<int>>& grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
    int dfsIsland(vector<vector<int>>& grid, int r, int c, int index) {
        if (!check(grid, r, c)) return 0;
        if (grid[r][c] != 1) return 0;
        grid[r][c] = index;
        return 1 + dfsIsland(grid, r, c + 1, index) + dfsIsland(grid, r, c - 1, index) +
               dfsIsland(grid, r + 1, c, index) + dfsIsland(grid, r - 1, c, index);
    }
    int searchSea(vector<vector<int>>& grid, int r, int c, const unordered_map<int, int>& island_area) {
        if (!check(grid, r, c)) return 0;
        if (grid[r][c] != 0) return 0;
        unordered_set<int> use_island;
        if (check(grid, r, c + 1) && grid[r][c + 1] >= 2) {
            use_island.insert(grid[r][c + 1]);
        }
        if (check(grid, r, c - 1) && grid[r][c - 1] >= 2) {
            use_island.insert(grid[r][c - 1]);
        }
        if (check(grid, r + 1, c) && grid[r + 1][c] >= 2) {
            use_island.insert(grid[r + 1][c]);
        }
        if (check(grid, r - 1, c) && grid[r - 1][c] >= 2) {
            use_island.insert(grid[r - 1][c]);
        }
        int res = 0;
        for (auto iter = use_island.begin(); iter != use_island.end(); iter++) {
            res += island_area.find(*iter)->second;
        }
        res++;  // 海洋变陆地
        return res;
    }

   public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> island_area;
        int index = 2;  // 从2开始，避免和0、1混淆
        int res = 0;    // 保存最大的陆地面积
        // 遍历陆地
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                if (1 == grid[i][j]) {
                    int area = dfsIsland(grid, i, j, index);
                    island_area[index] = area;
                    res = max(res, area);
                    index++;
                }
            }
        }
        // 遍历海洋
        int new_area = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                if (0 == grid[i][j]) {
                    int area = searchSea(grid, i, j, island_area);
                    new_area = max(new_area, area);
                }
            }
        }
        // 可能都没有海洋，全是陆地，则再次判断，直接返回陆地最大值
        res = max(res, new_area);
        return res;
    }
};