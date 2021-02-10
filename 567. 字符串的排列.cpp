// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/10.
// https://leetcode-cn.com/problems/permutation-in-string/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();

        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> number_of_characters_1(26, 0);
        vector<int> number_of_characters_2(26, 0);

        for (int i = 0; i < n; ++i) {
            ++number_of_characters_1[s1[i] - 'a'];
        }

        for (int i = 0; i < n; ++i) {
            ++number_of_characters_2[s2[i] - 'a'];
        }

        if (number_of_characters_1 == number_of_characters_2) {
            return true;
        }

        for (int i = n; i < s2.size(); ++i) {
            ++number_of_characters_2[s2[i] - 'a'];
            --number_of_characters_2[s2[i - n] - 'a'];

            if (number_of_characters_1 == number_of_characters_2) {
                return true;
            }
        }

        return false;
    }
};
