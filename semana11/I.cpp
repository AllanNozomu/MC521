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

int N, M;
vvi graph, pieces, rGraph, resp;
vi visited, parent, L, R;

void paint(int index, int distance){
    if (distance % 2){
        L.emplace_back(index);
    } else {
        R.emplace_back(index);
    }
    
    visited[index] = 1;
    for (auto v : graph[index]){
        if (!visited[v])
            paint(v, distance + 1);
    }
}

int bfs(){
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    parent[0] = -1; 

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for (auto v : rGraph[u]){
            if (!visited[v]){
                q.push(v);
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
    print_container(visited);
    return visited[M * N + 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    pieces = vvi(N, vi(M));

    for (int i = 0; i < N; ++i){
        for (int j = 0 ; j < M; ++j){
            cin >> pieces[i][j];
        }
    }
    print_matrix(pieces);

    // Graph
    graph = vvi(M * N + 2);

    for (int i = 0; i < N; ++i){
        for (int j = 0 ; j < M; ++j){
            if (i > 0){
                if (pieces[i][j] != pieces[i-1][j]){
                    graph[i * M + j + 1].push_back((i - 1) * M + j + 1);
                    graph[(i - 1) * M + j + 1].push_back(i * M + j + 1);
                }
            }
            if (j > 0){
                if (pieces[i][j] != pieces[i][j - 1]){
                    graph[i * M + j + 1].push_back(i * M + j);
                    graph[i * M + j].push_back(i * M + j + 1);
                }
            }
        }
    }

    visited = vi(M * N + 2);
    parent = vi(M * N + 2);
    print_matrix(graph);

    for (int i = 0 ; i < M * N; ++i){
        if (!visited[i + 1]){
            paint(i + 1, 0);
        }
    }

    print_container(L);
    print_container(R);
    
    rGraph = vvi(M * N + 2);
    for (const auto l : L){
        rGraph[0].emplace_back(l);
        for (const auto r : graph[l]){
            rGraph[l].emplace_back(r);
        }
    }
    for (const auto r : R){
        rGraph[r].emplace_back(M * N + 1);
    }

    print_matrix(rGraph);

    visited = vi(M * N + 2);
    while(bfs()){
        int u, v;
        for (v = M * N + 1; v != 0; v = parent[v])
        {
            u = parent[v];
            rGraph[u].erase(find(all(rGraph[u]), v));
            rGraph[v].emplace_back(u);

            print_pair(mkp(v, u));
        } print_pair(mkp(-1, -1));
 
        visited = vi(M * N + 2);
        print_matrix(rGraph);
    }

    int cont = 1;
    resp = vvi(N, vi(M));
    for (const auto v : rGraph[M * N + 1]){
        for (const auto u : rGraph[v]){
            resp[(v-1) / M][(v-1) % M] = cont;
            resp[(u-1) / M][(u-1) % M] = cont;
            ++cont;
            break;
        }
    }
    for (const auto r : resp){
        for (const auto c : r){
            printf("%d ", c);
        }
        printf("\n");
    }
}
