bool debug = false;

#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<bitset>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;

typedef unordered_map<int, int> umap_ii;
typedef unordered_map<int, pii> umap_ipii;
typedef unordered_map<int, string> umap_is;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

void print_pair(const pii & par){
    cout << "(" << par.first << spc << par.second << ")" << spc;
}

template <typename C>
void print_array(const C &data, int n){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (int i = 0; i < n; ++i){
        cout << data[i] << spc;
    }
    cout << endl;
}

template <typename C>
void print_container(const C &data){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (const auto &v : data){
        cout << v << spc;
    }
    cout << endl;
}

template <typename C>
void print_pairs(const C &data){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (const auto &v : data){
        print_pair(v);
    }
    cout << endl;
}

template <typename C>
void print_matrix(const C &data){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (const auto &row : data){
        for (const auto &v : row){
            cout << v << spc;
        } cout << endl;
    }
    cout << endl;
}

typedef struct rect{
    pii y;
    int x;
} rect;

int comp(const rect& r1, const rect& r2){
    return r1.x < r2.x;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n > 0){
        vector<rect> rects;
        pii pos, ante, first;

        cin >> first.first >> first.second;
        ante = first;
        for (int i = 1 ; i < n; ++i){
            cin >> pos.first >> pos.second;

            if (ante.first == pos.first){
                rect new_rect;
                new_rect.y = mkp(min(ante.second, pos.second), max(ante.second, pos.second));
                new_rect.x = ante.first;
                rects.emplace_back(new_rect);
            }
            ante = pos;
        }
        if (ante.first == first.first){
            rect new_rect;
            new_rect.y = mkp(min(ante.second, first.second), max(ante.second, first.second));
            new_rect.x = ante.first;
            rects.emplace_back(new_rect);
        }

        sort(all(rects), comp);
        cin >> pos.first >> pos.second;

        int cont = 0;
        for (auto const rect : rects){
            if (rect.x < pos.first && (rect.y.first < pos.second && rect.y.second > pos.second)){
                cont++;
            } else if (rect.x > pos.first){
                break;
            }
        }

        printf(cont % 2 ? "T\n" : "F\n");

        cin >> n;
    }
}
