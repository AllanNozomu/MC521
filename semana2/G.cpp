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

#define all(container) container.begin(), container.end()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(container.begin(), container.end(), element) != container.end())

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int n;

    cin >> n;
    for (int c = 0 ; c < n; ++c){
        string str;
        cin >> str;
        int q = 0;

        for (int i = 0; i <= str.length(); ++i){
            bitset<26> alfabeto;
            int c = 0;
            for (int j = i; j < str.length(); ++j){
                int index = str[j] - 'a';
                if (alfabeto[index]){
                    alfabeto.flip(index);
                    --c;
                } else {
                    alfabeto.flip(index);
                    c++;
                }
                if ((j-i) % 2 == 0 && c == 1){
                    ++q;
                } else if ((j - i) % 2 && c == 0){
                    ++q;
                }
            }
        }
        cout << "Case " << c + 1 << ": " << q << endl;
    }
    return 0;
}