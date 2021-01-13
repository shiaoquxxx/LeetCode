// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/6.
// https://leetcode-cn.com/problems/evaluate-division/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        int amount_of_numbers = 0;
        unordered_map<string, int> id_of_numbers;

        for (int i = 0; i < equations.size(); ++i) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];

            if (id_of_numbers.find(dividend) == id_of_numbers.end()) {
                id_of_numbers[dividend] = amount_of_numbers++;
            }
            if (id_of_numbers.find(divisor) == id_of_numbers.end()) {
                id_of_numbers[divisor] = amount_of_numbers++;
            }
        }

        vector<vector<double>> g(amount_of_numbers, vector<double>(amount_of_numbers, -1.0));

        for (int i = 0; i < equations.size(); ++i) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            int id_of_dividend = id_of_numbers[dividend];
            int id_of_divisor = id_of_numbers[divisor];

            g[id_of_dividend][id_of_divisor] = values[i];
            g[id_of_divisor][id_of_dividend] = 1 / values[i];
        }

        for (int k = 0; k < amount_of_numbers; ++k) {
            for (int i = 0; i < amount_of_numbers; ++i) {
                for (int j = 0; j < amount_of_numbers; ++j) {
                    if (g[i][k] > 0 && g[k][j] > 0) {
                        g[i][j] = g[i][k] * g[k][j];
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

                if (g[id_of_dividend][id_of_divisor] > 0) {
                    query_result = g[id_of_dividend][id_of_divisor];
                }
            }

            query_results.emplace_back(query_result);
        }

        return query_results;
    }
};
