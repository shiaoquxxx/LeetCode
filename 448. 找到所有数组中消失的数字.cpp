// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/13.
// https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();
        vector<int> answer;

        for (int i = 0; i < n; ++i) {
            nums[(nums[i] % n)] += n;
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n) {
                answer.emplace_back(i == 0 ? n : i);
            }
        }

        sort(answer.begin(), answer.end());

        return answer;
    }
};
