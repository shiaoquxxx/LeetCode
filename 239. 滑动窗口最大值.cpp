// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/2.
// https://leetcode-cn.com/problems/sliding-window-maximum/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<pair<int, int>> monotonic_queue;
        vector<int> maximum_elements;

        for (int i = 0; i < nums.size(); ++i) {
            if (monotonic_queue.empty()) {
                monotonic_queue.emplace_back(make_pair(nums[i], i));
            }
            else {
                if (monotonic_queue.front().second <= i - k) {
                    monotonic_queue.pop_front();
                }

                if (monotonic_queue.empty() || monotonic_queue.back().first <= nums[i]) {
                    while (!monotonic_queue.empty() && monotonic_queue.back().first <= nums[i]) {
                        monotonic_queue.pop_back();
                    }

                }

                monotonic_queue.emplace_back(make_pair(nums[i], i));
            }

            if (i >= k - 1) {
                maximum_elements.emplace_back(monotonic_queue.front().first);
            }
        }

        return maximum_elements;
    }
};
