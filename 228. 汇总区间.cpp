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

        int start_of_range = 0;
        int end_of_range = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[end_of_range] + 1) {
                ++end_of_range;
            }
            else {
                if (start_of_range != end_of_range) {
                    ranges.emplace_back(to_string(nums[start_of_range]) + "->" + to_string(nums[end_of_range]));
                }
                else {
                    ranges.emplace_back(to_string(nums[end_of_range]));
                }

                start_of_range = end_of_range = i;
            }
        }

        if (start_of_range != end_of_range) {
            ranges.emplace_back(to_string(nums[start_of_range]) + "->" + to_string(nums[end_of_range]));
        }
        else {
            ranges.emplace_back(to_string(nums[end_of_range]));
        }

        return ranges;
    }
};
