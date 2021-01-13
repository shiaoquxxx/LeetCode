// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/8.
// https://leetcode-cn.com/problems/rotate-array/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        k %= nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
