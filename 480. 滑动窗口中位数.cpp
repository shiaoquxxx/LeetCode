// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/3.
// https://leetcode-cn.com/problems/sliding-window-median/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        DualHeap dual_heap(k); // LEETCODE.H

        for (int i = 0; i < k; ++i) {
            dual_heap.insert(nums[i]);
        }

        vector<double> answer;
        answer.emplace_back(dual_heap.get_median());

        for (int i = k; i < nums.size(); ++i) {
            dual_heap.insert(nums[i]);
            dual_heap.erase(nums[i - k]);
            answer.emplace_back(dual_heap.get_median());
        }

        return answer;
    }
};
