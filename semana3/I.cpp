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

typedef struct {
    int pai;
    int qtde;
} animal;

animal sets[5000];

int find_set(int i){
    if (sets[i].pai != i)
        sets[i].pai = find_set(sets[i].pai);
    return sets[i].pai;
}

int union_set(int i, int j){
    sets[i].pai = sets[j].pai;
    sets[i].qtde += sets[j].qtde;
    sets[j].qtde = sets[i].qtde;
    return sets[i].qtde;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int C, R;

    cin >> C >> R;
    
    
    while(C > 0){
        map<string, int> mapa;
        
        string presa, predador, a;
        int m = 1, n;
        
        for (int i = 0 ; i < C; ++i){
            cin >> a;
            mapa[a] = i;
            sets[i].pai = i;
            sets[i].qtde = 1;
        }
        
        for (int i = 0 ; i < R; ++i){
            cin >> presa >> predador;
            int ipresa, ipredador;
            ipresa = find_set(mapa[presa]);
            ipredador = find_set(mapa[predador]);

            if (ipresa != ipredador){
                n = union_set(ipresa, ipredador);
                m = max(n,m);
            }
        }
        
        cout << m << endl;
        cin >> C >> R;
    }
}