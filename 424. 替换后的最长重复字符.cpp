// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/2.
// https://leetcode-cn.com/problems/longest-repeating-character-replacement/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> number_of_characters;

        number_of_characters.fill(0);

        int left = 0;
        int right = 0;
        int number_of_most_frequently_used_character = 0;

        while (right < s.size()) {
            ++number_of_characters[s[right] - 'A'];
            number_of_most_frequently_used_character = max(number_of_most_frequently_used_character, number_of_characters[s[right] - 'A']);

            if (right - left + 1 - number_of_most_frequently_used_character > k) {
                --number_of_characters[s[left++] - 'A'];
            }

            ++right;
        }

        return right - left + 1 - 1;
    }
};
