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
typedef long long ll;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()
#define rall(container) container.rbegin(), container.rend()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(container.begin(), container.end(), element) != container.end())

typedef struct Stone{
    char type;
    int distance = 0;
}Stone;

int cmp(const Stone &f, const Stone &s){
    return f.distance < s.distance;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int T;
    scanf("%d", &T);
    for(int cont = 0; cont < T; ++cont){
        int n, D;
        vector<Stone> stones, new_stones;
        scanf("%d %d\n", &n, &D);
        for(int i = 0 ; i < n; ++i){
            Stone stone;
            scanf("%c-%d ", &stone.type, &stone.distance);
            stones.emplace_back(stone);
        }
        sort(all(stones), cmp);

        int small_flag = 0;
        int res = 0;
        Stone prev;
        for(int i = 0 ; i < n; ++i){
            if (stones[i].type == 'B'){
                new_stones.emplace_back(stones[i]);
                small_flag = 0;
                res = max(res, stones[i].distance - prev.distance);
                prev = stones[i];
            } else if (small_flag){
                new_stones.emplace_back(stones[i]);
                small_flag = 0;
            } else {
                small_flag = 1;
                res = max(res, stones[i].distance - prev.distance);
                prev = stones[i];
            }
        }
        res = max(res, D - prev.distance);
        
        prev.distance = 0;
        for (auto const stone : new_stones){
            res = max(res, stone.distance - prev.distance);
            prev = stone;
        }
        res = max(res, D - prev.distance);
        cout << "Case " << cont + 1 << ": " << res << endl;
    }
}