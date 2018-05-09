
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

using namespace std;

typedef pair<int,int> pii;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(container.begin(), container.end(), element) != container.end())

typedef struct {
    int i;
    long a, b, c;
} Node;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;

    cin >> N >> M;
    while(N > 0 && M > 0){
       
        vector<long> rows;
        rows.push_back(0);
        rows.push_back(0);
        for (int i = 0 ; i < N; ++i){
            vector<long> columns;
            columns.push_back(0);
            columns.push_back(0);
            for (int j = 0 ; j < M; ++j){
                int val;
                cin >> val;
                if (columns[j+1] < columns[j] + val){
                    columns.push_back(columns[j] + val);
                } else {
                    columns.push_back(columns[j+1]);
                }
            }
            if (rows[i+1] < rows[i] + *columns.rbegin()){
                rows.push_back(rows[i] + *columns.rbegin());
            } else {
                rows.push_back(rows[i+1]);
            }
        }
        
        cout << *rows.rbegin() << endl;
        cin >> N >> M;
    }
}