// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/1.
// https://leetcode-cn.com/problems/fair-candy-swap/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
        unordered_set<int> candy_sizes_of_alice(A.begin(), A.end());
        unordered_set<int> candy_sizes_of_bob(B.begin(), B.end());
        int total_candy_size_of_alice = accumulate(A.begin(), A.end(), 0);
        int total_candy_size_of_bob = accumulate(B.begin(), B.end(), 0);

        for (auto i = candy_sizes_of_alice.begin(); i != candy_sizes_of_alice.end(); ++i) {
            auto j = candy_sizes_of_bob.find(static_cast<int>((total_candy_size_of_bob - total_candy_size_of_alice + 2 * (*i)) / 2.0));

            if (j != candy_sizes_of_bob.end()) {
                return {*i, *j};
            }
        }

        return {};
    }
};
