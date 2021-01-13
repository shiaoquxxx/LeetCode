// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/11.
// https://leetcode-cn.com/problems/smallest-string-with-swaps/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        MergeFindSet merge_find_set(s.size()); // LEETCODE.H

        for (auto &pair: pairs) {
            merge_find_set.merge(pair[0], pair[1]);
        }

        unordered_map<int, vector<char>> characters_of_sets;

        for (int i = 0; i < s.size(); ++i) {
            characters_of_sets[merge_find_set.find(i)].emplace_back(s[i]);
        }

        for (auto &[_, characters]: characters_of_sets) {
            sort(characters.begin(), characters.end(), greater<>());
        }

        for (int i = 0; i < s.size(); ++i) {
            int root = merge_find_set.find(i);

            s[i] = characters_of_sets[root].back();
            characters_of_sets[root].pop_back();
        }

        return s;
    }
};
