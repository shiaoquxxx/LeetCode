// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/4.
// https://leetcode-cn.com/problems/maximum-average-subarray-i/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        double average = 0;
        double maximum_average = 0;

        for (int i = 0; i < k; ++i) {
            average += nums[i] / (k + 0.0);
            maximum_average = average;
        }

        for (int i = k; i < nums.size(); ++i) {
            average -= nums[i - k] / (k + 0.0);
            average += nums[i] / (k + 0.0);
            maximum_average = max(maximum_average, average);
        }

        return maximum_average;
    }
};
