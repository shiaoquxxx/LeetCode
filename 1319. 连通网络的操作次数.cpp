// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/23.
// https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        MergeFindSet merge_find_set(n); // LEETCODE.H

        for (auto &connection: connections) {
            merge_find_set.merge(connection[0], connection[1]);
        }

        return merge_find_set.get_amount_of_disjoint_roots() - 1;
    }
};
