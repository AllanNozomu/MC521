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
typedef vector<string> vstr;
typedef vector<vector<int>> vvi;
typedef vector<vector<pii>> vvpii;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

clock_t t = clock();

void check_time(){
    if (!debug) return;
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
void print_container_pair(const C &data){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (const auto &v : data){
        print_pair(v);
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

vstr tokenizer(string s, const string &delimiter){
    vstr res;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        res.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    return res;
}


int N, H, M;
int graph[10000][10000];
vector<set<int>> vizs;
vector<set<int>> vizs_second;

vi hotels;
vi hotels_ids;
vi distances;
vi visited;
int res = -1;

void dfs(int index, int acumulado, int hotel){
    if (visited[index] || acumulado > 600){
        return;
    }
    if (hotels[index]){
        vizs_second[hotel].emplace(index);
        vizs_second[index].emplace(hotel);
    }
    visited[index] = 1;

    for (const auto viz : vizs[index]){
        dfs(viz, acumulado + graph[index][viz], hotel);
    }
    
    visited[index] = 0;
}

int djikstra(int index){
    auto cmp = [](pii left, pii right) { 
        return (left.first) > (right.first);
    };
    priority_queue< pii, vector<pii>, decltype(cmp)> q(cmp);

    q.push(mkp(0, index));
    distances = vi(N);

    for (int i = 0 ; i < N; ++i){
        distances[i] = -1;
    }
    distances[index] = 0;

    while(!q.empty()){
        pii d_u = q.top();
        int u = d_u.second;
        q.pop();
        visited[u] = 1;
        
        for (auto const v : vizs[u]){
            if (!visited[v])
                if ((distances[v] < 0 || distances[u] + graph[u][v] < distances[v]) && distances[u] + graph[u][v] <= 600){
                    if (hotels[v]){
                        vizs_second[v].emplace(index);
                        vizs_second[index].emplace(v);
                    }
                    distances[v] = distances[u] + graph[u][v];
                    q.push(mkp(distances[v], v));
                }
        }
    }
}

int djikstra2(){
    auto cmp = [](pii left, pii right) { 
        return (left.first) > (right.first);
    };
    priority_queue< pii, vector<pii>, decltype(cmp)> q(cmp);

    q.push(mkp(0, 0));
    distances = vi(N);

    for (int i = 0 ; i < N; ++i){
        distances[i] = -1;
    }
    distances[0] = 0;

    while(!q.empty()){
        pii d_u = q.top();
        int u = d_u.second;
        q.pop();
        visited[u] = 1;
        
        for (auto const v : vizs_second[u]){
            if (!visited[v])
                if (distances[v] < 0 || distances[u] + 1 < distances[v]){
                    distances[v] = distances[u] + 1;
                    q.push(mkp(distances[v], v));
                }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    while(N > 0){
        cin >> H;
        hotels = vi(N);
        hotels_ids = vi();
        for (int i = 0 ; i < H ; ++i){
            int h;
            cin >> h;
            h--;
            hotels_ids.emplace_back(h);
            hotels[h] = 1;
        }
        hotels[0] = hotels[N - 1] = 1;
        hotels_ids.emplace_back(0);
        hotels_ids.emplace_back(N-1);
        print_container(hotels);

        vizs = vector<set<int>>(N);
        vizs_second = vector<set<int>>(N);
        cin >> M;
        for (int i = 0 ; i < M; ++i){
            int s, d, p;
            cin >> s >> d >> p;
            s--;
            d--;
            
            if (vizs[s].count(d) == 0){
                graph[s][d] = p;
                graph[d][s] = p;
                vizs[s].emplace(d);
                vizs[d].emplace(s);
            } else
                graph[s][d] = min(graph[s][d], p);
                graph[d][s] = min(graph[d][s], p);
        }

        print_matrix(vizs);
        
        res = -1;

        for (auto hotel : hotels_ids){
            visited = vi(N);
            djikstra(hotel);
        }
        visited = vi(N);
        djikstra2();
        print_matrix(vizs_second);
        if (distances[N-1] > 0){
            cout << distances[N-1] - 1 << endl;
        } else{
            cout << distances[N-1] << endl;
        }
        
       

        cin >> N;
    }
}
