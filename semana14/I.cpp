bool debug = true;

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
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<pii>> vvii;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

clock_t t = clock();
void check_time(){
    t = clock() - t;
    cout << "Time taken " << ((double)t)/CLOCKS_PER_SEC << "s" << endl ;
}

void print_pair(const pii & par){
    if (!debug) return;
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, P;
    vi times;
    vi time_paint;

    cin >> N >> P;
    times = vi(P);
    time_paint = vi(P);

    for (int i = 0 ; i < N; ++i){
        for (int j = 0 ; j < P; ++j){
            cin >> time_paint[j];

            int now = 0;
            if (j > 0){
                now = times[j-1];
            }
            times[j] = max(now + time_paint[j], times[j] + time_paint[j]);
        }
        cout << times[P - 1] << spc;
    }cout << endl;
}
