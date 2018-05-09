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

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

// clock_t t;
// void init_time(){
//     t = clock();
// }

// void check_time(){
//     t = clock() - t;
//     cout << "Time taken " << ((double)t)/CLOCKS_PER_SEC << "s" << endl ;
// }

void deb_aux() {
    std::cout<<std::endl;
}

template<typename T, typename ... REST>
void deb_aux(T arg, const REST&... rest) {
    std::cout << arg << spc;
    deb_aux(rest...);
}

template<typename ... REST>
void deb(REST&... rest) {
    if (!debug)
        return;
    std::cout << "[DEBUG]";
    deb_aux(rest...);
}

template<typename T>
void deb_arr(const T arr[], const int &n) {
    if (!debug)
        return;
    std::cout << "[DEBUG ARR]";
    for(int i = 0 ; i < n; ++i){
        cout << arr[i] << spc;
    }
    cout << endl;
}

template<typename T>
void deb_vec(const vector<T> &vec) {
    if (!debug)
        return;
    std::cout << "[DEBUG VEC]";
    for (auto it = vec.begin(); it != vec.end(); ++it){
        cout <<  *it << spc;
    }
    cout << endl;
}

int get_middle(int s, int f){
    return (s + f) / 2;
}

long get_sum(vector<long> &st, vector<long> &lazy, int ss, int sf, int qs, int qf, int si){
    if (lazy[si] != 0){                     // Solve pendencies before update
        st[si] += (sf-ss + 1) * lazy[si];

        if (sf != ss){                      // Set pendencies to childs
            lazy[2 * si + 1] += lazy[si];
            lazy[2 * si + 2] += lazy[si];
        }

        lazy[si] = 0;                       // Clear lazy pendencies
    }

    if (qs <= ss && sf <= qf)       // In range
        return st[si];

    if (qs > sf || qf < ss)         // Out of range
        return 0;
    
    int mid = get_middle(ss, sf);
    return get_sum(st, lazy, ss, mid, qs, qf, 2 * si + 1) + get_sum(st, lazy, mid + 1, sf, qs, qf, 2 * si + 2);
}

long get_sum(vector<long> &st, vector<long> &lazy, int n, int qs, int qf){
    return get_sum(st, lazy, 0, n - 1, qs, qf, 0);
}

void update_range(vector<long> &st, vector<long> &lazy, int ss, int sf, int us, int uf, long val, int si){
    if (lazy[si] != 0){                     // Solve pendencies before update
        st[si] += (sf-ss + 1) * lazy[si];

        if (sf != ss){                      // Set pendencies to childs
            lazy[2 * si + 1] += lazy[si];
            lazy[2 * si + 2] += lazy[si];
        }

        lazy[si] = 0;                       // Clear lazy pendencies
    }
    if (ss > sf || ss > uf || sf < us){     // Out of range
        return;
    }

    if (ss >= us && sf <= uf){                  // Update usign bottom-up
        st[si] += (sf-ss + 1) * val;

        if (sf != ss){                          // Set pendencies to childs
            lazy[2 * si + 1] += val;
            lazy[2 * si + 2] += val;
        }
    } else {
        int mid = get_middle(ss, sf);
        update_range(st, lazy, ss, mid, us, uf, val, 2 * si + 1);
        update_range(st, lazy, mid + 1, sf, us, uf, val, 2 * si + 2);

        st[si] = st[2 * si + 1] + st[2 * si + 2];
    }
}

void update_range(vector<long> &st, vector<long> &lazy, int n, int us, int uf, long val){
    update_range(st, lazy, 0, n - 1, us, uf, val, 0);
}

int construct_segtree(vector<long> &st, const vector<long> &arr, int ss, int sf, int si){
    if (ss == sf){
        st[si] = arr[ss];                   // Insert leaf node value
    } else {
        int mid = get_middle(ss, sf);       // Constuct tree using bottom-up
        st[si] = construct_segtree(st, arr, ss, mid, 2 * si + 1) + 
        construct_segtree(st, arr, mid + 1, sf, 2 * si + 2);
    }   
    return st[si];
}

void construct_segtree(vector<long> &st, const vector<long> &arr, vector<long> &lazy){
    int x = (int)(ceil(log2(arr.size())));  // log2(n)
    int max_size = 2 * (int)pow(2, x) - 1;  // Max size = 2 * log2(n) - 1

    st = vector<long>(max_size);
    lazy = vector<long>(max_size);

    construct_segtree(st, arr, 0, arr.size() - 1, 0);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int T;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;
        vector<long> st, lazy, input;
        input = vector<long>(n);

        construct_segtree(st, input, lazy);

        while(q--){
            int op, s, f;
            cin >> op >> s >> f;
            s--;
            f--;
            if (op == 1){
                cout << get_sum(st, lazy, n, s, f) << endl;
            } else {
                long v;
                cin >> v;
                update_range(st, lazy, n, s, f, v);
            }
        }
    }
}