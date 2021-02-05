// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/5.
// https://leetcode-cn.com/problems/get-equal-substrings-within-budget/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> costs(s.size(), 0);

        for (int i = 0; i < s.size(); ++i) {
            costs[i] = abs(s[i] - t[i]);
        }

        int starting_position_of_substring = 0;
        int ending_position_of_substring = 0;
        int cost = 0;
        int answer = 0;

        while (ending_position_of_substring < s.size()) {
            cost += costs[ending_position_of_substring];

            while (cost > maxCost) {
                cost -= costs[starting_position_of_substring];
                ++starting_position_of_substring;
            }

            answer = max(answer, ending_position_of_substring - starting_position_of_substring + 1);

            ++ending_position_of_substring;
        }

        return answer;
    }
};
