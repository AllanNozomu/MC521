#include<vector>
#include<stack>
#include<map>
#include<unordered_map>
#include<queue>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
#include<bitset>
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
    while(n--){
        string right, left, result;
        bitset<12> suspects, light, heavy;

        suspects.set();
        light.set();
        heavy.set();

        for (int i = 0 ; i < 3; ++i){
            cin >> left >> right >> result;

            if (result == "even"){
                for (int j = 0 ; j < left.length(); ++j){
                    int lindex = left[j] - 'A', rindex = right[j] - 'A';
                    suspects.set(lindex, 0);
                    suspects.set(rindex, 0);
                }
            } else if (result == "up"){
                bitset<12> laux, raux;
                for (int j = 0 ; j < left.length(); ++j){
                    int lindex = left[j] - 'A', rindex = right[j] - 'A';
                    laux.set(lindex, 1);
                    raux.set(rindex, 1);
                }
                heavy &= laux;
                light &= raux;
            } else {
                bitset<12> laux, raux;
                for (int j = 0 ; j < left.length(); ++j){
                    int lindex = left[j] - 'A', rindex = right[j] - 'A';
                    laux.set(lindex, 1);
                    raux.set(rindex, 1);
                }
                light &= laux;
                heavy &= raux;
            }
            light &= suspects;
            heavy &= suspects;
        }
        if (light != 0){
            for (int i = 0 ; i < 12; ++i){
                if (light[i]){
                    printf("%c is the counterfeit coin and it is light.\n", 'A' + i);
                    break;
                }
            }
        }else{
            for (int i = 0 ; i < 12; ++i){
                if (heavy[i]){
                    printf("%c is the counterfeit coin and it is heavy.\n", 'A' + i);
                    break;
                }
            }
        }
    }
}