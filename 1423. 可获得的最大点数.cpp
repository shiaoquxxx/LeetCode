// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/6.
// https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int score = 0;

        for (int i = 0; i < k; ++i) {
            score += cardPoints[i];
        }

        int maximum_score = score;

        for (int i = 0; i < k; ++i) {
            score += cardPoints[cardPoints.size() - 1 - i];
            score -= cardPoints[k - 1 - i];

            maximum_score = max(maximum_score, score);
        }

        return maximum_score;
    }
};
