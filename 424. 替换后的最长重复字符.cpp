// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/2.
// https://leetcode-cn.com/problems/longest-repeating-character-replacement/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> amount_of_characters;

        amount_of_characters.fill(0);

        int left = 0;
        int right = 0;
        int amount_of_most_character = 0;

        while (right < s.size()) {
            ++amount_of_characters[s[right] - 'A'];
            amount_of_most_character = max(amount_of_most_character, amount_of_characters[s[right] - 'A']);

            if (right - left + 1 - amount_of_most_character > k) {
                --amount_of_characters[s[left++] - 'A'];
            }

            ++right;
        }

        return right - left + 1 - 1;
    }
};
