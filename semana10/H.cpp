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
#define rall(container) container.rbegin(), container.rend()

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

int comp(pii f, pii s){
    return f.first > s.first;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int N, M;
    int first = 1;
    while(scanf("%d %d", &N, &M) > 0){
        if (!first)
            cout << endl;
        first = 0;
        int matrix[N][N];
        int res[N][N];
        for (int i = 0 ; i < N; ++i){
            for (int j = 0 ; j < N; ++j){
                scanf("%d", &matrix[i][j]);
            }
        }
        int total = 0;
        for (int i = 0; i <= N - M; ++i){
            for (int j = 0; j <= N - M; ++j){
                int sum = 0;
                for (int k = i; k - i < M; ++k){
                    for (int l = j; l - j < M; ++l){
                        sum += matrix[k][l];
                    }
                }
                cout << sum << endl;
                total += sum;
            }
        }
        cout << total << endl;
    }
}