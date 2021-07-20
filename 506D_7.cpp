
// Problem: D. Mr. Kitayuta's Colorful Graph
// Contest: Codeforces - Codeforces Round #286 (Div. 1)
// URL: https://codeforces.com/contest/506/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define VPII vector <PII>
#define y2 y1919810
typedef pair <int, int> PII;
typedef vector <int> VI;
//#define int long long
#define all(x) x.begin(),  x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
#define il inline
#define RESET(x) memset((x), 0, sizeof(x))

const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
LL qread() {
    char c = getchar();
    int neg = 1;
    LL val = 0;
    while (c != '-' && !isdigit(c)) c = getchar();
    if (c == '-') {
        c = getchar(); 
        neg = -1;
    }
    while (isdigit(c)) {
        val = (val << 3) + (val << 1) + c - '0';
        c = getchar();
    }
    return neg * val;
}
int fa[200020], sz[200020];
il void init(int size) {
    rep(i, size) {
        fa[i] = i;
        sz[i] = 1;
    }
}
il int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
il void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    fa[y] = x;
    sz[x] += sz[y];
}
il bool same(int x, int y) {return find(x) == find(y);}
int n, m;
const int N = 200020;
vector <int> G[N];
vector <PII> colors[N];
vector <PII> queries;
il PII normalize(PII x) {return mp(min(x.first, x.second), max(x.first, x.second));}
il PII normalize(int x, int y) {return mp(min(x, y), max(x, y));}
map <PII, int> memory;
VPII fix;
il void large(int color) {
    init(n);
    for (auto e: colors[color]) merge(e.first, e.second);
    rep(i, fix.size()) {
        if (same(fix[i].first, fix[i].second))
            ++memory[normalize(fix[i].first, fix[i].second)];
    }
}
int nodes[N];
il void small(int color) {
    RESET(nodes);
    int tot = 0; 
    for (auto e: colors[color]) {
        nodes[++tot] = (e.first);
        nodes[++tot] = (e.second);
    }
    sort(nodes + 1, nodes + tot + 1);
    tot = unique(nodes + 1, nodes + tot + 1) - (nodes + 1);
    repn(i, tot) {fa[nodes[i]] = nodes[i]; sz[nodes[i]] = 1;}
    rep(i, colors[color].size()) merge(colors[color][i].first, colors[color][i].second);
    repn(i, tot)
        for (int j = i + 1; j <= tot; j++)
            if (same(nodes[i], nodes[j])) 
                if (memory.count(mp(nodes[i], nodes[j]))) 
                    memory[mp(nodes[i], nodes[j])]++;
}
int ne[N];
void solve() {
    n = qread(); m = qread();
    rep(i, m) {
        int u = qread(), v = qread(); --u; --v;
        G[u].pb(v);
        G[v].pb(u);
        int c = qread(); --c;
        ne[c]++;
        colors[c].pb(normalize(mp(u, v)));
    }
    int q = qread();
    rep(i, q) {
        int u = qread(), v = qread(); --u; --v;
        queries.pb(normalize(u, v));
        if (!memory.count(normalize(u, v))){
            fix.pb(normalize(u, v));
            memory.insert(mp(normalize(u, v), 0));    
        }
    }
    int BL = sqrt(m);
    rep(i, m) {
        if (ne[i]) {
            if (ne[i] >= BL) large(i); 
            else small(i);
        }
    }
    rep(i, q) {
        printf("%d\n", memory[normalize(queries[i].first, queries[i].second)]);
    }

}
signed main() {
    int T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}
