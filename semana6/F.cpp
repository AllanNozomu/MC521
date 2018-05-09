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

vector<int> stalls;

int funcionou(int m, int c){
    int last = stalls[0];
    c--;
    for (auto it = stalls.begin(); it != stalls.end(); ++it){
        
        if (*it - last >= m)
        {
            last = *it;
            if (--c == 0){
                return m;
            }
        }
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    
    int N;
    cin >> N;
    while(N--){
        int S, C, s;

        cin >> S >> C;
        stalls.clear();
        for (int i = 0 ; i < S; ++i){
            cin >> s;
            stalls.push_back(s);
        }
        sort(all(stalls));
        int ini = stalls[0], fim = stalls[stalls.size()-1];
        int meio;
        int r, resposta;
        while(ini < fim){
            meio = ini +(fim - ini)/2;
            r = funcionou(meio, C);
            if(r){
                ini = meio+1;
                resposta = r;
            } else {
                fim = meio;
            }
        }
        cout << resposta << endl;
    }
}