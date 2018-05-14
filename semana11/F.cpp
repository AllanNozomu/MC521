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

int visitado[100][100], N, M, k;
char mapa[100][100];
pii pos;
int certo = 0;

int chegou(int y, int x, int n){
    if (mapa[y][x] == '*'){
        return 0;
    }
    if (x < 0 || y < 0 || y > N - 1 || x > M - 1){
        return 0;
    }
    if (n >= k && pos.first == y && pos.second == x){
        if (!certo){
            printf("YES\n");
            certo = 1;
        }
        return 1;
    }
    if (visitado[y][x]){
        return 0;
    }

    visitado[y][x] = 1;

    int ret = chegou(y,x+1,n + 1) || chegou(y,x-1,n +  1) || chegou(y+1,x, n + 1) || chegou(y-1,x, n + 1);

    visitado[y][x] = 0;
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> k >> pos.first >> pos.second;

    pos.first--;
    pos.second--;

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cin >> mapa[i][j];
        }
    }

    memset(visitado, 0, sizeof(int[100][100]));
    chegou(pos.first, pos.second, 0);
    if (!certo){
        printf("NO\n");
    }
}
