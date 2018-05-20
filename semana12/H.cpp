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
    string str;
    std::getline(std::cin, str);
    T = stoi(str);

    std::getline(std::cin, str);
    while(T--){
        vi vet = vi();
        int N = 0, num;

        std::getline(std::cin, str);
        while(!str.empty()){
            vet.emplace_back(stoi(str));
            
            ++N;
            std::getline(std::cin, str);
        }
        vi dp = vi(N);
        vi dpi = vi(N);

        for (int i = 0 ; i < N; ++i){
            int index = -1;
            for (int j = 0; j < i; ++j){
                if (vet[i] >= vet[j]){
                    if (index < 0 || dp[index] < dp[j])
                        index = j;
                }
            }
            if (index < 0){
                dp[i] = 1;
                dpi[i] = -1;
            } else {
                dp[i] = dp[index] + 1;
                dpi[i] = index;
            }
        }
        int resp = 0;
        for (int i = 0 ; i < N; ++i){
            if (dp[resp] < dp[i]){
                resp = i;
            }
        }
        printf("Max hits: %d\n", dp[resp]);
        vi misseis;
        misseis.push_back(vet[resp]);
        for (int u = dpi[resp]; u != -1; u = dpi[u]){
            misseis.push_back(vet[u]);
        }
        for (auto it = misseis.rbegin(); it != misseis.rend(); ++it){
            printf("%d\n", *it);
        }
        if (T > 0){
            printf("\n");
        }
    }
}
