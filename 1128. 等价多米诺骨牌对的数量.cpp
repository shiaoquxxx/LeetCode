// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/26.
// https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        array<int, 100> amount_of_dominoes;

        amount_of_dominoes.fill(0);

        for (vector<int> &domino: dominoes) {
            amount_of_dominoes[10 * min(domino[0], domino[1]) + max(domino[0], domino[1])]++;
        }

        int amount_of_equivalent_dominoes = 0;

        for (int &amount_of_domino: amount_of_dominoes) {
            if (amount_of_domino > 0) {
                amount_of_equivalent_dominoes += amount_of_domino * (amount_of_domino - 1) / 2;
            }
        }

        return amount_of_equivalent_dominoes;
    }
};
