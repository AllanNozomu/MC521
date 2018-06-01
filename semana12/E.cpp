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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    string line;

    cin >> line;
    while(line != "END"){
        char mapa[15][15];
        char aux[15][15];
        int ans = 15;

        for (int i = 0 ; i < 15; ++i){
            for (int j = 0 ; j < line.size(); ++j){
                mapa[i][j] = line[j];
            }
            cin >> line;
        }
        for (int k = 0; k <= (1 << 15); ++k){
            bitset<15> mask = k;
            
            copy(&mapa[0][0], &mapa[14][15], &aux[0][0]);

            int rows = 0;
            for (int r = 0 ; r < 15; ++r){
                if (mask[r]){
                    ++rows;
                    memset(aux[r], '.', sizeof(aux[r]));
                }
            }
            int columns = 0;
            for (int c = 0 ; c < 15; ++c){
                for (int i = 0; i < 15; ++i){
                    if (aux[i][c] == '#'){
                        columns++;
                        break;
                    }
                }
            }
            if (columns <= rows){
                ans = min(ans, max(columns, rows));
            }
        }
        
        cout << ans << endl;
    } 
}
