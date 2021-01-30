// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/19.
// https://leetcode-cn.com/problems/min-cost-to-connect-all-points/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    struct Edge {
        int source;
        int destination;
        int distance;

        explicit Edge(int source, int destination, vector<vector<int>> &points)
            : source(source), destination(destination) {
            distance = abs(points[source][0] - points[destination][0]) + abs(points[source][1] - points[destination][1]);
        }

        bool operator<(const Edge &e) const {
            return distance > e.distance;
        }
    };

    int minCostConnectPoints(vector<vector<int>> &points) {
        priority_queue<Edge> priority_queue;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                priority_queue.emplace(Edge(i, j, points));
            }
        }

        MergeFindSet merge_find_set(points.size());

        int minimum_cost = 0;

        while (merge_find_set.get_rank(0) != points.size()) {
            Edge edge = priority_queue.top();

            priority_queue.pop();

            if (merge_find_set.find(edge.source) == merge_find_set.find(edge.destination)) {
                continue;
            }

            merge_find_set.merge(edge.source, edge.destination);
            minimum_cost += edge.distance;
        }

        return minimum_cost;
    }
};
