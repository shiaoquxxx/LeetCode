// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/7.
// https://leetcode-cn.com/problems/number-of-provinces/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        vector<int> visited(isConnected.size(), 0);
        int amount_of_provinces = 0;

        for (int i = 0; i < isConnected.size(); ++i) {
            if (dfs(isConnected, visited, i)) {
                ++amount_of_provinces;
            }
        }

        return amount_of_provinces;
    }

    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int city) {
        if (visited[city]) {
            return false;
        }

        visited[city] = 1;

        for (int i = 0; i < graph.size(); ++i) {
            if (!graph[city][i]) {
                continue;
            }

            if (!visited[i]) {
                dfs(graph, visited, i);
            }
        }

        return true;
    }
};
