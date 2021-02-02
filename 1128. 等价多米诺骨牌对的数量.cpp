// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/26.
// https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        array<int, 100> number_of_dominoes;

        number_of_dominoes.fill(0);

        for (vector<int> &domino: dominoes) {
            number_of_dominoes[10 * min(domino[0], domino[1]) + max(domino[0], domino[1])]++;
        }

        int number_of_equivalent_dominoes = 0;

        for (int &number_of_domino: number_of_dominoes) {
            if (number_of_domino > 0) {
                number_of_equivalent_dominoes += number_of_domino * (number_of_domino - 1) / 2;
            }
        }

        return number_of_equivalent_dominoes;
    }
};
