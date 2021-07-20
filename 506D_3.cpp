// Problem : D. Mr. Kitayuta's Colorful Graph
// Contest : Codeforces - Codeforces Round #286 (Div. 1)
// URL : https://codeforc.es/contest/506/problem/D
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define y2 y1919810
typedef pair <int, int> PII;
//#define int long long
#define all(x) x.begin(),  x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
    char c = getchar();
    int neg = 1;
    long long val = 0;
    while (c != '-' && !isdigit(c)) c = getchar();
    if (c == '-') c = getchar(), neg = -1;
    while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
    return neg * val;
}

const int N = 300000;
int n, m, q;
vector <int> col[N + 10];
map <PII, int> memory;
vector < pair < PII, int> > vec;
int deg[N + 10], pre[N + 10];

namespace dsu {
    int sz[N + 10], fa[N + 10];
    void init() {
        rep(i, N) fa[i] = i;
        fill(sz, sz + N + 1, 1);
    }
    int find(int x) {
        return fa[x] == x? x : fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
}

// Returns the ID of edge c of vid within the dsu
int get(int vid, int c) {
    return pre[vid] + lower_bound(col[vid].begin(), col[vid].end(), c) - col[vid].begin();
}

void solve() {
    n = qread(); 
    m = qread();
    rep(i, m) {
        int u = qread(), v = qread(); --u; --v;
        int c = qread();
        col[u].pb(c);
        col[v].pb(c);
        vec.pb(mp(mp(u, v), c));
    }
    rep(i, n) {
        sort(col[i].begin(), col[i].end());
        col[i].erase(unique(col[i].begin(), col[i].end()), col[i].end());
        deg[i] = col[i].size();
        pre[i + 1] = pre[i] + deg[i];
    }
    dsu::init();
    rep(i, m) {
        int u = vec[i].first.first, v = vec[i].first.second, c = vec[i].second;
        int U = get(u, c), V = get(v, c);
        dsu::merge(U, V);
    }
    q = qread();
    while (q--) {
        int u = qread(), v = qread(); --u; --v;
        if (deg[u] > deg[v]) swap(u, v);
        if (memory.count(mp(u, v))) printf("%d\n", memory[mp(u, v)]);
        else {
            int ans = 0;
            rep(i, deg[u]) {
                int c = col[u][i];
                if (binary_search(col[v].begin(), col[v].end(), c)) {
                    int tmp = get(v, c);    // The "c" edge from v in the dsu
                    if (dsu::same(tmp, i + pre[u]))    // i + pre[u] <- The "c" edge from u in the dsu
                        ans++;
                }
            }   
            memory[mp(u, v)] = ans; 
            printf("%d\n", ans);
        }
    }    
}

int main() {
    int T = 1;
    //T = qread();
    while (T--) solve();
    return 0;
}
