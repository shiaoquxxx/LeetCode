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

        return stones.size() - merge_find_set.count();
    }
};
