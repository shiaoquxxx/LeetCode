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

class DisjointSet {
private:
    vector<int> p;
    vector<int> rank;

public:
    explicit DisjointSet(size_t n) {
        p.resize(n, 0);
        rank.resize(n, 1);

        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    int Find(int x) {
        return p[x] == x ? x : p[x] = Find(p[x]);
    }

    void Union(int x, int y) {
        int px = Find(x);
        int py = Find(y);

        if (px == py) {
            return;
        }

        if (rank[px] < rank[py]) {
            swap(rank[px], rank[py]);
        }

        rank[px] += rank[py];

        p[py] = px;
    }
};
