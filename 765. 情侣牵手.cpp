// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/14.
// https://leetcode-cn.com/problems/couples-holding-hands/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        MergeFindSet merge_find_set(row.size()); // LEETCODE.H

        for (int i = 0; i < row.size() - 1; i += 2) {
            merge_find_set.merge(row[i] / 2, row[i + 1] / 2);
        }

        merge_find_set.get_number_of_different_roots();

        int answer = 0;

        for (auto &[key, value]: merge_find_set.roots) {
            answer += value - 1;
        }

        return answer;
    }
};
