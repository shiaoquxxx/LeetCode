// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/12.
// https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<int> TopologicalSort(vector<vector<int>> &g, vector<int> &in, vector<int> &items) {
        queue<int> q;

        for (const auto &item: items) {
            if (in[item] == 0) {
                q.push(item);
            }
        }

        vector<int> result;

        while (!q.empty()) {
            int front = q.front();

            q.pop();
            result.emplace_back(front);

            for (const auto &v: g[front]) {
                if (--in[v] == 0) {
                    q.push(v);
                }
            }
        }

        return result.size() == items.size() ? result : vector<int>();
    }

    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {
        vector<vector<int>> group_g(n + m);
        vector<vector<int>> item_g(n);
        vector<int> group_in(n + m, 0);
        vector<int> item_in(n, 0);

        vector<int> items;
        vector<vector<int>> items_of_groups(n + m);

        for (int i = 0; i < n + m; ++i) {
            items.emplace_back(i);
        }

        int next_unassigned_id = m;

        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = next_unassigned_id;
                next_unassigned_id += 1;
            }

            items_of_groups[group[i]].emplace_back(i);
        }

        for (int i = 0; i < n; ++i) {
            int current_group = group[i];

            for (auto &item: beforeItems[i]) {
                int before_group = group[item];

                if (before_group == current_group) {
                    item_in[i] += 1;
                    item_g[item].emplace_back(i);
                }
                else {
                    group_in[current_group] += 1;
                    group_g[before_group].emplace_back(current_group);
                }
            }
        }

        vector<int> sorted_groups = TopologicalSort(group_g, group_in, items);

        if (sorted_groups.size() == 0) {
            return vector<int>();
        }

        vector<int> result;

        for (auto &current_group: sorted_groups) {
            int size = items_of_groups[current_group].size();

            if (size == 0) {
                continue;
            }

            vector<int> sorted_items = TopologicalSort(item_g, item_in, items_of_groups[current_group]);

            if (sorted_items.size() == 0) {
                return vector<int>();
            }

            for (auto &item: sorted_items) {
                result.emplace_back(item);
            }
        }

        return result;
    }
};
