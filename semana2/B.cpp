bool debug = true;

#include<vector>
#include<stack>
#include<deque>
#include<map>
#include<unordered_map>
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
    if (!debug)
        return;
    std::cout << "[DEBUG]";
    deb_aux(rest...);
}

#define all(container) container.begin(), container.end()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(container.begin(), container.end(), element) != container.end())

int main()
{
    vector<long> f;

    f.push_back(0);
    f.push_back(1);
    for (int i = 2; i < 41; ++i){
        f.push_back(f[i-1] + f[i-2]);
    }

    int T;
    cin >> T;
    
    while(T--){

        map<int, long> val;

        int a,b,n, vala, valb;
        cin >> n >> a >> b;
        vala = f[n - 1];
        valb = f[n];
        
        int d = 2;
        int q = 0;
        int aux = a;
        while(aux > 1){
            if (aux % d){
                if (q > 0){
                    val[d] += q * vala;
                }
                q = 0;
                if (d == 2)
                    d++;
                else
                    d += 2;
            } else {
                aux /= d;
                q ++;
            }
        }
        if (q > 0){
            val[d] += q * vala;
        }

        d = 2;
        q = 0;
        aux = b;
        while(aux > 1){
            if (aux % d){
                if (q > 0){
                    val[d] += q * valb;
                }
                q = 0;
                if (d == 2)
                    d++;
                else
                    d += 2;
            } else {
                aux /= d;
                q ++;
            }
        }
        if (q > 0){
            val[d] += q * valb;
        }
        for (auto a = val.begin(); a != val.end(); ++a){
            cout << a->first << " " << a->second << endl;
        } cout << endl;
    }

    return 0;
}