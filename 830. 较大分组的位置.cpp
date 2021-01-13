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
        int start = 0;
        int end = 0;
        char previous_character = '#';

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == previous_character) {
                ++end;
            }
            else {
                if (end - start + 1 >= 3) {
                    large_group_positions.push_back({start, end});
                }

                start = i;
                end = i;
            }

            previous_character = s[i];
        }

        return large_group_positions;
    }
};
