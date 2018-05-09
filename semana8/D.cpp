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

int mmq(int a, int b){
    int mmq = 1, f = 0;
    for (int i = 2; a != 1 && b != 1;){
        f = 0;
        if (a % i == 0){
            a /= i;
            f = 1;
        } 
        if (b % i == 0){
            b /= i;
            f = 1;
        }
        if (f){
            mmq *= i;
        } else {
            ++i;
        }
    }
    return mmq * a * b;
}

int main()
{
    int x, y, a, b, m, dif, q = 0;
    cin >> a >> b >> x >> y;

    m = mmq(a,b);
    if (x % m > 0){
        x += m - (x % m);
    }
    
    if (x <= y){
        q += (y - x) / mmq(a,b) + 1;
    }
    cout << q << endl;
}