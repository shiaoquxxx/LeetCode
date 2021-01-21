// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/21.
// https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
        int amount_of_edges = edges.size();

        for (int i = 0; i < amount_of_edges; ++i) {
            edges[i].emplace_back(i);
        }

        sort(edges.begin(), edges.end(), [](const auto &lhs, const auto &rhs) {
            return lhs[2] < rhs[2];
        });

        MergeFindSet merge_find_set_for_mst(n);
        int weight_of_mst = 0;

        for (int i = 0; i < amount_of_edges; ++i) {
            if (merge_find_set_for_mst.find(edges[i][0]) != merge_find_set_for_mst.find(edges[i][1])) {
                merge_find_set_for_mst.merge(edges[i][0], edges[i][1]);
                weight_of_mst += edges[i][2];
            }
        }

        vector<vector<int>> answer(2);
        int weight_of_current_tree = 0;

        for (int i = 0; i < amount_of_edges; ++i) {
            MergeFindSet merge_find_set_for_critical_edges(n);
            weight_of_current_tree = 0;

            for (int j = 0; j < amount_of_edges; ++j) {
                if (i != j && merge_find_set_for_critical_edges.find(edges[j][0]) != merge_find_set_for_critical_edges.find(edges[j][1])) {
                    merge_find_set_for_critical_edges.merge(edges[j][0], edges[j][1]);
                    weight_of_current_tree += edges[j][2];
                }
            }

            if (merge_find_set_for_critical_edges.get_rank(0) != n || weight_of_current_tree > weight_of_mst) {
                answer[0].emplace_back(edges[i][3]);
                continue;
            }

            MergeFindSet merge_find_set_for_pseudo_critical_edges(n);
            weight_of_current_tree = 0;

            merge_find_set_for_pseudo_critical_edges.merge(edges[i][0], edges[i][1]);
            weight_of_current_tree = edges[i][2];

            for (int j = 0; j < amount_of_edges; ++j) {
                if (i != j && merge_find_set_for_pseudo_critical_edges.find(edges[j][0]) != merge_find_set_for_pseudo_critical_edges.find(edges[j][1])) {
                    merge_find_set_for_pseudo_critical_edges.merge(edges[j][0], edges[j][1]);
                    weight_of_current_tree += edges[j][2];
                }
            }

            if (weight_of_current_tree == weight_of_mst) {
                answer[1].emplace_back(edges[i][3]);
            }
        }

        return answer;
    }
};

// TODO: rewrite solution (Tarjan)
