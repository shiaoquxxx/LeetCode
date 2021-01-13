// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/9.
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maximum_profit_by_buying_once = -prices[0];
        int maximum_profit_by_selling_once = 0;
        int maximum_profit_by_buying_twice = -prices[0];
        int maximum_profit_by_selling_twice = 0;

        for (int i = 1; i < prices.size(); ++i) {
            maximum_profit_by_buying_once = max(maximum_profit_by_buying_once, -prices[i]);
            maximum_profit_by_selling_once = max(maximum_profit_by_selling_once, maximum_profit_by_buying_once + prices[i]);
            maximum_profit_by_buying_twice = max(maximum_profit_by_buying_twice, maximum_profit_by_selling_once - prices[i]);
            maximum_profit_by_selling_twice = max(maximum_profit_by_selling_twice, maximum_profit_by_buying_twice + prices[i]);
        }

        return maximum_profit_by_selling_twice;
    }
};
