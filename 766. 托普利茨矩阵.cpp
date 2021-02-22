// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/22.
// https://leetcode-cn.com/problems/toeplitz-matrix/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        for (int i = 0; i < matrix.size() - 1; ++i) {
            for (int j = 0; j < matrix[0].size() - 1; ++j) {
                if (matrix[i][j] != matrix[i + 1][j + 1]) {
                    return false;
                }
            }
        }

        return true;
    }
};
