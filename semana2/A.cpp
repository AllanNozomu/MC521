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

#define all(container) container.begin(), container.end()

typedef pair<int, int> pii;

bool comp(const pair<int, pair<int, int>> &l, const pair<int, pair<int, int>> &r){
    if (l.second.first == r.second.first)
        return l.second.second < r.second.second;
    return l.second.first > r.second.first;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    map<int, pii> mapa;
    int N, C, v;

    cin >> N >> C;

    for (int i = 0; i < N; ++i){
        cin >> v;
        auto it = mapa.find(v);
        if (it != mapa.end()){
            it->second.first++;
        } else {
            mapa.insert(make_pair(v, make_pair(1,i)));
        }
    }

    vector< pair<int, pii>> ordered (mapa.begin(), mapa.end());
    sort(all(ordered), comp);
    
    for(auto it = ordered.begin(); it != ordered.end(); ++it){
        for (int i = 0 ; i < it->second.first; ++i){
            cout << it->first << " ";
        }
    }
    cout << "\n";
    
    return 0;
}