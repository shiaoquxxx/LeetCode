// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/25.
// https://leetcode-cn.com/problems/regions-cut-by-slashes/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int regionsBySlashes(vector<string> &grid) {
        int n = grid.size();

        MergeFindSet merge_find_set(4 * n * n); // LEETCODE.H

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int id_of_cell = i * n + j;

                switch (grid[i][j]) {
                    case ' ':
                        merge_find_set.merge(4 * id_of_cell + 0, 4 * id_of_cell + 1);
                        merge_find_set.merge(4 * id_of_cell + 1, 4 * id_of_cell + 2);
                        merge_find_set.merge(4 * id_of_cell + 2, 4 * id_of_cell + 3);
                        break;
                    case '/':
                        merge_find_set.merge(4 * id_of_cell + 0, 4 * id_of_cell + 3);
                        merge_find_set.merge(4 * id_of_cell + 1, 4 * id_of_cell + 2);
                        break;
                    case '\\':
                        merge_find_set.merge(4 * id_of_cell + 0, 4 * id_of_cell + 1);
                        merge_find_set.merge(4 * id_of_cell + 2, 4 * id_of_cell + 3);
                        break;
                    default:
                        break;
                }

                if (i + 1 < n) {
                    int id_of_cell_at_the_bottom = (i + 1) * n + j;
                    merge_find_set.merge(4 * id_of_cell + 2, 4 * id_of_cell_at_the_bottom + 0);
                }

                if (j + 1 < n) {
                    int id_of_cell_on_the_right = i * n + (j + 1);
                    merge_find_set.merge(4 * id_of_cell + 1, 4 * id_of_cell_on_the_right + 3);
                }
            }
        }

        unordered_set<int> id_of_connected_components;

        for (int i = 0; i < 4 * n * n; ++i) {
            id_of_connected_components.emplace(merge_find_set.find(i));
        }

        return id_of_connected_components.size();
    }
};
