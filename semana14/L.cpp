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

int N, M;
int graph[100][100];
int ships = 0;
vi distances;
vi visited;
vector<set<int>> vizs;

int djikstra(int index){
    auto cmp = [](pii left, pii right) { 
        return (left.first) > (right.first);
    };
    priority_queue< pii, vector<pii>, decltype(cmp)> q(cmp);

    q.push(mkp(0, index));
    distances = vi(N);
    visited = vi(N);

    for (int i = 0 ; i < N; ++i){
        distances[i] = -1;
    }
    distances[index] = 0;
    int high = 0;

    while(!q.empty()){
        pii d_u = q.top();
        int u = d_u.second;
        q.pop();
        visited[u] = 1;
        high = max(high, distances[u]);
        
        for (auto const v : vizs[u]){
            if (!visited[v])
                if (distances[v] < 0 || distances[u] + graph[u][v] < distances[v]){
                    distances[v] = distances[u] + graph[u][v];
                    q.push(mkp(distances[v], v));
                }
        }
    }
    return high;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vizs = vector<set<int>>(N);
    for (int i = 0 ; i < M; ++i){
        int s, d, p;
        cin >> s >> d >> p;
        
        if (vizs[s].count(d) == 0){
            graph[s][d] = p;
            graph[d][s] = p;
            vizs[s].emplace(d);
            vizs[d].emplace(s);
        } else
            graph[s][d] = min(graph[s][d], p);
            graph[d][s] = min(graph[d][s], p);
    }
    int res = -1;
    for (int i = 0 ; i < N; ++i){
        int d_res = djikstra(i);
        res = (res < 0) ? d_res : min(res, d_res);
    }
    cout << res << endl;
}
