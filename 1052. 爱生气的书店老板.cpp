// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/23.
// https://leetcode-cn.com/problems/grumpy-bookstore-owner/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
        int ans = 0;

        for (int i = 0; i < customers.size(); ++i) {
            if (!grumpy[i]) {
                ans += customers[i];
                customers[i] = 0;
            }
        }

        int sat = 0;

        for (int i = 0; i < X; ++i) {
            sat += customers[i];
        }

        int maxsat = sat;

        for (int i = X; i < customers.size(); ++i) {
            sat += customers[i];
            sat -= customers[i - X];
            maxsat = max(maxsat, sat);
        }

        ans += maxsat;

        return ans;
    }
};
