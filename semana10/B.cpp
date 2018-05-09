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

        unordered_map<int, int> differents;
        vector<int>v;

        int sum = 0;
        for (int i = 0; i < n; ++i){
            int q;
            cin >> q;

            int s = v.size();
            for (int i = 0 ; i < s; ++i){
                if (differents[q + v[i]] == 0){
                    sum += q + v[i];
                    v.emplace_back(q + v[i]);
                    differents[q + v[i]] = 1;
                }
            }

            if (differents[q] == 0){
                sum += q;
                v.emplace_back(q);
                differents[q] = 1;
            }

        }
        cout << sum << endl;
    }
}