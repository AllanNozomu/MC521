#include <sstream>
#include <cassert>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <climits>

using namespace std;

typedef int s32;
typedef long long s64;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

#define EULER 2.7182818

void print(vector<int> v) {
    printf("[");
    for (int i = 0; i < v.size(); i++) {
        printf(" %d", v[i]);
    }
    printf(" ]\n");
}

void print(int *v, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf(" ]\n");
}

void print(int **m, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

#define pos(l,c,la,ca) ((la) * (c) + ca)
#define lpos(l,c,a) ((a) / (c))
#define cpos(l,c,a) ((a) % (c))

struct seg_tree_t {
    vector<int> range;
    vector<int> v;
};

int build_seg_tree_rec(seg_tree_t *t, int p, int l, int r) {
    //printf("called with %d %d\n", l, r);
    if (l == r) {
        return t->v[l];
    }
    //printf(" %d %d\n", l, r);
    assert(r > l);

    int mid = (l + r) / 2;
    int a = build_seg_tree_rec(t, p * 2 + 1, l, mid);
    t->range[p * 2 + 1] = a;
    //printf("[%d](%d,%d) = %d\n", p * 2 + 1, l, mid, a);
    int b = build_seg_tree_rec(t, p * 2 + 2, mid + 1, r);
    t->range[p * 2 + 2] = b;
    //printf("[%d](%d,%d) = %d\n", p * 2 + 2, mid + 1, r, b);

    return max(a, b);
}

seg_tree_t build_seg_tree(vector<int> v, int l, int r) {
    seg_tree_t seg_tree;
    seg_tree.range.assign(4 * v.size(), 0);
    seg_tree.v = v;

    seg_tree.range[0] = build_seg_tree_rec(&seg_tree, 0, l, r);
    return seg_tree;
}

int query_seg_tree_rec(seg_tree_t *t, int p, int ql, int qr, int l, int r) {
    if (l >= ql && r <= qr) {
        //printf("p = %d\n", p);
        //printf("returned A %d %d %d\n", l, r, t.range[p]);
        return t->range[p];
    }

    if (l > qr || r < ql) {
        //printf("returned %d %d -1\n", l, r);
        return -1;
    }

    int a = query_seg_tree_rec(t, p * 2 + 1, ql, qr, l, (l + r) / 2);
    int b = query_seg_tree_rec(t, p * 2 + 2, ql, qr, (l + r) / 2 + 1, r);
    int m = max(a, b);
    //printf("returned B %d %d %d\n", a, b, m);

    return m;
}

int query_seg_tree(seg_tree_t *t, int ql, int qr) {
    //puts("--------------");
    return query_seg_tree_rec(t, 0, ql, qr, 0, t->v.size()-1);
}

void solve(vector<int> v) {
    
}

int main(int argc, char** argv) {
    int num_intervals, num_tests;
    vector<int> v;
    scanf(" %d %d", &num_intervals, &num_tests);

    for (int i = 0; i < num_intervals; i++) {
        int a;
        scanf(" %d", &a);
        v.push_back(a);
    }

    seg_tree_t seg_tree = build_seg_tree(v, 0, v.size()-1);
    //print(seg_tree.range);

    int count = 0;
    for (int i = 0; i < num_tests; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        int r = query_seg_tree(&seg_tree, a-1, b-2);
        //printf("a %d r %d\n", v[a-1], r);
        if (v[a-1] >= r) {
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}

