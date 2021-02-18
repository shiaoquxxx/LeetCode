// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/18.
// https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int minKBitFlips(vector<int> &A, int K) {
        queue<int> queue;
        int answer = 0;

        for (int i = 0; i < A.size(); ++i) {
            while (!queue.empty() && queue.front() <= i - K) {
                queue.pop();
            }

            if ((A[i] ^ (queue.size() % 2)) == 0) {
                if (i >= A.size() - K + 1) {
                    return -1;
                }

                queue.push(i);
                ++answer;
            }
        }

        return answer;
    }
};
