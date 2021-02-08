// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/8.
// https://leetcode-cn.com/problems/longest-turbulent-subarray/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int maxTurbulenceSize(vector<int> &arr) {
        vector<int> turbulence;
        int flag = 0;
        int answer = 0;

        for (auto &number: arr) {
            if (turbulence.empty()) {
                turbulence.emplace_back(number);
            }
            else if (number == turbulence.back()) {
                turbulence.clear();
                flag = 0;
                turbulence.emplace_back(number);
            }
            else if (flag == 0) {
                if (number < turbulence.back()) {
                    flag = 1;
                }
                else {
                    flag = -1;
                }

                turbulence.emplace_back(number);
            }
            else {
                if ((number - turbulence.back()) / flag > 0) {
                    turbulence.emplace_back(number);
                    flag = -flag;
                }
                else {
                    int t = turbulence.back();

                    turbulence.clear();
                    turbulence.emplace_back(t);
                    turbulence.emplace_back(number);

                    if (number < t) {
                        flag = 1;
                    }
                    else {
                        flag = -1;
                    }
                }
            }

            answer = max(answer, (int) turbulence.size());
        }

        return answer;
    }
};
