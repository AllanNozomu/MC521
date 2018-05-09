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

int N, M;
char mapa[1000][1000];
int visited[1000][1000];
int traps[1000][1000];
int q = 0;

void compute(int i, int j){
    if (traps[i][j])
        return;
    if (visited[i][j]){
        ++q;
        traps[i][j] = 1;
        return;
    }
    if (i < 0 || j < 0 || i >= N || j >= M){
        ++q;
        return;
    }
    visited[i][j] = 1;
    if (mapa[i][j] == 'S'){
        compute(i+1, j);
    } else if (mapa[i][j] == 'E'){
        compute(i, j+1);
    } else if (mapa[i][j] == 'W'){
        compute(i, j-1);
    } else {
        compute(i-1, j);
    }
    visited[i][j] = 0;
    traps[i][j] = 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    scanf("%d %d ", &N, &M);
    for (int i = 0 ; i < N ; ++ i){
        for(int j = 0 ; j < M; ++j){
            scanf("%c", &mapa[i][j]);
        }scanf(" ");
    }
    memset(visited, 0, sizeof(visited));
    memset(traps, 0, sizeof(visited));

    for (int i = 0 ; i < N ; ++ i){
        for(int j = 0 ; j < M; ++j){
            compute(i, j);
        }
    }
    cout << q << endl;
}