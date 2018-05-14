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

int comp(pii s, pii f){
    if (s.first == f.first)
        return s.second < f.second;
    return s.first < f.first;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while(N > 0){
        vii pares;
        char mapa[N][N];

        for (int i = 0 ; i < N; ++i){
            string line;
            cin >> line;
            for (int j = 0 ; j < line.length(); ++j){
                if (line[j] == 'O'){
                    pii par;
                    par.first = i;
                    par.second = j;
                    pares.push_back(par);
                }
            }
        }
        for (int i = 0 ; i < N; ++i){
            string line;
            cin >> line;
            for (int j = 0 ; j < line.length(); ++j){
                mapa[i][j] = line[j];
            }
        }
        
        for (int i = 0; i < 4; ++i){
            for (const auto par : pares){
                printf("%c", mapa[par.first][par.second]);
            }
            for (int i = 0 ; i < pares.size(); ++i){
                pii aux = pares[i];
                pares[i].first = pares[i].second;
                pares[i].second = N - aux.first - 1;
            }
            sort(all(pares), comp);
        }
        printf("\n");
        cin >> N;
    }
}
