// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/5.
// https://leetcode-cn.com/problems/positions-of-large-groups/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        s += '#';

        vector<vector<int>> large_group_positions;
        int start_of_group = 0;
        int end_of_group = 0;
        char previous_character = '#';

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == previous_character) {
                ++end_of_group;
            }
            else {
                if (end_of_group - start_of_group + 1 >= 3) {
                    large_group_positions.push_back({start_of_group, end_of_group});
                }

                start_of_group = i;
                end_of_group = i;
            }

            previous_character = s[i];
        }

        return large_group_positions;
    }
};
