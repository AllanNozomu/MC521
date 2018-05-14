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

int black[501], white[501];
int memo[501][501];

ll horses(int index, int k, int n){
    if (k == 0){
        return (black[n] - black[index - 1]) * (white[n] - white[index - 1]);
    }
    if (memo[index][k] != -1){
        return memo[index][k];
        
    }
    ll minimum = INT64_MAX;
    for (int i = 1; i <= n - index - k + 1; ++i){
        minimum = min(minimum, (black[index + i - 1] - black[index - 1]) * (white[index + i - 1] - white[index - 1]) + horses(index + i, k - 1, n));
    }
    memo[index][k] = minimum;
    return minimum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    memset(black, 0, sizeof(black));
    memset(white, 0, sizeof(white));
    memset(memo, -1, sizeof(memo));

    black[0] = white[0] = 0;
    for (int i = 1; i <= N; ++i){
        int q;
        cin >> q;
        if (q){
            black[i] = black[i - 1] + 1;
            white[i] = white[i - 1];
        } else {
            white[i] = white[i - 1] + 1;
            black[i] = black[i - 1];
        }
    }

    cout <<  horses(0, K - 1, N) << endl;

}
