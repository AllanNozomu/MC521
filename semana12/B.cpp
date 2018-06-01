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
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

template <typename C>
void printa(const C &a){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    cout << a << endl;
}

template <typename C, typename D>
void print_pair(const pair<C,D> & par){
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

int board[10][10];
int reached[10][10];
int ans = 0, R;

void solve(int r, int c, int distance){
    if (r < 0 || c < 0 || r >= 10 || c >= 10){
        ans = max(ans, distance);
        return;
    }
    if (!board[r][c] || reached[r][c]){
        ans = max(ans, distance);
        return;
    }
    reached[r][c] = 1;
    distance++;
    solve(r-2, c-1, distance);
    solve(r-2, c+1, distance);
    solve(r-1, c-2, distance);
    solve(r-1, c+2, distance);
    solve(r+1, c-2, distance);
    solve(r+1, c+2, distance);
    solve(r+2, c-1, distance);
    solve(r+2, c+1, distance);
    reached[r][c] = 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ini, tiles, ncase = 1;
    cin >> R;
    while(R > 0){
        memset(board, 0, sizeof(board));
        memset(reached, 0, sizeof(reached));
        tiles = ans = 0;

        for (int i = 0; i < R; ++i){
            int a, b;
            cin >> a >> b;
            if (i == 0){
                ini = a;
            }
            
            for (int j = a; j < a + b; ++j){
                board[i][j] = 1;
            }
            tiles += b;
        }

        solve(0,ini,0);
        if (tiles - ans == 1)
            printf("Case %d, %d square can not be reached.\n", ncase++, tiles - ans);
        else
            printf("Case %d, %d squares can not be reached.\n", ncase++, tiles - ans);

        cin >> R;
    }
}
