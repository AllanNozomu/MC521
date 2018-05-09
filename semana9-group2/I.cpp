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
    vector<int> primes;

    for (int i = 2; i < 1000; ++i)
    {
        if (is_prime(i))
            primes.push_back(i);
    }
    int T = 1000;
    vector<int> respostas;

    for (int i = 30; T; ++i){
        vector<int> fator;
        for (int j = 0; j < primes.size() && i > primes[j]; ++j){
            if (i % primes[j] == 0){
                fator.push_back(primes[j]);
            }
            if (fator.size() >= 3){
                break;
            }
        }
        if (fator.size() >= 3){
            T--;
            respostas.push_back(i);
        }
    }


    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << respostas[n-1] << endl;
    }
}