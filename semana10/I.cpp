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
#include<time.h>

using namespace std;

typedef pair<int,int> pii;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()
#define rall(container) container.rbegin(), container.rend()

// clock_t t;
// void init_time(){
//     t = clock();
// }

// void check_time(){
//     t = clock() - t;
//     cout << "Time taken " << ((double)t)/CLOCKS_PER_SEC << "s" << endl ;
// }

int comp_distance(const pii &f, const pii & s){
    return f.first > s.first;
}

int comp_fuel(const pii &f, const pii &s){
    return f.second > s.second;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        deque<pii> postos, reached;
        for (int i = 0; i < n; ++i){
            int k, q;
            cin >> k >> q;
            postos.emplace_back(mkp(k, q));
        }
        int L, P;
        cin >> L >> P;

        sort(all(postos), comp_distance);

        int i_posto = 0;
        int q = 0;
        int fail = 0;
        while(L - P > 0){
            for(int flag = 1; i_posto < postos.size() && flag; ++i_posto){
                if (L - P <= postos[i_posto].first){
                    reached.insert(lower_bound(all(reached), postos[i_posto], comp_fuel), postos[i_posto]);
                } else {
                    flag = 0;
                    --i_posto;
                }
            }
            if (reached.empty()){
                fail = 1;
                break;
            }
            ++q;
            P += reached[0].second;
            reached.pop_front();
        }
        cout << (fail ? -1 : q) << endl;
    }
}