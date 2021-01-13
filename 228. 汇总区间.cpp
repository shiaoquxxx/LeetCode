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

        int start = 0;
        int end = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[end] + 1) {
                ++end;
            }
            else {
                if (start != end) {
                    ranges.emplace_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                }
                else {
                    ranges.emplace_back(to_string(nums[end]));
                }

                start = end = i;
            }
        }

        if (start != end) {
            ranges.emplace_back(to_string(nums[start]) + "->" + to_string(nums[end]));
        }
        else {
            ranges.emplace_back(to_string(nums[end]));
        }

        return ranges;
    }
};
