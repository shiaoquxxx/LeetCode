// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/28.
// https://leetcode-cn.com/problems/find-pivot-index/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int sum_of_all_numbers = accumulate(nums.begin(), nums.end(), 0);
        int sum_of_left_part = 0;
        int sum_of_right_part = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum_of_right_part = sum_of_all_numbers - nums[i] - sum_of_left_part;

            if (sum_of_left_part == sum_of_right_part) {
                return i;
            }

            sum_of_left_part += nums[i];
        }

        return -1;
    }
};
