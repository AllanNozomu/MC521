bool debug = true;

#include<vector>
#include<stack>
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
    int n;
    cin >> n;
    
    while(n >= 0){
        int sum = 0;
        int q = 0;
        int p;

        for (int i = 0; i < n; ++i){
            cin >> p;
            sum += p;
            if (sum % 100 == 0){
                ++q;
                sum = 0;
            }
        }
        cout << q << endl;
        cin >> n;
    }
}