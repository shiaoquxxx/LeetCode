// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/13.
// https://leetcode-cn.com/problems/redundant-connection/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        MergeFindSet mfs(edges.size() + 1); // LEETCODE.H

        vector<int> redundant_connection;

        for (auto &edge: edges) {
            if (mfs.find(edge[0]) == mfs.find(edge[1])) {
                redundant_connection = edge;
                break;
            }

            mfs.merge(edge[0], edge[1]);
        }

        return redundant_connection;
    }
};
