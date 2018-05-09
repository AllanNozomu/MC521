#include<vector>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define pii pair<int,int>
#define all(container) container.begin(), container.end()

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int cont[3] = {};
    long q;
    int s;
    char c;

    cont[0] = 1;
    q = s = 0;
    int fim = 1;
    c = getchar();
    while(c != EOF){
        if (c >= '0' && c <= '9'){
            s += (c - '0');
            q += cont[ s % 3 ];
            ++cont[s % 3];
            fim = 0;
        } else if (c == '\n'){
            if (!fim){
                cout << q << endl;

                q = s = 0;
                fim = 1;
                memset(cont, 0, 3 * sizeof(int));
                cont[0] = 1;
            }
        } else {
            memset(cont, 0, 3 * sizeof(int));
            cont[0] = 1;
            fim = s = 0;
        }
        c = getchar();
    }

    return 0;
}