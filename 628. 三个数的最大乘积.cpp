// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/20.
// https://leetcode-cn.com/problems/maximum-product-of-three-numbers/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};
