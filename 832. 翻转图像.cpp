// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/24.
// https://leetcode-cn.com/problems/flipping-an-image/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        for (auto &v: A) {
            reverse(v.begin(), v.end());

            for (auto &e: v) {
                e ^= 1;
            }
        }

        return A;
    }
};
