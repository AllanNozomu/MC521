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
#include <functional>
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

int N, M, Q;
vi visited;
vi distances;
vvpii graph;

int djikstra(int index){
    auto cmp = [](pii left, pii right) { 
        return (left.first) > (right.first);
    };
    priority_queue< pii, vector<pii>, decltype(cmp)> q(cmp);

    q.push(mkp(0, index));

    for (int i = 0 ; i < N; ++i){
        distances[i] = -1;
    }
    distances[index] = 0;

    while(!q.empty()){
        pii u = q.top();
        q.pop();
        visited[u.second] = 1;
        

        for (auto const v : graph[u.second]){
            if (!visited[v.second])
                if (distances[v.second] < 0 || distances[u.second] + v.first < distances[v.second]){
                    distances[v.second] = distances[u.second] + v.first;
                    q.push(mkp(distances[v.second], v.second));
                }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> Q;
    graph = vvpii(N);

    for (int i = 0 ; i < M; ++i){
        int s, d, p;
        cin >> s >> d >> p;
        if (s != d){
            graph[s].emplace_back(mkp(p, d));
            graph[d].emplace_back(mkp(p, s));
        }
    }

    for (int i = 0 ; i < Q; ++i){
        int q;
        cin >> q;

        distances = vi(N);
        visited = vi(N);
        djikstra(q);

        int index = -1;
        int qty = 1;

        for (int i = 0 ; i < N; ++i){
            if (index < 0 || distances[index] < distances[i]){
                index  = i;
                qty = 1;
            } else if (distances[index] == distances[i]){
                qty ++;
            }
        }
        cout << distances[index] << spc << qty << endl;
    }
}
