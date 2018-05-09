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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int not_city [100001];
    map<int, vector<pii>> g;
    vector<int> flour;

    memset(not_city, 0, sizeof(not_city));

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0 ; i < m; ++i){
        long o, d, l;
        cin >> o >> d >> l;

        g[o].push_back(make_pair(d,l));
        g[d].push_back(make_pair(o,l));
    }
    for (int i = 0; i < k; ++i){
        int c;
        cin >> c;
        not_city[c] = 1;
        flour.push_back(c);
    }
    long resposta = -1;
    for (auto it = flour.begin(); it!= flour.end(); ++it){
        for (auto par = g[*it].begin(); par != g[*it].end(); ++par){
            if (not_city[par->first] == 0 && (par->second < resposta || resposta < 0)){
                resposta = par->second;
            }
        }
    }
    cout << resposta << endl;
}