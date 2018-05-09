
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
    
    int N, t = 0;
    cin >> N;
    vector<Node> nodes;
    while(N > 0){
        Node node;
        cin >> node.a >> node.b >> node.c;
        nodes.push_back(node);
        node.a = node.b;
        node.c += node.b;
        for (int i = 1 ; i < N; ++i){
            Node atual, aux;
            cin >> atual.a >> atual.b >> atual.c;
            nodes.push_back(atual);
            aux = atual;

            if (i == N - 1){
                node.a += min(atual.b, atual.b + atual.a);
                node.b += min(atual.b, atual.b + atual.a);
                node.c += atual.b;
            } else {
                set<long> minimo;
                minimo.emplace(node.a);
                minimo.emplace(node.b);
                aux.a += *minimo.begin();
                minimo.clear();
                minimo.emplace(node.a);
                minimo.emplace(node.b);
                minimo.emplace(node.c);
                minimo.emplace(node.a + atual.a);
                minimo.emplace(node.b + atual.a);
                aux.b += *minimo.begin();
                minimo.clear();
                minimo.emplace(node.a + atual.a + atual.b);
                minimo.emplace(node.a + atual.b);
                minimo.emplace(node.b);
                minimo.emplace(node.b + atual.b);
                minimo.emplace(node.b + atual.a + atual.b);
                minimo.emplace(node.c);
                minimo.emplace(node.c + atual.b);
                aux.c += *minimo.begin();
                node = aux;
            }
        }
        cout << ++t << ". " ;
        cout << (min(node.a,min(node.b, node.c))) << endl;
        cin >> N;
    }
}