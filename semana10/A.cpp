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

// clock_t t;
// void init_time(){
//     t = clock();
// }

// void check_time(){
//     t = clock() - t;
//     cout << "Time taken " << ((double)t)/CLOCKS_PER_SEC << "s" << endl ;
// }

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int c1, c2, c3, c4, c5, c6;

    cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
    while(c1 || c2 || c3 || c4 || c5 || c6){
        int q = 0;

        // Box 6x6
        q += c6;

        // Box 5x5
        q += c5;
        c1 -= c5 * 11;

        // Box 4x4
        for (int i = 0; i < c4; ++i){
            q++;
            int j;
            for (j = 0 ; j < 5 && c2 > 0; ++j){
                --c2;
            }
            if (j < 5){
                c1 -= (5 - j) * 4;
            }
        }
        
        // box 3x3
        q += c3 / 4;
        switch(c3 % 4){
            case 1:
                ++q;
                c1 -= 7 + (5 - min(c2, 5)) * 4;
                c2 -= min(c2, 5);
                break;
            case 2:
                ++q;    
                c1 -= 6 + (3 - min(c2, 3)) * 4;
                c2 -= min(c2, 3);
                break;
            case 3:
                ++q;
                c1 -= 5 + (1 - min(c2, 1)) * 4;
                c2 -= min (c2, 1);
                break;
        }

        // box 2x2 
        if (c2 > 0){
            q += c2 / 9;
            if (c2 % 9){
                ++q;
                c1 -= (36 - (c2 % 9) * 4);
            }
        }
        
        // box 1x1
        if (c1 > 0){
            q += c1 / 36;
            if (c1 % 36) q++;
        }

        cout << q << endl;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
    }
}