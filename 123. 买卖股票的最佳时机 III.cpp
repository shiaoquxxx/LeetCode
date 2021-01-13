// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/9.
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int buy_once = -prices[0];
        int sell_once = 0;
        int buy_twice = -prices[0];
        int sell_twice = 0;

        for (int i = 1; i < prices.size(); ++i) {
            buy_once = max(buy_once, -prices[i]);
            sell_once = max(sell_once, buy_once + prices[i]);
            buy_twice = max(buy_twice, sell_once - prices[i]);
            sell_twice = max(sell_twice, buy_twice + prices[i]);
        }

        return sell_twice;
    }
};
