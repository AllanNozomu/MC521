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

int dist;
int city;
vi visited;
vvi graph;

void DFS(int index, int size){
    if (visited[index]){
        if (size > dist){
            dist = size;
            city = index;
        }
        return;
    }
    visited[index] = 1;
    for (int i = 0 ; i < graph[index].size(); ++i){
        DFS(graph[index][i], size + 1); 
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    while(N > 0){
        visited = vi(N);
        dist = 0;
        graph = vvi(N);

        for (int i = 1 ; i < N; ++i){
            int n;
            cin >> n;
            n--;
            graph[i].push_back(n);
            graph[n].push_back(i);
        }
        DFS(0, 1);

        visited = vi(N);
        dist = 0;
        DFS(city, 1);
        
        cout << dist / 2 << endl;
        cin >> N;
    }
}
