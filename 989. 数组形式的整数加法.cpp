// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/22.
// https://leetcode-cn.com/problems/add-to-array-form-of-integer/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        vector<int> k;

        while (K) {
            k.emplace_back(K % 10);
            K /= 10;
        }

        reverse(k.begin(), k.end());

        return addArray(A, k);
    }

    vector<int> addArray(vector<int> &m, vector<int> &n) {
        vector<int> result;
        result.reserve(max(m.size(), n.size()) + 1);

        auto iterator_of_m = m.rbegin();
        auto iterator_of_n = n.rbegin();
        int carry = 0;

        while (iterator_of_m != m.rend() || iterator_of_n != n.rend() || carry) {
            int value_from_m = 0;
            int value_from_n = 0;

            if (iterator_of_m != m.rend()) {
                value_from_m = *iterator_of_m++;
            }
            if (iterator_of_n != n.rend()) {
                value_from_n = *iterator_of_n++;
            }

            int sum = value_from_m + value_from_n + carry;

            carry = sum / 10;
            sum %= 10;

            result.emplace_back(sum);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
