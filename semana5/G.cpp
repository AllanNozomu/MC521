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

using namespace std;

void deb_aux() {
    std::cout<<std::endl;
}

#define all(container) container.begin(), container.end()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(container.begin(), container.end(), element) != container.end())

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;

    while(a && b && c && d && e){
        vector<int> v;
        int possivel = 0;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        v.push_back(e);
        sort(all(v));
        int a1, a2, a3, a4;

        do{
            for (int i = 0; i < 3 && possivel == 0; ++i){
                if (i == 0){
                    a1 = v[0] + v[1];
                } else if (i == 1) {
                    a1 = v[0] - v[1];
                } else {
                    a1 = v[0] * v[1];
                }
                for (int j = 0; j < 3 && possivel == 0; ++j){
                    if (j == 0){
                        a2 = a1 + v[2];
                    } else if (j == 1) {
                        a2 = a1 - v[2];
                    } else {
                        a2 = a1 * v[2];
                    }
                    for (int k = 0; k < 3 && possivel == 0; ++k){
                        if (k == 0){
                            a3 = a2 + v[3];
                        } else if (k == 1) {
                            a3 = a2 - v[3];
                        } else {
                            a3 = a2 * v[3];
                        }
                        for (int l = 0; l < 3 && possivel == 0; ++l){
                            if (l == 0){
                                a4 = a3 + v[4];
                            } else if (l == 1) {
                                a4 = a3 - v[4];
                            } else {
                                a4 = a3 * v[4];
                            }
                            if (a4 == 23){
                                cout << "Possible\n";
                                possivel = 1;
                                break;
                            }
                        }
                    }
                }
            }
        } while(next_permutation(all(v)) && possivel == 0);
        if (!possivel){
            cout << "Impossible\n";
        }

        cin >> a >> b >> c >> d >> e;
    }


}