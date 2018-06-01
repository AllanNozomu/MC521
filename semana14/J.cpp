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
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<pii>> vvii;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

clock_t t = clock();

void check_time(){
    t = clock() - t;
    cout << "Time taken " << ((double)t)/CLOCKS_PER_SEC << "s" << endl ;
}

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

char roda(char c, char ori){
    if (c == 'E'){
        switch (ori){
            case 'N': return 'O';
            break;
            case 'S': return 'L';
            break;
            case 'L': return 'N';
            break;
            case 'O': return 'S';
            break;
        }
    } else if (c == 'D'){
        switch (ori){
            case 'N': return 'L';
            break;
            case 'S': return 'O';
            break;
            case 'L': return 'S';
            break;
            case 'O': return 'N';
            break;
        } 
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, S;
    cin >> M >> N >> S;
    while(M > 0 && N > 0 && S > 0){
        char board[M][N];
        pii pos;
        char ori;

        for (int i = 0 ; i < M; ++i){
            for (int j = 0 ; j < N; ++j){
                cin >> board[i][j];
                if (board[i][j] == 'N' || board[i][j] == 'S' || board[i][j] == 'L' || board[i][j] == 'O'){
                    pos = mkp(i, j);
                    ori = board[i][j];
                }
            }
        }
        string inst;
        cin >> inst;
        int fig = 0;
        for (auto c : inst){
            
            pii prev = pos;
            if (c == 'F'){
                switch (ori){
                    case 'N': pos.first = max(0, pos.first - 1);
                    break;
                    case 'S': pos.first = min(M - 1, pos.first + 1);
                    break;
                    case 'O': pos.second = max(0, pos.second - 1);
                    break;
                    case 'L': pos.second = min(N - 1, pos.second + 1);
                    break;
                }
            } else {
                ori = roda(c, ori);
            }
            if (board[pos.first][pos.second] == '#'){
                pos = prev;
            } else if (board[pos.first][pos.second] == '*'){
                ++fig;
                board[pos.first][pos.second] = '.';
            }
            print_pair(pos);
        }
        cout << fig << endl;
         cin >> M >> N >> S;
    }
}
