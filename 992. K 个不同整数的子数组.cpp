// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/9.
// https://leetcode-cn.com/problems/subarrays-with-k-different-integers/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int subarraysWithKDistinct(vector<int> &A, int K) {
        vector<int> number_of_numbers_1(A.size() + 1, 0);
        vector<int> number_of_numbers_2(A.size() + 1, 0);
        int distinct_types_of_numbers_1 = 0;
        int distinct_types_of_numbers_2 = 0;
        int left_1 = 0;
        int left_2 = 0;
        int right = 0;
        int answer = 0;

        while (right < A.size()) {
            if (!number_of_numbers_1[A[right]]) {
                ++distinct_types_of_numbers_1;
            }

            ++number_of_numbers_1[A[right]];

            if (!number_of_numbers_2[A[right]]) {
                ++distinct_types_of_numbers_2;
            }

            ++number_of_numbers_2[A[right]];

            ++right;

            // [left1, left2)
            while (distinct_types_of_numbers_1 > K) {
                if (!--number_of_numbers_1[A[left_1++]]) {
                    --distinct_types_of_numbers_1;
                }
            }

            while (distinct_types_of_numbers_2 > K - 1) {
                if (!--number_of_numbers_2[A[left_2++]]) {
                    --distinct_types_of_numbers_2;
                }
            }

            answer += left_2 - left_1;
        }

        return answer;
    }
};
