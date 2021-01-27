// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/27.
// https://leetcode-cn.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), [](const auto &lhs, const auto &rhs) {
            return lhs[0] > rhs[0];
        });

        MergeFindSet merge_find_set_for_alice(n); // LEETCODE.H
        MergeFindSet merge_find_set_for_bob(n); // LEETCODE.H

        int amount_of_edges_to_remove = 0;

        for (auto &edge: edges) {
            if (edge[0] == 1) {
                if (merge_find_set_for_alice.find(edge[1] - 1) == merge_find_set_for_alice.find(edge[2] - 1)) {
                    ++amount_of_edges_to_remove;
                }
                else {
                    merge_find_set_for_alice.merge(edge[1] - 1, edge[2] - 1);
                }
            }
            else if (edge[0] == 2) {
                if (merge_find_set_for_bob.find(edge[1] - 1) == merge_find_set_for_bob.find(edge[2] - 1)) {
                    ++amount_of_edges_to_remove;
                }
                else {
                    merge_find_set_for_bob.merge(edge[1] - 1, edge[2] - 1);
                }
            }
            else if (edge[0] == 3) {
                if (merge_find_set_for_alice.find(edge[1] - 1) == merge_find_set_for_alice.find(edge[2] - 1) && merge_find_set_for_bob.find(edge[1] - 1) == merge_find_set_for_bob.find(edge[2] - 1)) {
                    ++amount_of_edges_to_remove;
                }
                else {
                    merge_find_set_for_alice.merge(edge[1] - 1, edge[2] - 1);
                    merge_find_set_for_bob.merge(edge[1] - 1, edge[2] - 1);
                }
            }
        }

        if (merge_find_set_for_alice.get_amount_of_disjoint_roots() != 1) {
            return -1;
        }

        if (merge_find_set_for_bob.get_amount_of_disjoint_roots() != 1) {
            return -1;
        }

        return amount_of_edges_to_remove;
    }
};
