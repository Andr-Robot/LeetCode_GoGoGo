/*
 * Author: robot
 * Source : https://leetcode.cn/problems/island-perimeter/
 */
#include <iostream>
#include <vector>
using namespace std;

// 岛屿周长
// 使用深度优先遍历，递归的时候返回值是格子的边长，最终将所有的边长累加就可以得到周长
// 格子的周长主要有两部分组成：
//  1. 陆地格子在边缘【此时会越界】，周长+1
//  2. 陆地格子和海洋格子相邻，周长+1
class Solution {
   private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        bool is_ok = (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size());
        // 越界，此时会有一条边需要被算入周长
        if (!is_ok) return 1;
        // 遇到海洋，此时会有一条边需要被算入周长
        if (0 == grid[r][c]) return 1;
        // 遇到访问过的陆地，不需要算入周长
        if (2 == grid[r][c]) return 0;
        grid[r][c] = 2;
        // 将四周遍历的结果累加
        return dfs(grid, r - 1, c) + dfs(grid, r + 1, c) + dfs(grid, r, c - 1) + dfs(grid, r, c + 1);
    }

   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                if (1 == grid[i][j]) {
                    res += dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};