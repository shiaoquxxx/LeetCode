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
// Dual Heap
// ----- ----- ----- ----- ----- ----- ----- -----

class DualHeap {
private:
    int n;

    priority_queue<int, vector<int>, less<>> smaller_part;
    int size_of_smaller_part;

    priority_queue<int, vector<int>, greater<>> bigger_part;
    int size_of_bigger_part;

    unordered_map<int, int> delayed;

    template<typename T>
    void prune(T &heap) {
        while (!heap.empty()) {
            int top = heap.top();

            if (delayed.count(top)) {
                --delayed[top];

                if (!delayed[top]) {
                    delayed.erase(top);
                }

                heap.pop();
            }
            else {
                break;
            }
        }
    }

    void balance() {
        if (size_of_smaller_part > size_of_bigger_part + 1) {
            bigger_part.push(smaller_part.top());
            ++size_of_bigger_part;

            smaller_part.pop();
            --size_of_smaller_part;

            prune(smaller_part);
        }
        else if (size_of_smaller_part < size_of_bigger_part) {
            smaller_part.push(bigger_part.top());
            ++size_of_smaller_part;

            bigger_part.pop();
            --size_of_bigger_part;

            prune(bigger_part);
        }
    }

public:
    explicit DualHeap(int n)
        : n(n), size_of_smaller_part(0), size_of_bigger_part(0) {
    }

    void insert(int number) {
        if (smaller_part.empty() || number <= smaller_part.top()) {
            smaller_part.push(number);
            ++size_of_smaller_part;
        }
        else {
            bigger_part.push(number);
            ++size_of_bigger_part;
        }

        balance();
    }

    void erase(int number) {
        ++delayed[number];

        if (number <= smaller_part.top()) {
            --size_of_smaller_part;

            if (number == smaller_part.top()) {
                prune(smaller_part);
            }
        }
        else {
            --size_of_bigger_part;

            if (number == bigger_part.top()) {
                prune(bigger_part);
            }
        }

        balance();
    }

    double get_median() {
        return n & 1 ? smaller_part.top() : smaller_part.top() / 2.0 + bigger_part.top() / 2.0;
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
    unordered_map<int, int> roots;

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

    size_t get_number_of_different_roots() { // a.k.a connected components
        roots.clear();

        for (auto i = root.begin(); i != root.end(); ++i) {
            roots[find(*i)]++;
        }

        return roots.size();
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

double inner_product(Vector m, Vector n) { // a.k.a dot product / scalar product
    return m.x * n.x + m.y * n.y;
}

double outer_product(Vector m, Vector n) { // a.k.a cross product / vector product
    return m.x * n.y - m.y * n.x;
}
