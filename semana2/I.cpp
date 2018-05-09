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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int t;
    int s = 1;
    cin >> t;

    while(t > 0){

        queue<int> teams;
        queue<int> q_team[1000];
        int id[1000000];
        

        for (int i = 0; i < t; ++i){
            int q;
            cin >> q;
            for (int j = 0; j < q; ++j){
                int x;
                cin >> x;
                id[x] = i;
            }
        }

        cout << "Scenario #" << s << "\n";

        string cmd;
        cin >> cmd;

        while(cmd[0] != 'S'){
            int x, team;
            switch(cmd[0]) {
                case 'E':
                cin >> x;
                team = id[x];
                if (q_team[team].empty()){
                    teams.push(team);
                }
                q_team[team].push(x);
                break;

                case 'D':
                team = teams.front();
                x = q_team[team].front();
                q_team[team].pop();
                if (q_team[team].empty()){
                    teams.pop();
                }
                cout << x << "\n";
                break;

            }
            cin >> cmd;
        }
        
    cin >> t;
    cout << "\n";
    ++s;
    }
}