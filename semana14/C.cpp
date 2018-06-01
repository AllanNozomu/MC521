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

int N, M;
int graph[100][100];
int ships = 0;
vi distances;
vi visited;
vector<set<int>> vizs;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, U, L, R, D;
    cin >> M >> N;
    cin >> U >> L >> R >> D;

    vs strs = vs(M);
    for (int i = 0 ; i < M; ++i){
        cin >> strs[i];
    }
    
    char board[M + U + D][N + L + R];

    for (int i = 0; i < M + U + D; ++i){
        for (int j = 0 ; j < N + L + R; ++j){
            if ((i + j) % 2){
                board[i][j] = '.';
            } else {
                board[i][j] = '#';
            }
        }
    }
    
    for (int s = 0; s < strs.size(); ++s){
        for (int i = 0; i < strs[s].length(); ++i){
            board[U+s][L+i] = strs[s][i];
        }
    }
    for (int i = 0; i < M + U + D; ++i){
        for (int j = 0 ; j < N + L + R; ++j){
            cout << board[i][j];
        }cout << endl;
    }
}
