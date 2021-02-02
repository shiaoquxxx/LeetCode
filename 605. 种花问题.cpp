// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/1.
// https://leetcode-cn.com/problems/can-place-flowers/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int number_of_continuous_available_plots = 0;
        int maximum_number_of_flowers = 0;

        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                ++number_of_continuous_available_plots;
            }
            else {
                --number_of_continuous_available_plots;

                if (number_of_continuous_available_plots > 0) {
                    maximum_number_of_flowers += (number_of_continuous_available_plots + 1) / 2;
                }

                number_of_continuous_available_plots = -1;
            }
        }

        maximum_number_of_flowers += (number_of_continuous_available_plots + 1) / 2;

        return maximum_number_of_flowers >= n;
    }
};
