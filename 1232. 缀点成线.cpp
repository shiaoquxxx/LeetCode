// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/17.
// https://leetcode-cn.com/problems/check-if-it-is-a-straight-line/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    bool checkStraightLine(vector<vector<int>> &coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }

        Vector v(Point(coordinates[1][0], coordinates[1][1]) - Point(coordinates[0][0], coordinates[0][1])); // LEETCODE.H

        for (int i = 2; i < coordinates.size(); ++i) {
            if (outer_product(v, Point(coordinates[i][0], coordinates[i][1]) - Point(coordinates[0][0], coordinates[0][1])) != 0) {
                return false;
            }
        }

        return true;
    }
};
