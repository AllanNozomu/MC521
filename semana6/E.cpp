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
#include<iomanip>
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int p, q, r, s, t, u;
    while((scanf("%d", &p)) == 1){
        
        scanf("%d %d %d %d %d", &q, &r, &s, &t, &u);
        // pex+qsin(x) +rcos(x) +stan(x) +tx2+u= 0
        double for_zero, for_one;
        double x = 0;
        for_zero = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
        x = 1;
        for_one = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
        if ((for_zero < 0 && for_one < 0) || (for_zero > 0 && for_one > 0)){
            printf("No solution\n");
        } else {
            int times = 30, crescent = for_zero < 0;
            double i, e, now;
            i = 0;
            e = 1;
            while(times--){
                x = (i + e) / 2;
                now = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
                
                if (crescent){
                    if (now > 0){
                        e = x;
                    } else{
                        i = x;
                    }
                } else {
                    if (now > 0){
                        i = x;
                    } else{
                        e = x;
                    }
                }
            }
            printf("%.4f\n", x);
        }
    }
}