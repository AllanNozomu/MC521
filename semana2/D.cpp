#include<vector>
#include<stack>
#include<map>
#include<bitset>
#include<unordered_map>
#include<queue>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

using namespace std;

void deb_aux() {
    std::cout<<std::endl;
}

template<typename T, typename ... REST>
void deb_aux(T arg, const REST&... rest) {
    std::cout << arg << " ";
    deb_aux(rest...);
}

template<typename ... REST>
void deb(REST&... rest) {
    std::cout << "[DEBUG]";
    deb_aux(rest...);
}

template<typename T>
void deb_vec(T t[], int n){
    std::cout << "[DEBUG] vector ";
    for (int i = 0 ; i < n ; ++ i){
        cout << t[i] << " ";
    }
    cout << endl;
}

#define all(container) container.begin(), container.end()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(container.begin(), container.end(), element) != container.end())

int parent(const int parents[], const int &id){
    if (parents[id] == -1)
        return id;
    return parent(parents, parents[id]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int n, m, i = 0;

    cin >> n >> m;

    while(n != 0 || m != 0){
        int parents[501] = {};
        int not_valid[501] = {};
        int s,d;
        int q = n;

        while(m--){
            cin >> s >> d;
            int ps = s, pd = d;

            while(parents[ps] != 0){
                ps = parents[ps];
            }
            while(parents[pd] != 0){
                pd = parents[pd];
            }
            if (ps != pd){
                if (not_valid[pd] == 0 || not_valid[ps] == 0){
                    --q;
                }
                if (not_valid[pd] || not_valid[ps]){
                    not_valid[pd] = not_valid[ps] = 1;
                }
                parents[pd] = ps;
            } else {
                if(not_valid[pd] == 0){
                    --q;
                    not_valid[pd] = 1;
                }
            }
            
        }
        if (q == 0){
            printf("Case %d: No trees.\n", ++i);
        } else if (q == 1){
            printf("Case %d: There is one tree.\n", ++i);
        } else {
            printf("Case %d: A forest of %d trees.\n",  ++i, q);
        }
        cin >> n >> m;
    }

    return 0;
}

