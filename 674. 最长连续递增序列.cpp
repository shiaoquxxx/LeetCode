// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/24.
// https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int current_length_of_subsequence = 1;
        int maximum_length_of_subsequence = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++current_length_of_subsequence;
            }
            else {
                current_length_of_subsequence = 1;
            }

            maximum_length_of_subsequence = max(maximum_length_of_subsequence, current_length_of_subsequence);
        }

        return maximum_length_of_subsequence;
    }
};
