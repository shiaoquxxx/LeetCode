// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/17.
// https://leetcode-cn.com/problems/reshape-the-matrix/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int _r = nums.size();
        int _c = nums[0].size();

        if (_r * _c != r * c) {
            return nums;
        }

        vector<vector<int>> answer(r, vector<int>(c, 0));

        for (int _i = 0; _i < _r; ++_i) {
            for (int _j = 0; _j < _c; ++_j) {
                int n = _i * _c + _j;
                int i = n / c;
                int j = n % c;

                answer[i][j] = nums[_i][_j];
            }
        }

        return answer;
    }
};
