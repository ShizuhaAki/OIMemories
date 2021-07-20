
// Problem : D. Mr. Kitayuta's Colorful Graph
// Contest : Codeforces - Codeforces Round #286 (Div. 1)
// URL : https://codeforces.com/contest/506/problem/D
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
const int N = 200000;
int fa[N + 10], n, m, q, sz[N + 10];
vector <PII> col[N + 10];
vector <PII> vec;
vector < int > tmp[N + 10];
vector < vector <int> > con;
map <PII, int> memory;
vector <int> pla[N + 10];
bool vis[N];
const int BL = 456;
vector <int> large;
int id[N];
void init() {
    rep(i, N + 5) fa[i] = i;
    fill(sz, sz + N, 1);
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    fa[y] = x;
    sz[x] += sz[y];
}
void solve() {
    n = qread(); m = qread();
    rep(i, m) {
        int u = qread(), v = qread(), c = qread();
        --u; --v; --c;
        col[c].pb(mp(u, v));
    }
    q = qread();
    rep(i, q) {
        int u = qread(), v = qread();
        --u; --v;
        vec.pb(mp(u, v));
    }
    init();
    rep(c, n) {
        rep(i, col[c].size()) {
            int u = col[c][i].first, v = col[c][i].second;
            merge(u, v);
        }
        rep(i, col[c].size()) {
            int u = col[c][i].first, v = col[c][i].second;
            if (!vis[u]) {
                vis[u] = true;
                tmp[find(u)].pb(u);
            }
            if (!vis[v]) {
                vis[v] = true;
                tmp[find(v)].pb(v);
            }
        }
        rep(i, col[c].size()) {
            int u = col[c][i].first, v = col[c][i].second;
            if (tmp[u].size()) con.pb(tmp[u]);
            if (tmp[v].size()) con.pb(tmp[v]);
            fa[u] = u; fa[v] = u; sz[u] = 1; sz[v] = 1; vis[u] = 0; vis[v] = 0;    // prep the dsu for the next color
        }
//        init();
    }
    rep(i, con.size()) rep(j, con[i].size()) pla[con[i][j]].pb(i);
    rep(i, n) if (pla[i].size() > BL) {large.pb(i); id[i] = large.size();} else id[i] = -1;
    rep(i, large.size()) {
        int u = large[i];
        rep(j, pla[u].size()) {
            int v = pla[u][j];
            rep(i, con[v].size()) {
                int w = con[v][i];
                // WARNING: The table does not use ID!
                memory[mp(u, w)]++;
            }
        }
    }
    rep(Q, q) {
        int u = vec[Q].first, v = vec[Q].second;
        if (id[u] == -1) swap(u, v);
        if (memory.count(mp(u, v))) printf("%d\n", memory[mp(u, v)]);    // large point
        else {
            
        }
    }
}
int main() {
    int T = 1;
    //T = qread();
    while (T--) solve();
    return 0;
}
