#include<vector>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>

#define all(container) container.begin(), container.end()

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int a[2500], b[2500], c[2500], d[2500];
    vector<int> v;
    int n,i,j,r, q=0;

    cin >> n;
    i = n;
    
    while(i--)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    for(i = 0 ; i < n; ++i)
        for(j = 0 ; j < n; ++j)
            v.push_back(a[i] + b[j]);
    
    sort(all(v));

    for(i = 0 ; i < n; ++i)
        for(j = 0 ; j < n; ++j){
            r = -(c[i] + d[j]);
            auto range = equal_range(all(v), r);
            q += range.second - range.first;
        }

    cout << q << endl;

    return 0;
}