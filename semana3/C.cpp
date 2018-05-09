bool debug = true;

#include<vector>
#include<stack>
#include<map>
#include<bitset>
#include<unordered_map>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<limits.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

#define MID (ss + se) / 2
#define LEFT 2 * si + 1
#define RIGHT 2 * si + 2
#define IS_LEAF ss == se

typedef struct node{
    ll seg_sum = INT_MIN, total_sum = 0, pre_sum = INT_MIN, pos_sum = INT_MIN;
} node;

node get_sum(const vector<node> &st, int ss, int se, int qs, int qe, int si){
    if (qs <= ss && se <= qe)       // In range
        return st[si];

    if (qs > se || qe < ss){         // Out of range
        node nullnode;
        return nullnode;
    }
    
    node left = get_sum(st, ss, MID, qs, qe, LEFT),
        right = get_sum(st, MID + 1, se, qs, qe, RIGHT);

    node res;
    res.total_sum = left.total_sum + right.total_sum;
    res.seg_sum = max({left.seg_sum, right.seg_sum, left.pos_sum + right.pre_sum});
    res.pre_sum = max(left.pre_sum, left.total_sum + right.pre_sum);
    res.pos_sum = max(right.pos_sum, right.total_sum + left.pos_sum);

    return res;
}

ll get_sum(const vector<node> &st, int n, int qs, int qe){
    return get_sum(st, 0, n - 1, qs, qe, 0).seg_sum;
}

node construct_segtree(vector<node> &st, const vector<int> &arr, int ss, int se, int si){
    if (IS_LEAF){
        st[si].total_sum = arr[ss];                  
        st[si].seg_sum = arr[ss];                  
        st[si].pre_sum = arr[ss];                    
        st[si].pos_sum = arr[ss];               
    } else {
        node left = construct_segtree(st, arr, ss, MID, LEFT),
        right = construct_segtree(st, arr, MID + 1, se, RIGHT);

        st[si].total_sum = left.total_sum + right.total_sum;
        st[si].seg_sum = max({left.seg_sum, right.seg_sum, left.pos_sum + right.pre_sum});
        st[si].pre_sum = max(left.pre_sum, left.total_sum + right.pre_sum);
        st[si].pos_sum = max(right.pos_sum, right.total_sum + left.pos_sum);
    }
    
    return st[si];
}

void construct_segtree(vector<node> &st, const vector<int> &arr){
    int x = (int)(ceil(log2(arr.size())));  // log2(n)
    int max_size = 2 * (int)pow(2, x) - 1;  // Max size = 2 * log2(n) - 1
    st = vector<node>(max_size);

    construct_segtree(st, arr, 0, arr.size() - 1, 0);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    vector<int> input;
    vector<node> st;
    int n;
    cin >> n;
    for (int i = 0 ; i < n; ++i){
        int q;
        cin >> q;
        input.emplace_back(q);
    }
    construct_segtree(st, input);

    int m;
    cin >> m;
    while(m--){
        int i, j;
        cin >> i >> j;
        cout << get_sum(st, n, i-1, j-1) << endl;
    }
}