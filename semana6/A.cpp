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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 
    
    unordered_map<string, pii> mapa;

    string str;
    char c;
    int index = 0;
    while(true){
        c = getchar();
        index++;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            str.push_back(tolower(c));
        } else {
            if (str.length() > 0){
                if (mapa[str].second == 0){
                    mapa[str] = make_pair(1, index);
                } else {
                    mapa[str].first++;
                    mapa[str].second = index;
                }
                str.clear();
            }
            if (c == '#'){
                if (mapa.size() == 0)
                    return 0;
                pii maximo;
                string resposta;
                for (auto it = mapa.begin(); it != mapa.end(); ++it){
                    if (maximo.first < it->second.first){
                        maximo = it->second;
                        resposta = it->first;
                    } else if (maximo.first == it->second.first && maximo.second > it->second.second){
                        maximo = it->second;
                        resposta = it->first;
                    }
                }
                printf("%4d %s\n", maximo.first, resposta.c_str());
                mapa.clear();
                index = 0;
            }
        }
    }
}