// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/18.
// https://leetcode-cn.com/problems/accounts-merge/
// ----- ----- ----- ----- ----- ----- ----- -----

#include "leetcode.h"

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string, string> account_name_of_emails;
        map<string, int> id_of_emails;
        int amount_of_emails = 0;

        for (auto &account: accounts) {
            string account_name = account[0];

            for (int i = 1; i < account.size(); ++i) {
                if (id_of_emails.find(account[i]) == id_of_emails.end()) {
                    account_name_of_emails[account[i]] = account_name;
                    id_of_emails[account[i]] = amount_of_emails++;
                }
            }
        }

        MergeFindSet merge_find_set(amount_of_emails); // LEETCODE.H

        for (auto &account: accounts) {
            if (account.size() <= 1) {
                continue;
            }

            string first_email_address = account[1];

            for (int i = 2; i < account.size(); ++i) {
                merge_find_set.merge(id_of_emails[first_email_address], id_of_emails[account[i]]);
            }
        }

        unordered_map<int, int> id_of_users;
        int amount_of_users = 0;

        for (auto &[_, id_of_email]: id_of_emails) {
            int user = merge_find_set.find(id_of_email);

            if (id_of_users.find(user) == id_of_users.end()) {
                id_of_users[user] = amount_of_users++;
            }
        }

        vector<vector<string>> answer(amount_of_users, vector<string>());

        for (auto &[email, id_of_email]: id_of_emails) {
            int user = merge_find_set.find(id_of_email);
            int id_of_user = id_of_users[user];

            if (answer[id_of_user].empty()) {
                answer[id_of_user].emplace_back(account_name_of_emails[email]);
            }

            answer[id_of_user].emplace_back(email);
        }

        return answer;
    }
};
