bool debug = true;

#include<vector>
#include<stack>
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

void deb_aux() {
    std::cout<<std::endl;
}

template<typename T, typename ... REST>
void deb_aux(T arg, const REST&... rest) {
    std::cout << arg << " ";
    deb_aux(rest...);
}

template<typename ... REST>
void deb(REST&... rest) {
    if (!debug)
        return;
    std::cout << "[DEBUG]";
    deb_aux(rest...);
}

typedef pair<int,int> pii;

#define spc " "
#define all(container) container.begin(), container.end()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(container.begin(), container.end(), element) != container.end())

int visited[5000];
int MAXIMUM = 0;
set<int> candidates;
vector<vector<int>> graph;

pii DFS(const int &i, const int &father, const int &time){
    visited[i] = father;
    pii maximum = make_pair(i, time);
    for (auto it = graph[i].begin(); it != graph[i].end(); ++it){
        if (visited[*it] < 0){
            pii result = DFS(*it, i, time + 1);
            if (MAXIMUM < result.second){
                MAXIMUM = result.second;
                candidates.clear();
                candidates.emplace(result.first);
            } else if (MAXIMUM == result.second)
                candidates.emplace(result.first);
        }
    }

    return maximum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int N, q, d;

    while(cin >> N){
        graph.clear();
        

        for (int i = 0; i < N; ++i){
            graph.push_back(vector<int>());
        }
        for (int i = 0; i < N; ++i){
            int q;
            cin >> q;

            for (int j = 0 ; j < q; ++j){
                cin >> d;
                graph[i].push_back(d-1);
                graph[d-1].push_back(i);
            }
        }
        set<int> worst;
        set<int> best;

        // Acha os candidatos
        candidates.clear();
        memset(visited, -1, sizeof(visited));
        MAXIMUM = 0;
        DFS(0, 0, 0);
        int candidate = *candidates.begin();

        // Acha os piores de um lado
        candidates.clear();
        memset(visited, -1, sizeof(visited));
        MAXIMUM = 0;
        DFS(candidate, candidate, 0);

        for (auto it = candidates.begin(); it != candidates.end(); ++it){
            int good = visited[*it];
            for (int i = 1 ; i < MAXIMUM / 2; ++i){
                good = visited[good];
            }
            best.emplace(good);
            worst.emplace(*it);
        }

        // Acha os piores do outro lado
        candidate = *candidates.begin();
        candidates.clear();
        memset(visited, -1, sizeof(visited));
        MAXIMUM = 0;
        DFS(candidate, candidate, 0);

        for (auto it = candidates.begin(); it != candidates.end(); ++it){
            int good = visited[*it];
            for (int i = 1 ; i < MAXIMUM / 2; ++i){
                good = visited[good];
            }
            best.emplace(good);
            worst.emplace(*it);
        }
        
        cout << "Best Roots  : ";
        int i = 0;
        for (auto it = best.begin(); it != best.end(); ++i, ++it){
            if (i == best.size() - 1)
                cout << *it + 1;
            else
                cout << *it + 1 << spc;
        } cout << endl;
        cout << "Worst Roots : ";
        i = 0;
        for (auto it = worst.begin(); it != worst.end(); ++i, ++it){
            if (i == worst.size() - 1)
                cout << *it + 1;
            else
                cout << *it + 1 << spc;
        } cout << endl;
    }
}