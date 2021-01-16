// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/16.
// https://leetcode-cn.com/problems/bricks-falling-when-hit/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int get_flatten_coordinate(int x, int y) {
        return 205 * x + y + 1;
    }

    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
        for (auto &hit: hits) {
            int x = hit[0];
            int y = hit[1];

            if (grid[x][y]) {
                grid[x][y] = 0;
            }
            else {
                grid[x][y] = -1;
            }

        }

        MergeFindSet merge_find_set(205 * 205 + 1); // LEETCODE.H

        for (int i = 0; i < grid[0].size(); ++i) {
            if (grid[0][i] > 0) {
                merge_find_set.merge(0, get_flatten_coordinate(0, i));
            }
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] <= 0) {
                    continue;
                }

                if (i + 1 < grid.size() && grid[i + 1][j] > 0) {
                    merge_find_set.merge(get_flatten_coordinate(i, j), get_flatten_coordinate(i + 1, j));
                }

                if (j + 1 < grid[0].size() && grid[i][j + 1] > 0) {
                    merge_find_set.merge(get_flatten_coordinate(i, j), get_flatten_coordinate(i, j + 1));
                }
            }
        }

        vector<int> ranks;
        ranks.emplace_back(merge_find_set.get_rank(0) - 1);

        reverse(hits.begin(), hits.end());

        for (auto &hit: hits) {
            int x = hit[0];
            int y = hit[1];

            if (grid[x][y] == 0) {
                grid[x][y] = 1;

                if (!x) {
                    merge_find_set.merge(0, get_flatten_coordinate(x, y));
                }

                if (x - 1 >= 0 && grid[x - 1][y] > 0) {
                    merge_find_set.merge(get_flatten_coordinate(x, y), get_flatten_coordinate(x - 1, y));
                }

                if (x + 1 < grid.size() && grid[x + 1][y] > 0) {
                    merge_find_set.merge(get_flatten_coordinate(x, y), get_flatten_coordinate(x + 1, y));
                }

                if (y - 1 >= 0 && grid[x][y - 1] > 0) {
                    merge_find_set.merge(get_flatten_coordinate(x, y), get_flatten_coordinate(x, y - 1));
                }

                if (y + 1 < grid[0].size() && grid[x][y + 1] > 0) {
                    merge_find_set.merge(get_flatten_coordinate(x, y), get_flatten_coordinate(x, y + 1));
                }
            }

            ranks.emplace_back(merge_find_set.get_rank(0) - 1);
        }

        reverse(ranks.begin(), ranks.end());

        vector<int> answer;

        for (int i = 1; i < ranks.size(); ++i) {
            if (ranks[i - 1] != ranks[i]) {
                answer.emplace_back(ranks[i - 1] - ranks[i] - 1);
            }
            else {
                answer.emplace_back(0);
            }
        }

        return answer;
    }
};
