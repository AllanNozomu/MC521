bool debug = false;

#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<bitset>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;

typedef unordered_map<int, int> umap_ii;
typedef unordered_map<int, pii> umap_ipii;
typedef unordered_map<int, string> umap_is;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

void print_pair(const pii & par){
    cout << "(" << par.first << spc << par.second << ")" << spc;
}

template <typename C>
void print_array(const C &data, int n){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (int i = 0; i < n; ++i){
        cout << data[i] << spc;
    }
    cout << endl;
}

template <typename C>
void print_container(const C &data){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (const auto &v : data){
        cout << v << spc;
    }
    cout << endl;
}

template <typename C>
void print_pairs(const C &data){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (const auto &v : data){
        print_pair(v);
    }
    cout << endl;
}

template <typename C>
void print_matrix(const C &data){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (const auto &row : data){
        for (const auto &v : row){
            cout << v << spc;
        } cout << endl;
    }
    cout << endl;
}


#define MAX 100000
#define LOGMAX 18

int query(const int matrix[MAX][LOGMAX], const ll data[MAX], int qs, int qe){
    int k = (int)log2(qe - qs + 1);
    if (data[matrix[qs][k]] < data[matrix[qe - (1 << k) + 1][k]])
        return matrix[qs][k];
    return matrix[qe - (1 << k) + 1][k];
}

void pre_process(int matrix[MAX][LOGMAX], const ll data[MAX], int n){
    for (int i = 0 ; i < n; ++i){
        matrix[i][0] = i;
    }
    for (int j = 1; (1 << j) <= n; ++j){
        for (int i = 0; i + (1 << j) - 1 < n; ++i){
            if (data[matrix[i][j-1]] < data[matrix[i + (1 << j - 1)][j-1]]){
                matrix[i][j] = matrix[i][j-1];
            } else {
                matrix[i][j] = matrix[i + (1 << j - 1)][j-1];
            }
        }
    }
}

ll process(int matrix[MAX][LOGMAX], const ll data[MAX], int qs, int qe){
    if (qs > qe){
        return 0;
    }
    if (qs == qe){
        return data[qs];
    }
    int mid = query(matrix, data, qs, qe);
    ll now = data[mid] * (qe - qs + 1);
    ll esq = process(matrix, data, qs, mid - 1);
    ll dir = process(matrix, data, mid + 1, qe);
    return max({now, dir, esq});
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    ll data[MAX];
    int matrix[MAX][LOGMAX];
    int n;

    cin >> n;
    while(n > 0){
        for (int i = 0 ; i < n; ++i){
            cin >> data[i];
        }
        pre_process(matrix, data, n);
        cout << process(matrix, data, 0, n - 1) << endl;

        cin >> n;
    }
}