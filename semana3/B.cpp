bool debug = true;

#include<vector>
#include<stack>
#include<map>
#include<queue>
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

void deb_aux() {
    std::cout<<std::endl;
}

template<typename T, typename ... REST>
void deb_aux(T arg, const REST&... rest) {
    std::cout << arg << " ";
    deb_aux(rest...);
}

template<typename ... REST>
void deb(REST&... rest) {
    if (!debug)
        return;
    std::cout << "[DEBUG]";
    deb_aux(rest...);
}

typedef pair<int,int> pii;

#define mp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(container.begin(), container.end(), element) != container.end())

typedef struct {
    char t, nt;
    int time = 9999999;
} Tile;

typedef struct {
    char cor;
    pii pos, ante;
} PaintTile;

Tile tiles[500][500];
vector<PaintTile> civ;
vector<PaintTile> aux;
vector<pii> war;
int R, C;


bool check(const int &i, const int &j){
    if (i < 0 || j < 0 || i >= R || j >= C)
        return true;
    return (tiles[i][j].nt == '*' || tiles[i][j].nt == '.' || tiles[i][j].nt == '#');
}

void paint(const PaintTile& pt,const int &time){
    if (pt.pos.first < 0 || pt.pos.second < 0 || pt.pos.first >= R || pt.pos.second >= C)
        return;
        
    if (tiles[pt.ante.first][pt.ante.second].nt == '*' || tiles[pt.pos.first][pt.pos.second].nt == '#' )
        return;
    int i, j;
    i = pt.pos.first;
    j = pt.pos.second;
    if (tiles[i][j].time > time) {
        tiles[i][j].time = time;
        tiles[i][j].nt = pt.cor;
        PaintTile npt;
        npt.ante = mp(i,j);
        npt.cor = pt.cor;
        npt.pos = mp(i-1,j);
        aux.push_back(npt);
        npt.pos = mp(i+1,j);
        aux.push_back(npt);
        npt.pos = mp(i,j-1);
        aux.push_back(npt);
        npt.pos = mp(i,j+1);
        aux.push_back(npt);
        
    } else if (tiles[i][j].time == time && tiles[i][j].nt != pt.cor) {
        tiles[i][j].nt = '*';
        tiles[i][j].time = time;
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int T, t;
    
    cin >> T;
    while(T--){
        t = 0;
        cin >> R >> C;
        civ.clear();
        aux.clear();

        for (int i = 0 ; i < R; ++i){
            for (int j = 0 ; j < C; ++j){
                cin >> tiles[i][j].t;
                tiles[i][j].nt = tiles[i][j].t;
                tiles[i][j].time = 9999999;

                if (tiles[i][j].t >= 'a' && tiles[i][j].t <= 'z'){
                    PaintTile pt;
                    pt.pos = pt.ante = mp(i,j);
                    pt.cor = tiles[i][j].t;
                    civ.push_back(pt);
                }
            }
        }
        while(!civ.empty()){
            ++t;
            for (auto it = civ.begin(); it != civ.end(); ++it)
                paint(*it, t);
            civ.swap(aux);
            aux.clear();
        }

        for (int i = 0 ; i < R; ++i){
            for (int j = 0 ; j < C; ++j){
                cout << tiles[i][j].nt;
            }
            cout<<endl;
        }
        cout << endl;
    }
}