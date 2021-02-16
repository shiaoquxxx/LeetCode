// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/15.
// https://leetcode-cn.com/problems/max-consecutive-ones/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int number_of_consecutive_ones = 0;
    int answer = 0;

    int findMaxConsecutiveOnes(vector<int> &nums) {
        for (auto &number: nums) {
            if (!number) {
                number_of_consecutive_ones = 0;
            }
            else {
                ++number_of_consecutive_ones;
                answer = max(answer, number_of_consecutive_ones);
            }
        }

        return answer;
    }
};
