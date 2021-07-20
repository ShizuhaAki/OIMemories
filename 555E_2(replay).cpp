
// Problem: B - Case of Computer Network
// Contest: Virtual Judge - RavenclawOIer's Timed Training 1
// URL: https://vjudge.net/contest/387932#problem/B
// Memory Limit: 262 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define VPII vector <PII>
#define I int
#define y2 y1919810
typedef pair <I, I> PII;
typedef vector <I> VI;
//#define I long long
#define all(x) x.begin(),  x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (I i = 1; i <= (I)n; i++)
#define rep(i, n) for (I i = 0; i < (I)n; i++)
#define range(i, s, t)  for (I i = s; i <= (I)t; i++)
#define il inline
#define vo void
#define RESET(x) memset((x), 0, sizeof(x))
#define au auto

const I INF = 0x3f3f3f3f;
const long double EPS = 1e-6;

LL qread() {
    char c = getchar();
    I neg = 1;
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
const I N = 300020;
VPII G[N]; VI T[N];
I bcccnt, bccID[N];
namespace tarjan {
    I dfn[N], low[N], tot;
    stack <I> s;
    vo tarjan(I u, I eid = 0) {
        dfn[u] = low[u] = ++tot;
        s.push(u);
        for (auto e: G[u]) {
            I v = e.first, id = e.second;
            if (!dfn[v]) {
                tarjan(v, id);
                low[u] = min(low[u], low[v]);
            } else if (id != eid) low[u] = min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            bcccnt++;
            while (!s.empty()) {
                I t = s.top(); s.pop();
                bccID[t] = bcccnt;
                if (t == u) break;
            }
        }
    }
}
I n, m, q;
I up[N], down[N];
I comp[N], ctot;
vo getComp(I u, I f, I cid) {
    comp[u] = cid;
    for (au v: T[u]) if (v != f) getComp(v, u, cid);
}
namespace lca {
    I dfn[N], top[N], dep[N], fa[N], hson[N], sz[N];
    vo dfs1(I u) {
        sz[u] = 1;
        for (auto v: T[u]) {
            if (v == fa[u]) continue;
            dep[v] = dep[u] + 1; fa[v] = u;
            dfs1(v);
            sz[u] += sz[v];
            if (!hson[u] || sz[hson[u]] < sz[v]) hson[u] = v;
        }
    }
    I tot = 0;
    vo dfs2(I u, I t) {
        top[u] = t;
        dfn[u] = ++tot;
        if (hson[u]) dfs2(hson[u], t);
        for (auto v: T[u]) if (v != hson[u] && v != fa[u]) dfs2(v, v);
    }
    I lca(I u, I v) {
        while (top[u] != top[v]) if (dep[top[u]] > dep[top[v]]) u = fa[top[u]]; else v = fa[top[v]];
        return dep[u] > dep[v] ? v : u;
    }
    vo init(I x) {
        fa[x] = 1;
        dep[x] = 1;
        dfs1(x);
        dfs2(x, x);
    }
}
I vis[N];
vo calc(I u, I f = 0) {
    vis[u] = true;
    for (auto v: T[u]) if (v != f) {
        calc(v, u);
        up[u] += up[v];
        down[u] += down[v];
    }
    if (up[u] && down[u]) {
        // conflict
        puts("No");
        exit(0);
    }
}
vo solve() {
    n = qread(); m = qread(); q = qread();
    rep(i, m) {
        I u = qread(), v = qread();
        G[u].pb(mp(v, i));
        G[v].pb(mp(u, i));
    }
    repn(i, n) if (!tarjan::dfn[i]) tarjan::tarjan(i);
    repn(u, n) 
        for (auto e: G[u]) {
            int v = e.first;
            if (bccID[u] != bccID[v])
                T[bccID[u]].pb(bccID[v]);
        }
    n = bcccnt;
    repn(u, n) if (!comp[u]) {getComp(u, 0, ++ctot); lca::init(u);}
    while (q--) {
        I u = bccID[qread()], v = bccID[qread()];
        if (comp[u] != comp[v]) {puts("No"); return;}
        if (u == v) continue;
        int lca = lca::lca(u, v);
        up[u]++; up[lca]--;
        down[v]++; down[lca]--;
    }
    repn(u, n) if (!vis[u]) calc(u); 
    puts("Yes");
}
signed main() {
    I T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}

