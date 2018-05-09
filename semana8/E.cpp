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

#define mkp(a,b) make_pair(a,b)
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

char mapa[100][100];

void paint(pii pos, int n, int m){
    if (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= m || mapa[pos.first][pos.second] == '*')
        return;
    mapa[pos.first][pos.second] = '*';
    paint(mkp(pos.first-1, pos.second-1), n, m);
    paint(mkp(pos.first-1, pos.second), n, m);
    paint(mkp(pos.first-1, pos.second+1), n, m);
    paint(mkp(pos.first, pos.second-1), n, m);
    paint(mkp(pos.first, pos.second+1), n, m);
    paint(mkp(pos.first+1, pos.second-1), n, m);
    paint(mkp(pos.first+1, pos.second), n, m);
    paint(mkp(pos.first+1, pos.second+1), n, m);
}

int main()
{
    int n, aux;
    int q = 0;
    cin >> n;
    for (int i = 1 ; i <= n/2 + 1; ++i){
        aux = n;
        aux -= i * i;
        if (aux >= 0){
            q++;
        }
        while(aux > 0){
            aux -= i;
            if (aux >= 0){
                q++;
            }
        }
    }
    cout << q << endl;
}