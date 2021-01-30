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

// ----- ----- ----- ----- ----- ----- ----- -----
// Merge-Find Set
// ----- ----- ----- ----- ----- ----- ----- -----

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

    int get_rank(int x) {
        return rank[find(x)];
    }

    size_t get_amount_of_disjoint_roots(void) {
        unordered_set<int> roots;

        for (auto i = root.begin(); i != root.end(); ++i) {
            roots.emplace(find(*i));
        }

        return roots.size();
    }

    void show_debug_information(void) {
        printf("----- ----- ----- -----\n");
        printf("merge-find set size: %lu\n", root.size());
        printf("merge-find set disjoint roots: %lu\n", get_amount_of_disjoint_roots());
        for (int i = 0; i < root.size(); ++i) {
            printf("node: %d\troot:%d\trank:%d\t\n", i, find(i), rank[i]);
        }
        printf("----- ----- ----- -----\n");

    }
};

// ----- ----- ----- ----- ----- ----- ----- -----
// Computational Geometry
// ----- ----- ----- ----- ----- ----- ----- -----

#define EPS (1e-6)
#define eq(m, n) (fabs((m) - (n)) < EPS)

class Point {
public:
    double x;
    double y;

    explicit Point(double x = 0.0, double y = 0.0)
        : x(x), y(y) {
    }

    Point operator+(Point p) {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(Point p) {
        return Point(x - p.x, y - p.y);
    }

    Point operator*(double k) {
        return Point(k * x, k * y);
    }

    Point operator/(double k) {
        return Point(x / k, y / k);
    }

    double norm() {
        return sqrt(x * x + y * y);
    }

    bool operator<(const Point &p) const {
        return !eq(x, p.x) ? x < p.x : y < p.y;
    }

    bool operator==(const Point &p) const {
        return eq(x, p.x) && eq(y, p.y);
    }
};

using Vector = Point;

double inner_product(Vector m, Vector n) { // dot product / scalar product
    return m.x * n.x + m.y * n.y;
}

double outer_product(Vector m, Vector n) { // cross product / vector product
    return m.x * n.y - m.y * n.x;
}
