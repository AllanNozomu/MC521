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

int board[100][100];
int N, M;
int ships = 0;
vi ship_sizes;

void paint(int i, int j){
    if (i < 0 || j < 0 || i >= N || j >= M){
        return;
    }
    if (board[i][j] != 0)
        return;
    ship_sizes[ships - 1]++;
    board[i][j] = ships;
    paint(i + 1, j);
    paint(i - 1, j);
    paint(i, j + 1);
    paint(i, j - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    char c;
    for (int i = 0 ; i < N; ++i){
        for (int j = 0 ; j < M; ++j){
            cin >> c;
            if (c == '.')
                board[i][j] = -1;
            else
                board[i][j] = 0;
        }
    }

    for (int i = 0 ; i < N; ++i){
        for (int j = 0 ; j < M; ++j){
            if (board[i][j] == 0){
                ships++;
                ship_sizes.emplace_back(0);
                paint(i, j);
            }
        }
    }

   
    int T;
    cin >> T;
    vii shots = vii(T);

    for (int i = 0 ; i < T; ++i){
        cin >> shots[i].first >> shots[i].second;
        shots[i].first--;
        shots[i].second--;
    }

    for (auto shot : shots){
        int ship = board[shot.first][shot.second];
        if (ship > 0){
            board[shot.first][shot.second] = 0;
            ship_sizes[ship-1]--;
        }
    }
    print_container(ship_sizes);
    int res = 0;
    for (int i = 0 ; i < ships; ++i){
        if (ship_sizes[i] == 0){
            res++;
        }
    }
    cout << res << endl;
}
