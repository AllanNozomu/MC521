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

typedef long long ll;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;

typedef unordered_map<int, int> umapii;
typedef unordered_map<int, string> umapis;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

ll nine_sum(int index){
    return index * 45 * pow(10, index - 1);
}

int len_number(int number){
    int s = 1;
    while(number >= 10){
        ++s;
        number /= 10;
    }
    return s;
}

ll sum_digits(int number){
    if (number < 10){
        return number * (number + 1) / 2;
    }
    int index = len_number(number) - 1;     // Is the index of msd number (lenght - 1)
    int msd = number / pow(10, index);      

    // First part is nearest number with final 999...9. Ex.: Number 4351 will calculate 3999
    // Calculate 4 * 9999 + (1 + 2 + 3 + 4) * 10^3
    ll first = msd * nine_sum(index) + (msd) * (msd - 1) / 2 * pow(10, index);

    // Second part is the rest. Example 4351 will calculate 4000 until 4351
    // The number 4 will appear 352 times, then calculate 352 with recursion
    ll second = msd * (number - msd * pow(10, index) + 1) + sum_digits(number - msd * pow(10, index));
    return first + second;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int s, e;
    cin >> s >> e;
    while(s > 0 && e > 0){
            cout << sum_digits(e) - sum_digits(s - 1)<< endl;
        cin >> s >> e;
    }
}