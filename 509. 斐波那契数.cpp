// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/4.
// https://leetcode-cn.com/problems/fibonacci-number/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    Solution() {
        fibonacci_sequence[0] = 0;
        fibonacci_sequence[1] = 1;

        for (int i = 2; i < fibonacci_sequence.size(); ++i) {
            fibonacci_sequence[i] = fibonacci_sequence[i - 1] + fibonacci_sequence[i - 2];
        }
    }

    int fib(int n) {
        return fibonacci_sequence[n];
    }

private:
    array<int, 31> fibonacci_sequence;
};
