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

public:
    explicit MergeFindSet(size_t n) {
        root.resize(n, 0);
        rank.resize(n, 1);

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

        if (_x == _y) {
            return;
        }

        if (rank[_x] < rank[_y]) {
            swap(rank[_x], rank[_y]);
        }

        rank[_x] += rank[_y];

        root[_y] = _x;
    }
};
