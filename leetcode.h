// ----- ----- ----- ----- ----- ----- ----- -----
// Created by Shiao Qu on 2021/1/1.
// ----- ----- ----- ----- ----- ----- ----- -----

#pragma once

#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x)
        : val(x), next(nullptr) {
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {
    }
};

class MergeFindSet {
private:
    vector<int> root;
    vector<int> rank;
    vector<int> seen;
    int amount_of_connected_components;

public:
    explicit MergeFindSet(size_t n) {
        root.resize(n, 0);
        rank.resize(n, 1);
        seen.resize(n, 0);
        amount_of_connected_components = 0;

        for (int i = 0; i < n; ++i) {
            root[i] = i;
        }
    }

    int find(int x) {
        return root[x] == x ? x : root[x] = find(root[x]);
    }

    void merge(int x, int y) {
        int _x = find(x);
        int _y = find(y);

        if (!seen[x]) {
            ++amount_of_connected_components;
            seen[x] = 1;
        }

        if (!seen[y]) {
            ++amount_of_connected_components;
            seen[y] = 1;
        }

        if (_x == _y) {
            return;
        }

        --amount_of_connected_components;

        if (rank[_x] < rank[_y]) {
            swap(rank[_x], rank[_y]);
        }

        rank[_x] += rank[_y];

        root[_y] = _x;
    }

    int get_amount_of_connected_components() {
        return amount_of_connected_components;
    }

    int get_rank(int x) {
        return rank[find(x)];
    }
};
