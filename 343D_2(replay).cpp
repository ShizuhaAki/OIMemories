
// Problem: A - Water Tree
// Contest: Virtual Judge - RavenclawOIer's Timed Training 1
// URL: https://vjudge.net/contest/387927#problem/A
// Memory Limit: 262 MB
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
#define vo void
#define au auto
#define re return
#define I int
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
const I N = 3000099;
namespace sgt {
    I t[N], lazy[N], lc[N], rc[N];
    #define ls p << 1
    #define rs p << 1 | 1
    il vo d(I p) {
        if (lazy[p] != -1) {
            t[ls] = lazy[p] * (rc[ls] - lc[ls] + 1);
            t[rs] = lazy[p] * (rc[rs] - lc[rs] + 1);
            lazy[ls] = lazy[rs] = lazy[p];
            lazy[p] = -1;
        }
    }
    vo b(I p, I l, I r) {
       lc[p] = l;
       rc[p] = r;
       lazy[p] = -1;
       if (l == r) return;
       int m = (l + r) >> 1;
       b(ls, l, m);
       b(rs, m + 1, r);
    }
    I q(I p, I x) {
        d(p);
        if (lc[p] >= x && x == rc[p]) return t[p];
        if (x < lc[p] || x > rc[p]) return 0;
        return q(ls, x) + q(rs, x);
    }
    vo m(I p, I l, I r, I v) {
        d(p);
        if (lc[p] >= l && r >= rc[p]) {
            t[p] = v * (rc[p] - lc[p] + 1);
            lazy[p] = v;
            return;
        }
        if (r < lc[p] || l > rc[p]) return;
        m(ls, l, r, v);
        m(rs, l, r, v);
    }
}
I in[N], out[N];
VI G[N];
I n, q;
namespace hld {
    I dfn[N], top[N], fa[N], dep[N], sz[N], hson[N];
    vo d1(I u) {
        sz[u] = 1;
        for (au v: G[u]) {
            if (v == fa[u]) continue;
            fa[v] = u;
            dep[v] = dep[u] + 1;
            d1(v);
            sz[u] += sz[v];
            if (!hson[u] || sz[hson[u]] < sz[v]) hson[u] = v;
        }
    }
    int tot;
    vo d2(I u, I t) {
        top[u] = t;
        tot++;
        dfn[u] = tot;
        in[u] = tot;
        if (hson[u]) d2(hson[u], t);
        for (au v: G[u]) if (v != hson[u] && v != fa[u]) d2(v, v);
        out[u] = tot;
    }
    vo go() {
        fa[1] = 1;
        dep[1] = 1;
        d1(1);
        d2(1, 1);
        sgt::b(1, 1, n);
    }
    vo m(I x) {
        I u = x, v = 1;
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            sgt::m(1, dfn[top[u]], dfn[u], 0);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        sgt::m(1, dfn[u], dfn[v], 0);
    }
    I q(I x) {
        return sgt::q(1, dfn[x]);
    }
}
vo solve() {
    n = qread();
    rep(i, n - 1) {
        I u = qread(), v = qread();
        G[u].pb(v); G[v].pb(u);
    }
    hld::go();
    q = qread();
    while (q--) {
        I op = qread(), u = qread();
        if (op == 1) sgt::m(1, in[u], out[u], 1);
        elif (op == 2) hld::m(u);
        else printf("%d\n", hld::q(u));
    }
}
signed main() {
    int T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}
