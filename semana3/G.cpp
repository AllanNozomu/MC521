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

long int calc(const int &x, const int &y, const int &z){
    if (y == 0){
        return 1;
    }
    long int r = calc(x, y/2, z);
    if (y % 2 == 0)
        return (r * r) % z;
    return (((r * r) % z) * x) % z;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int n, x, y, z;

    cin >> n;
    while(n--){
        cin >> x >> y >> z;

        cout << calc(x,y,z) << endl;
    }
}