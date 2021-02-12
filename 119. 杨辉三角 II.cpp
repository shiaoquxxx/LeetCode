// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/12.
// https://leetcode-cn.com/problems/pascals-triangle-ii/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    explicit Solution() {
        precalculate();
    }

    vector<int> getRow(int rowIndex) {
        return rows[rowIndex];
    }

private:
    vector<vector<int>> rows;

    void precalculate() {
        rows.resize(34);

        for (int i = 0; i < 34; ++i) {
            rows[i].resize(i + 1);
            rows[i][0] = 1;
            rows[i][i + 1 - 1] = 1;
        }

        for (int i = 2; i <= 33; ++i) {
            for (int j = 1; j < i + 1 - 1; ++j) {
                rows[i][j] = rows[i - 1][j - 1] + rows[i - 1][j];
            }
        }
    }
};
