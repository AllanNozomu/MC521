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

int count(vector<int> v[], const int &id){
    if (v[id].empty())
        return 1;
    int q = 0;
    for (int i = 0 ; i < v[id].size(); ++i){
        q += count(v, v[id][i]);
    }
    return q;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 
    int first = 1;

    std::string line;
    while (getline(std::cin, line))
    {
        if (line.length() > 0){
            if (first){
                first = 0;
            } else {
                cout << endl;
            }
            int n = stoi(line);
            vector<int> v[n];

            for (int i = 0; i < n; ++i){
                int q;
                cin >> q;
                while(q--){
                    int id;
                    cin >> id;
                    v[i].push_back(id);
                }
            }
            int r = count(v, 0);

            cout << r << "\n";
        }
    }
}