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
#include<time.h>

using namespace std;

typedef pair<int,int> pii;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

// clock_t t;
// void init_time(){
//     t = clock();
// }

// void check_time(){
//     t = clock() - t;
//     cout << "Time taken " << ((double)t)/CLOCKS_PER_SEC << "s" << endl ;
// }

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

int is_prime(int n){
    for (int i = 2; i < sqrt(n + 0.5f); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    
    int C, N;
    
    cin >> C >> N;
    while(C > 0 && N > 0){
        long int v[C];
        memset(v, -1, sizeof(v));
        vector<long int> entrada;
        vector<long int> resposta;
        long int soma = 0;

        for (int i = 0 ; i < N; ++i){
            int a;
            cin >> a;
            if (resposta.empty()){
                entrada.push_back(a);
                soma = (soma + a) % C;
                if (soma == 0){
                    for (int j = 0 ; j < i + 1; ++j){
                        resposta.push_back(j);
                    }
                    // Answer
                } else if (v[soma] == -1){
                    v[soma] = i;
                } else {
                    // Answer
                    for (int j = v[soma] + 1 ; j < i + 1; ++j){
                        resposta.push_back(j);
                    }
                }
            }
        }
        if (resposta.size() > 0){
            int first = 1;
            for (auto it = resposta.begin(); it != resposta.end(); ++it){
                if (first){
                    cout << * it + 1;
                    first = 0;
                } else {
                    cout << spc << * it + 1;
                }
                
            }
            cout << endl;
        } else {
            cout << "no sweets\n";
        }
        cin >> C >> N;
    }
    
}