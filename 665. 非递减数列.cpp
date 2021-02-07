// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/7.
// https://leetcode-cn.com/problems/non-decreasing-array/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (i - 1 >= 0 && nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] = nums[i];
                }

                for (int j = i + 1; j < nums.size() - 1; ++j) {
                    if (nums[j] > nums[j + 1]) {
                        return false;
                    }
                }

                break;
            }
        }

        return true;
    }
};
