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
    if (!debug)
        return;
    std::cout << "[DEBUG]";
    deb_aux(rest...);
}

#define spc " "
#define all(container) container.begin(), container.end()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(container.begin(), container.end(), element) != container.end())

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int T, t = 0;

    cin >> T;
    while(T--){
        int p, q;
        long int l = 0, h = 0;
        cin >> p >> q;

        int total = pow(2, p - 1);
        int mod = pow(2, q);

        for (int i = 0; i < total && l == 0; ++i){
            bitset<17> low(i);
            long int num = 0;
            for (int j = p-2; j >=0; --j){
                num += low[j] ? 2 : 1;
                num *= 10;
            }
            num += 2;
            if (num % mod == 0){
                l = num;
            }
        }
        for (int i = total - 1; i >= 0 && h == 0; --i){
            bitset<17> low(i);
            long int num = 0;
            for (int j = p-2; j >=0; --j){
                num += low[j] ? 2 : 1;
                num *= 10;
            }
            num += 2;
            if (num % mod == 0){
                h = num;
            }
        }
        cout << "Case " << ++t << ": ";
        if (l == h){
            if (l == 0){
                cout << "impossible" << endl;
            } else {
                cout << l << endl;
            }
        } else {
            cout << l << spc << h << endl;
        }
    }
}