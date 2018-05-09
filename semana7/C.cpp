bool debug = true;

#include<vector>
#include<stack>
#include<deque>
#include<map>
#include<bitset>
#include<unordered_map>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

using namespace std;

typedef pair<int,int> pii;

#define spc " "
#define all(container) container.begin(), container.end()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(container.begin(), container.end(), element) != container.end())

void deb_aux() {
    std::cout<<std::endl;
}

template<typename T, typename ... REST>
void deb_aux(T arg, const REST&... rest) {
    std::cout << arg << spc;
    deb_aux(rest...);
}

template<typename ... REST>
void deb(REST&... rest) {
    if (!debug)
        return;
    std::cout << "[DEBUG]";
    deb_aux(rest...);
}

template<typename T>
void deb_arr(const T arr[], const int &n) {
    if (!debug)
        return;
    std::cout << "[DEBUG ARR]";
    for(int i = 0 ; i < n; ++i){
        cout << arr[i] << spc;
    }
    cout << endl;
}

template<typename T>
void deb_vec(const vector<T> &vec) {
    if (!debug)
        return;
    std::cout << "[DEBUG VEC]";
    for (auto it = vec.begin(); it != vec.end(); ++it){
        cout <<  *it << spc;
    }
    cout << endl;
}

int is_prime(const int &n){
    if (n  == 0){
        return 0;
    }
    return (n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23 || n == 29 || n == 31);
}

vector<vector <int> > graph;
bitset<17> visited;
deque<int> ring;
vector<vector< vector<int> >> results;

int DFS(const int &n, const int &N){
    visited.set(n);
    ring.push_back(n);
    if (visited.count() == N && graph[n][0] == 1){
        vector<int> result;
        for (auto it = ring.begin(); it != ring.end(); ++it){
            result.push_back(*it);
        }
        results[N/2].push_back(result);
    } else {
        for (auto it = graph[n].begin(); it != graph[n].end() && *it <= N; ++it){
            if (visited[*it] == 0){
                DFS(*it, N);
            }
        }
    }
    visited.reset(n);
    ring.pop_back();
}

int main()
{
    
    graph.push_back(vector<int>());
    for (int i = 1 ; i <= 16; ++i){
        graph.push_back(vector<int>());
    }
    for (int i = 1 ; i <= 16; ++i){
        for (int j = i + 1; j <=16; ++j){
            if (is_prime(i + j)){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    // for (auto it = graph.begin(); it != graph.end(); ++it){
    //     for (auto it2 = it->begin(); it2!=it->end(); ++it2){
    //         cout << spc << *it2;
    //     }
    //     cout << endl;
    // }
    results.push_back(vector<vector<int>>());
    results[0].push_back(vector<int>());
    results[0][0].push_back(1);
    for (int i = 2 ; i <= 16; i +=2){
        results.push_back(vector<vector<int>>());
        DFS(1, i);
    }
    int n = 1;
    int t = 0;
    int q, p = 0;
    while(scanf("%d\n", &n) == 1){
        if (p)
            cout << endl;
        cout << "Case " << ++t << ":" << endl;
        if (n % 2 == 0){
            for (auto it = results[n/2].begin(); it != results[n/2].end(); ++it){
                q = 0;
                for (auto it2 = it->begin(); it2 != it->end(); ++it2, ++q){
                    if (q < n - 1){
                        cout << *it2 << spc;
                    } else {
                        cout << *it2;
                    }
                }
                cout << endl;
            }
        }
        p = 1;   
    }
    return 0;
}