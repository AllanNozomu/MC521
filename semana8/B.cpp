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

map <pair <pii, int>, int> vals;

int bee(pii pos, int n){
    if (n == 0){
        return pos.first == pos.second && pos.second == 0;
    }
    if (vals[mkp(pos, n)] < 0){
        return 0;
    }
    if (vals[mkp(pos, n)] > 0){
        return vals[mkp(pos, n)];
    }
    int val = bee( make_pair(pos.first,pos.second+2), n-1) + 
            bee(mkp(pos.first, pos.second-2), n-1) + 
            bee(mkp(pos.first+1, pos.second+1), n-1) + 
            bee(mkp(pos.first-1, pos.second+1), n-1) + 
            bee(mkp(pos.first+1, pos.second-1), n-1) + 
            bee(mkp(pos.first-1, pos.second-1), n-1);
    vals[mkp(pos, n)] = val;
    return val;
}

int main()
{
    // for (int i = 1; i <= 14; ++i){
    //     cout << bee(mkp(0,0), i) << endl;
    // }
    int results[15] = {
        0,
        6,
        12,
        90,
        360,
        2040,
        10080,
        54810,
        290640,
        1588356,
        8676360,
        47977776,
        266378112,
        1488801600
    };
    int T;
    cin >> T;
    while(T--){
        int q;
        cin >> q;
        cout << results[q-1] << endl;
    }
}