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

int comp(pii f, pii s){
    return f.first > s.first;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int n;
    cin >> n;
    while(n > 0){
        vector<ll> v;
        ll sum = 0;
        
        for (int i = 0 ; i < n - 1; ++i){
            ll q;
            cin >> q;
            sum += q;
            v.emplace_back(q);
        }
        sort(all(v));

        int lower = n / 2 - 1;
        int upper = n / 2;
        ll lower_value = v[lower] * n - sum;
        ll upper_value = v[upper] * n - sum;
        ll mid_value = sum / (n - 1);

        int q = 0;
        if (!binary_search(all(v), lower_value) && lower_value < v[lower]){
            ++q;
        }
        if (!binary_search(all(v), upper_value) && upper_value > v[upper] && upper_value != lower_value){
            ++q;
        }
        if (!binary_search(all(v), mid_value) && sum % (n - 1) == 0 && v[lower] < mid_value && mid_value < v[upper]){
            ++q;
        }
        cout << q << endl;

        cin >> n;
    }
}