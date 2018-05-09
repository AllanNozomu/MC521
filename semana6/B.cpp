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

    int N;
    cin >> N;
    vector<long> aux;
    vector<long> resposta;

    int n = 1, flag = 0;

    resposta.push_back(0);
    aux.push_back(0);

    for (int i = 1 ; i < 1000000; ++i){
        aux.push_back(aux[i-1] + n);
        resposta.push_back(resposta[i-1] + aux[i]);
        if (flag){
            n++;
        }
        flag = !flag;
    }
    while(N--){
        int n;
        cin >> n;
        
        cout << resposta[n - 3] << endl;
    }
}