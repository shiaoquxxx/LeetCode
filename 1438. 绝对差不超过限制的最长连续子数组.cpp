// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/21.
// https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        deque<int> mqmin;
        deque<int> mqmax;
        int left = 0;
        int right = 0;
        int ans = 0;

        while (right < nums.size()) {
            while (!mqmax.empty() && mqmax.back() < nums[right]) {
                mqmax.pop_back();
            }

            while (!mqmin.empty() && mqmin.back() > nums[right]) {
                mqmin.pop_back();
            }

            mqmax.emplace_back(nums[right]);
            mqmin.emplace_back(nums[right]);

            while (!mqmax.empty() && !mqmin.empty() && mqmax.front() - mqmin.front() > limit) {
                if (nums[left] == mqmax.front()) {
                    mqmax.pop_front();
                }

                if (nums[left] == mqmin.front()) {
                    mqmin.pop_front();
                }

                ++left;
            }

            ans = max(ans, right - left + 1);
            ++right;
        }

        return ans;
    }
};
