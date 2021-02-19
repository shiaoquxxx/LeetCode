// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/19.
// https://leetcode-cn.com/problems/max-consecutive-ones-iii/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int left = 0;
        int right = 0;
        int k = 0;
        int answer = 0;

        for (right = 0; right < A.size(); ++right) {
            if (!A[right]) {
                ++k;

                while (k > K) {
                    if (!A[left]) {
                        --k;
                    }

                    ++left;
                }
            }

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};
