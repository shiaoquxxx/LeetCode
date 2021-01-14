// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/14.
// https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int> &A) {
        int last_digit = 0;

        vector<bool> answer;

        for (auto &digit: A) {
            last_digit = (last_digit * 2 + digit) % 10;
            answer.emplace_back(last_digit == 0 || last_digit == 5);
        }

        return answer;
    }
};
