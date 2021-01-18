// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/15.
// https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        MergeFindSet merge_find_set(20002); // LEETCODE.H

        for (auto &stone: stones) {
            merge_find_set.merge(stone[0], stone[1] + 10001);
        }

        unordered_map<int, int> id_of_connected_components;
        int amount_of_connected_components = 0;

        for (auto &stone: stones) {
            int id_of_connected_component = merge_find_set.find(stone[0]);

            if (id_of_connected_components.find(id_of_connected_component) == id_of_connected_components.end()) {
                id_of_connected_components[id_of_connected_component] = amount_of_connected_components++;
            }
        }

        return stones.size() - amount_of_connected_components;
    }
};
