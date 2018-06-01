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
typedef vector<string> vstr;
typedef vector<vector<int>> vvi;
typedef vector<vector<pii>> vvpii;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

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

template <typename C>
void print_matrix_pair(const C &data){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (const auto &row : data){
        for (const auto &v : row){
            print_pair(v);
        } cout << endl;
    }
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    int amigos[50][50];
    int resp[50];
    cin >> T;
    while(T--){
        string str;
        cin >> str;
        int count = 0;
        for (const auto c : str){
            if (c == 'Y'){
                amigos[0][count] = 1;
                count ++;
            } else if (c == 'N'){
                
                amigos[0][count] = 0;
                count ++;
            }
        }
        int Q = count;
        for (int i = 1; i < Q; ++i){
            cin >> str;
            int count = 0;
            for (const auto c : str){
                if (c == 'Y'){
                    
                    amigos[i][count] = 1;
                    count ++;
                } else if (c == 'N'){
                    
                    amigos[i][count] = 0;
                    count ++;
                }
            }
        }

        memset(resp, 0, sizeof(resp));
        for (int i = 0; i < Q; ++i){
            for (int j = 0 ; j < Q; ++j){
                if (i != j && amigos[i][j] == 0){
                    for (int k = 0 ; k < Q; ++k){
                        if (amigos[j][k] == 1 && amigos[i][k] == 1){
                            resp[j] ++;
                            break;
                        }
                    }
                }
            }
        }
        int index = 0;
        for (int i = 1 ; i < Q; ++i){
            if (resp[index] < resp[i]){
                index = i;
            }
        }
        cout << index << ' ' << resp[index] << endl;
    }
}
