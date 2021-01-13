// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/4.
// https://leetcode-cn.com/problems/fibonacci-number/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    Solution() {
        fibonacci_sequence[0] = 0LL;
        fibonacci_sequence[1] = 1LL;

        for (int i = 2; i < fibonacci_sequence.size(); ++i) {
            fibonacci_sequence[i] = fibonacci_sequence[i - 1] + fibonacci_sequence[i - 2];
        }
    }

    int fib(int n) {
        return static_cast<int>(fibonacci_sequence[n]);
    }

private:
    array<long long, 50> fibonacci_sequence;
};
