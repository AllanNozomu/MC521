#include<vector>
#include<stack>
#include<map>
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int n;
    cin >> n;
    map<int, int> m;
    int a;

   for (int i = 0 ; i < n; ++i){
        cin >> a;
        m[a] ++;
    }

    int q = 0;
    for (auto it = m.begin(); it!= m.end(); it++){
        if (it->second > 1){
            q += it->second - 1;
            m[it->first + 1] += it->second - 1;
        }
    }
    cout << q << endl;
}