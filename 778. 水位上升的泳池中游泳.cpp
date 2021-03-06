// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/30.
// https://leetcode-cn.com/problems/swim-in-rising-water/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    struct Cell {
        int x;
        int y;
        int height;

        explicit Cell(int x, int y, vector<vector<int>> &heights)
            : x(x), y(y), height(heights[x][y]) {
        }

        bool operator<(const Cell &c) const {
            return height > c.height;
        }
    };

    int flatten(int x, int y, vector<vector<int>> &heights) {
        return x * heights.size() + y;
    }

    int swimInWater(vector<vector<int>> &grid) {
        priority_queue<Cell> priority_queue;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                priority_queue.emplace(Cell(i, j, grid));
            }
        }

        int n = grid.size();
        MergeFindSet merge_find_set(n * n); // LEETCODE.H
        int answer = 0;

        while (!priority_queue.empty() && merge_find_set.find(0 * n + 0) != merge_find_set.find((n - 1) * n + (n - 1))) {
            Cell c = priority_queue.top();

            priority_queue.pop();

            if (c.x - 1 >= 0 && grid[c.x - 1][c.y] <= c.height) {
                merge_find_set.merge(flatten(c.x, c.y, grid), flatten(c.x - 1, c.y, grid));
            }

            if (c.y - 1 >= 0 && grid[c.x][c.y - 1] <= c.height) {
                merge_find_set.merge(flatten(c.x, c.y, grid), flatten(c.x, c.y - 1, grid));
            }

            if (c.x + 1 < n && grid[c.x + 1][c.y] <= c.height) {
                merge_find_set.merge(flatten(c.x, c.y, grid), flatten(c.x + 1, c.y, grid));
            }

            if (c.y + 1 < n && grid[c.x][c.y + 1] <= c.height) {
                merge_find_set.merge(flatten(c.x, c.y, grid), flatten(c.x, c.y + 1, grid));
            }

            answer = c.height;
        }

        return answer;
    }
};
