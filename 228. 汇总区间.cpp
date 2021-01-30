// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/10.
// https://leetcode-cn.com/problems/summary-ranges/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ranges;

        if (nums.empty()) {
            return ranges;
        }

        int starting_position_of_range = 0;
        int ending_position_of_range = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[ending_position_of_range] + 1) {
                ++ending_position_of_range;
            }
            else {
                if (starting_position_of_range != ending_position_of_range) {
                    ranges.emplace_back(to_string(nums[starting_position_of_range]) + "->" + to_string(nums[ending_position_of_range]));
                }
                else {
                    ranges.emplace_back(to_string(nums[ending_position_of_range]));
                }

                starting_position_of_range = ending_position_of_range = i;
            }
        }

        if (starting_position_of_range != ending_position_of_range) {
            ranges.emplace_back(to_string(nums[starting_position_of_range]) + "->" + to_string(nums[ending_position_of_range]));
        }
        else {
            ranges.emplace_back(to_string(nums[ending_position_of_range]));
        }

        return ranges;
    }
};
