/*
 * Author: robot
 * Source : https://leetcode.cn/problems/number-of-islands/
 */
#include <iostream>
#include <vector>
using namespace std;

// 岛屿数量
// 通过深度优先搜索来解决，为了避免重复递归，可以将递归过得格子设置为已访问。
class Solution {
   private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        // 判断是否越界
        bool is_ok = (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size());
        if (!is_ok) return;
        // 非陆地直接返回
        if (grid[r][c] != '1') return;
        // 将访问过的陆地标识为【已访问】
        grid[r][c] = '2';
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                if ('1' == grid[i][j]) {
                    // 遇到陆地，则统计数量，并向四周搜索
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};