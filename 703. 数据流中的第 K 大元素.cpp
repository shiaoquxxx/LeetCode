// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/2/11.
// https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class KthLargest {
public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;

        for (auto &number: nums) {
            add(number);
        }
    }

    int add(int val) {
        priority_queue.push(val);

        if (priority_queue.size() > k) {
            priority_queue.pop();
        }

        return priority_queue.top();
    }

private:
    priority_queue<int, vector<int>, greater<>> priority_queue;
    int k;
};
