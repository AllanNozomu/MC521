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

int visited[10000];
int val = 0;
int farest = -1;
vvi graph;

void DFS(int index, int distance){
    visited[index] = 1;
    for (auto const v : graph[index]){
        if (!visited[v]){
            DFS(v, distance + 1);
        }
    }
    if (val < distance){
        val = distance;
        farest = index; 
    }
    visited[index] = 0;
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, s, d;
    cin >> N;
    for (int i = 0 ; i < N; ++i){
        graph.push_back(vi());
    }
    memset(visited, 0, sizeof(visited));

    while(--N){
        cin >> s >> d;
        graph[s-1].push_back(d-1);
        graph[d-1].push_back(s-1);
    }
    DFS(0, 0);

    val = 0;
    memset(visited, 0, sizeof(visited));
    DFS(farest, 0);

    cout << val << endl;
}
