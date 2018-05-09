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

template<class T>
const T& mmin(const T &f){
    return f;
}

template<class T, typename ... REST>
const T& mmin(const T &f, const REST&... rest){
    return min(f, mmin(rest...));
}

template<class T>
const T& mmax(const T &f){
    return f;
}

template<class T, typename ... REST>
const T& mmax(const T &f, const REST&... rest){
    return max(f, mmax(rest...));
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int n;
    int T;
    cin >> T;
    
    while(T--){
        cin >> n;
        int sum = 0;
        vector<int> input;
        int minimo = 10000;

        for (int i = 0 ; i < n; ++i){
            int q;
            cin >> q;
            minimo = min(minimo, q);
            input.emplace_back(q);
        }
        int printou = 0;
        for (int i = minimo; i > 1; --i){
            int flag = 1;
            for (int j = 0; j < input.size() && flag; ++j){
                if (input[j] % i != 0){
                    flag = 0;
                }
            }
            if (flag){
                for (int j = 0; j < input.size(); ++j){
                    cout << input[j] / i << spc;
                } cout << endl;
                printou = 1;
                break;
            }
        }
        if (!printou){
            for(const auto v : input)
                cout << v << spc;
            cout << endl;
        }
        
    }
}