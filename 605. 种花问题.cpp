// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/1.
// https://leetcode-cn.com/problems/can-place-flowers/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int amount_of_continuous_available_plots = 0;
        int maximum_amount_of_flowers = 0;

        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                ++amount_of_continuous_available_plots;
            }
            else {
                --amount_of_continuous_available_plots;

                if (amount_of_continuous_available_plots > 0) {
                    maximum_amount_of_flowers += (amount_of_continuous_available_plots + 1) / 2;
                }

                amount_of_continuous_available_plots = -1;
            }
        }

        maximum_amount_of_flowers += (amount_of_continuous_available_plots + 1) / 2;

        return maximum_amount_of_flowers >= n;
    }
};
