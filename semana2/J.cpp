#include<vector>
#include<stack>
#include<map>
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

#define all(container) container.begin(), container.end()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(container.begin(), container.end(), element) != container.end())

typedef struct {
    vector<short> v;
    short m = 0;
    short i = 0;
} Valor;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    short n;
    Valor val[10000];
    vector<short> num;
    
    cin >> n;
    for (short i = 0; i < n; ++i){
        short t;
        cin >> t;
        num.push_back(t);

        short index = t % n;
        val[index].v.push_back(t);

        if (val[index].v.size() * t % n == 0) {
            cout << val[index].v.size() << endl;
            for (auto it = val[index].v.begin(); it != val[index].v.end(); ++it){
                cout << * it << endl;
            }
            return 0;
        }

        if (val[index].v.size() > 1){
            short n_index = t * val[index].v.size() % n;
            if (val[n_index].v.size() == 0){
                val[n_index].m = val[index].v.size();
                val[n_index].i = index;
            }
        }
    }
    // for (short i = 0; i < n; ++i){ 
    //     cout << i << endl;
    //     cout << val[i].m << endl;
    //     cout << val[i].i << endl;
    //     for (auto it = val[i].v.begin(); it != val[i].v.end(); ++it){
    //         cout << * it << " ";
    //     }
    //     cout << endl;
    // }

    for (short i = 0; i < n; ++i){
        short t = num[i];

        short index = (n - t % n) % n;

        if (t % n == 0){
            cout << 1 << endl;
            cout << t << endl;
            return 0;
        } else if (val[index].m > 0 && val[index].i != (t % n)){
            short n_index = val[index].i;
            cout << val[index].m + 1 << endl;
            cout << t << endl;
            for (short j = 0 ; j < val[index].m; ++j){
                cout << val[n_index].v[j] << endl;
            }
            return 0;
        } else if (val[index].v.size() > 0){
            cout << 2 << endl;
            cout << t << endl;
            cout << val[index].v[0] << endl;
            return 0;
        }
    }



}