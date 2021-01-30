// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/3.
// https://leetcode-cn.com/problems/partition-list/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy_head_for_smaller_elements = new ListNode(0);
        ListNode *dummy_head_for_bigger_elements = new ListNode(0);

        ListNode *smaller_elements = dummy_head_for_smaller_elements;
        ListNode *bigger_elements = dummy_head_for_bigger_elements;

        while (head) {
            if (head->val < x) {
                smaller_elements->next = head;
                smaller_elements = smaller_elements->next;
            }
            else {
                bigger_elements->next = head;
                bigger_elements = bigger_elements->next;
            }

            head = head->next;
        }

        smaller_elements->next = dummy_head_for_bigger_elements->next;
        bigger_elements->next = nullptr;

        return dummy_head_for_smaller_elements->next;
    }
};
