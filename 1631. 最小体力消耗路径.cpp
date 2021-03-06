// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/29.
// https://leetcode-cn.com/problems/path-with-minimum-effort/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"


class Solution {
public:
    struct Edge {
        int source;
        int destination;
        int distance;

        explicit Edge(int source, int destination, vector<vector<int>> &heights)
            : source(source), destination(destination) {
            int n = heights[0].size();
            int source_x = source / n;
            int source_y = source % n;
            int destination_x = destination / n;
            int destination_y = destination % n;

            distance = abs(heights[destination_x][destination_y] - heights[source_x][source_y]);
        }

        bool operator<(const Edge &e) const {
            return distance > e.distance;
        }
    };

    int minimumEffortPath(vector<vector<int>> &heights) {
        int n = heights[0].size();
        priority_queue<Edge> priority_queue;

        for (int i = 0; i < heights.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                int id_of_cell = i * n + j;

                if (i + 1 < heights.size()) {
                    int id_of_cell_at_the_bottom = (i + 1) * n + j;

                    priority_queue.emplace(Edge(id_of_cell, id_of_cell_at_the_bottom, heights));
                }

                if (j + 1 < n) {
                    int id_of_cell_on_the_right = i * n + (j + 1);

                    priority_queue.emplace(Edge(id_of_cell, id_of_cell_on_the_right, heights));
                }
            }
        }

        MergeFindSet merge_find_set(heights.size() * n); // LEETCODE.H
        int answer = 0;

        while (!priority_queue.empty() && merge_find_set.find(0) != merge_find_set.find((heights.size() - 1) * n + (n - 1))) {
            Edge e = priority_queue.top();

            priority_queue.pop();

            merge_find_set.merge(e.source, e.destination);
            answer = e.distance;
        }

        return answer;
    }
};
