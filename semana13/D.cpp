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
#define rall(container) container.rbegin(), container.rend()

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

    int T;
    scanf("%d", &T);
    for (int t = 0 ; t < T; ++t){
        int N;
        vi red;
        vi blue;
        scanf("%d", &N);
        for (int i = 0 ; i < N; ++i){
            int l;
            char c;
            scanf("%d%c ", &l, &c);
            if (c == 'R'){
                red.push_back(l);
            } else {
                blue.push_back(l);
            }
        }
        sort(rall(red));
        sort(rall(blue));

        ll res = 0;
        int i;
        if (red.size() > blue.size()){
            for ( i = 0; i < blue.size(); ++i){
                res += red[i] + blue[i] - 2;
            }
        } else {
            for ( i = 0; i < red.size(); ++i){
                res += red[i] + blue[i] - 2;
            }
        }
        printf("Case #%d: %lld\n", t + 1, res);
        
    }
    
}
