// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/31.
// https://leetcode-cn.com/problems/similar-string-groups/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    bool isSimilar(string &s1, string &s2) {
        auto i1 = s1.begin();
        auto i2 = s2.begin();
        int counter = 0;

        while (i1 != s1.end() && i2 != s2.end()) {
            if (*i1++ != *i2++) {
                ++counter;
                if (counter > 2) {
                    return false;
                }
            }
        }

        return true;
    }

    int numSimilarGroups(vector<string> &strs) {
        MergeFindSet merge_find_set(strs.size()); // LEETCODE.H

        for (int i = 0; i < strs.size(); ++i) {
            for (int j = i + 1; j < strs.size(); ++j) {
                if (merge_find_set.find(i) == merge_find_set.find(j)) {
                    continue;
                }
                if (isSimilar(strs[i], strs[j])) {
                    merge_find_set.merge(i, j);
                }
            }
        }

        return merge_find_set.get_amount_of_different_roots();
    }
};
