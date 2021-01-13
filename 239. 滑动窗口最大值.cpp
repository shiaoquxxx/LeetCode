// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/2.
// https://leetcode-cn.com/problems/sliding-window-maximum/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> maximum_elements;
        deque<pair<int, int>> mq;

        for (int i = 0; i < nums.size(); ++i) {
            if (mq.empty()) {
                mq.emplace_back(make_pair(nums[i], i));
            }
            else {
                if (mq.front().second <= i - k) {
                    mq.pop_front();
                }

                if (mq.empty() || mq.back().first <= nums[i]) {
                    while (!mq.empty() && mq.back().first <= nums[i]) {
                        mq.pop_back();
                    }

                }

                mq.emplace_back(make_pair(nums[i], i));
            }

            if (i >= k - 1) {
                maximum_elements.emplace_back(mq.front().first);
            }
        }

        return maximum_elements;
    }
};
