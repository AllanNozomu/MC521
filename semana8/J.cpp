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
#define allr(container) container.rbegin(), container.rend()
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

int main(){
    int T;
    cin >> T;
    pii bag[101][10001];

    while(T--){
        memset(bag, 0, sizeof(bag));
        int n, k;
        cin >> n >> k;

        vector<int> objs;
        
        for (int i = 0;  i < n; ++i){
            int q;
            cin >> q;
            objs.emplace_back(q);
        }

        int i, w;
        for ( i = 1 ; i < n + 1; ++i){
            for ( w = 1 ; w < k + 1; ++w){
                if (objs[i-1] > w){
                    bag[i][w] = bag[i - 1][w];
                } else {
                    if (bag[i - 1][w].first > bag[i - 1][w - objs[i - 1]].first + objs[i - 1] || 
                        (bag[i - 1][w].first == bag[i - 1][w - objs[i - 1]].first + objs[i - 1] && bag[i - 1][w].second < bag[i - 1][w - objs[i - 1]].second + 1)){
                        bag[i][w] = bag[i - 1][w];
                    } else {
                        bag[i][w].first = bag[i - 1][w - objs[i - 1]].first + objs[i - 1];
                        bag[i][w].second = bag[i - 1][w - objs[i - 1]].second + 1;
                    }
                }
            }
        }
        i = n;
        w = k;
        if (bag[i][w].first == k){
            cout << bag[i][w].second << endl;
        } else{
            cout << "impossible" << endl;
        }
    }
}