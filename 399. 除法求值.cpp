// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/6.
// https://leetcode-cn.com/problems/evaluate-division/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        unordered_map<string, int> id_of_numbers;
        int number_of_numbers = 0;

        for (int i = 0; i < equations.size(); ++i) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];

            if (id_of_numbers.find(dividend) == id_of_numbers.end()) {
                id_of_numbers[dividend] = number_of_numbers++;
            }

            if (id_of_numbers.find(divisor) == id_of_numbers.end()) {
                id_of_numbers[divisor] = number_of_numbers++;
            }
        }

        vector<vector<double>> graph(number_of_numbers, vector<double>(number_of_numbers, -1.0));

        for (int i = 0; i < equations.size(); ++i) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            int id_of_dividend = id_of_numbers[dividend];
            int id_of_divisor = id_of_numbers[divisor];

            graph[id_of_dividend][id_of_divisor] = values[i];
            graph[id_of_divisor][id_of_dividend] = 1 / values[i];
        }

        for (int k = 0; k < number_of_numbers; ++k) {
            for (int i = 0; i < number_of_numbers; ++i) {
                for (int j = 0; j < number_of_numbers; ++j) {
                    if (graph[i][k] > 0 && graph[k][j] > 0) {
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }

        vector<double> query_results;

        for (auto &query: queries) {
            double query_result = -1.0;
            string dividend = query[0];
            string divisor = query[1];

            if (id_of_numbers.find(dividend) != id_of_numbers.end() && id_of_numbers.find(divisor) != id_of_numbers.end()) {
                int id_of_dividend = id_of_numbers[dividend];
                int id_of_divisor = id_of_numbers[divisor];

                if (graph[id_of_dividend][id_of_divisor] > 0) {
                    query_result = graph[id_of_dividend][id_of_divisor];
                }
            }

            query_results.emplace_back(query_result);
        }

        return query_results;
    }
};
