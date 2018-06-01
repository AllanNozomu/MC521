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


#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

void print_pair(const pii & par){
    if (!debug) return;
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    long N;
    getline(cin, str);
    N = stol(str);
    
    for(int i = 0 ; i < N; ++i){
        
        int ante = -1;
        bool first = true;
        getline(cin, str);

        cout << "Case #" << i + 1 <<": ";
        for (const auto c : str){
            switch(c){
                case 'c': 
                if (first && ante == 2){
                    cout << ' ';
                    first = false;
                } cout << '2';
                case 'b':
                if (first && ante == 2){
                    cout << ' ';
                    first = false;
                } cout << '2';
                case 'a':
                if (first && ante == 2){
                    cout << ' ';
                    first = false;
                } cout << '2';
                ante = 2;
                break;

                case 'f': 
                if (first && ante == 3){
                    cout << ' ';
                    first = false;
                    
                } cout << '3';
                case 'e':
                if (first && ante == 3){
                    cout << ' ';
                    first = false;
                } cout << '3';
                case 'd':
                if (first && ante == 3){
                    cout << ' ';
                    first = false;
                } cout << '3';
                ante = 3;
                break;

                case 'i': 
                if (first && ante == 4){
                    cout << ' ';
                    first = false;
                } cout << '4';
                case 'h':
                if (first && ante == 4){
                    cout << ' '; 
                    first = false;
                } cout << '4';
                case 'g':
                if (first && ante == 4){
                    cout << ' ';
                    first = false;
                } cout << '4';
                ante = 4;
                break;

                case 'l': 
                if (first && ante == 5){
                    cout << ' ';
                    first = false;
                    ante = 5;
                } cout << '5';
                case 'k':
                if (first && ante == 5){
                    cout << ' ';
                    first = false;
                    ante = 5;
                } cout << '5';
                case 'j':
                if (first && ante == 5){
                    cout << ' ';
                    first = false;
                    ante = 5;
                } cout << '5';
                ante = 5;
                break;

                case 'o': 
                if (first && ante == 6){
                    cout << ' ';
                    first = false;
                    ante = 6;
                } cout << '6';
                case 'n':
                if (first && ante == 6){
                    cout << ' ';
                    first = false;
                    ante = 6;
                } cout << '6';
                case 'm':
                if (first && ante == 6){
                    cout << ' ';
                    first = false;
                    ante = 6;
                } cout << '6';
                ante = 6;
                break;

                case 's': 
                if (first && ante == 7){
                    cout << ' ';
                    first = false;
                    ante = 7;
                }  cout << '7';
                case 'r': 
                if (first && ante == 7){
                    cout << ' ';
                    first = false;
                    ante = 7;
                } cout << '7';
                case 'q':
                if (first && ante == 7){
                    cout << ' ';
                    first = false;
                    ante = 7;
                } cout << '7';
                case 'p':
                if (first && ante == 7){
                    cout << ' ';
                    first = false;
                    ante = 7;
                } cout << '7';
                ante = 7;
                break;

                case 'v': 
                if (first && ante == 8){
                    cout << ' ';
                    first = false;
                    ante = 8;
                } cout << '8';
                case 'u':
                if (first && ante == 8){
                    cout << ' ';
                    first = false;
                    ante = 8;
                } cout << '8';
                case 't':
                if (first && ante == 8){
                    cout << ' ';
                    first = false;
                    ante = 8;
                } cout << '8';
                ante = 8;
                break;

                case 'z': 
                if (first && ante == 9){
                    cout << ' ';
                    first = false;
                    ante = 9;
                } cout << '9';
                case 'y': 
                if (first && ante == 9){
                    cout << ' ';
                    first = false;
                    ante = 9;
                } cout << '9';
                case 'x':
                if (first && ante == 9){
                    cout << ' ';
                    first = false;
                    ante = 9;
                } cout << '9';
                case 'w':
                if (first && ante == 9){
                    cout << ' ';
                    first = false;
                    ante = 9;
                } cout << '9';
                ante = 9;
                break;

                case ' ':
                if (first && ante == 0){
                    cout << ' ';
                    first = false;
                    ante = 0;
                } cout << '0';
                ante = 0;
                break;
            }
            first = true;
        }
        cout << endl;
    }
}
