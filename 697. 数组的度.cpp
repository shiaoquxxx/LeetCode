// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/20.
// https://leetcode-cn.com/problems/degree-of-an-array/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        unordered_map<int, int> first_time;
        unordered_map<int, int> last_time;
        unordered_map<int, int> frequency;
        int maximum_frequency = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (!first_time.count(nums[i])) {
                first_time[nums[i]] = i;
                frequency[nums[i]] = 0;
            }

            last_time[nums[i]] = i;
            ++frequency[nums[i]];
            maximum_frequency = max(maximum_frequency, frequency[nums[i]]);
        }

        int answer = INT_MAX;

        for (auto &[k, v]: frequency) {
            if (v == maximum_frequency) {
                answer = min(answer, last_time[k] - first_time[k] + 1);
            }
        }

        return answer;
    }
};
