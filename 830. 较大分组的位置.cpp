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
        int starting_position_of_group = 0;
        int ending_position_of_group = 0;
        char previous_character = '#';

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == previous_character) {
                ++ending_position_of_group;
            }
            else {
                if (ending_position_of_group - starting_position_of_group + 1 >= 3) {
                    large_group_positions.push_back({starting_position_of_group, ending_position_of_group});
                }

                starting_position_of_group = i;
                ending_position_of_group = i;
            }

            previous_character = s[i];
        }

        return large_group_positions;
    }
};
