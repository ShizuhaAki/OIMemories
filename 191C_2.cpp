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
const int N = 100010;
int fa[N], hson[N], dfn[N], sz[N], dep[N], rnk[N], top[N], tot, n, m, w[N], v[N];
vector <int> G[N];
void dfs1(int u) {
	sz[u] = 1;
	for (auto v:G[u])
		if (v != fa[u]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs1(v);
			sz[u] += sz[v];
			if (hson[u] == 0 || sz[v] > sz[hson[u]]) hson[u] = v;
		}
}
void dfs2(int u, int tp) {
	top[u] = tp;
	tot++;
	dfn[u] = tot;
	rnk[tot] = u;
	if (hson[u]) dfs2(hson[u], tp);
	for (auto v:G[u]) if (v != hson[u] && v != fa[u]) dfs2(v, v);
}
long long lc[4 * N], rc[4 * N];
long long sum[4 * N], add[4 * N];
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1) 
inline void pushup(int p) {
	sum[p] = sum[lson(p)] + sum[rson(p)];
} 
inline void pushdown(int p) {
	if (add[p]) {
		sum[lson(p)] += add[p] * (rc[lson(p)] - lc[lson(p)] + 1);
		sum[rson(p)] += add[p] * (rc[rson(p)] - lc[rson(p)] + 1);
		add[lson(p)] += add[p];
		add[rson(p)] += add[p];
		add[p] = 0;
	}
}
inline void build(int p, int l, int r) {
	lc[p] = l, rc[p] = r;
	if (l == r) {
		sum[p] = 0;
		return;
	}
	long long mid = (l + r) >> 1;
	build(lson(p), l, mid);
	build(rson(p), mid + 1, r);
	pushup(p);
}
inline void change(int p, int l, int r, int d) {
	if (l <= lc[p] && r >= rc[p]) {
		sum[p] += d * (rc[p] - lc[p] + 1);
		add[p] += d;
		return;
	}
	pushdown(p);
	long long mid = (lc[p] + rc[p]) >> 1;
	if (l <= mid) change(lson(p), l, r, d);
	if (r > mid) change(rson(p), l, r, d);
	pushup(p);
}
inline long long ask(int p, int l, int r) {
	if (l <= lc[p] && rc[p] <= r) {
		return sum[p];
	}
	pushdown(p);
	long long res = 0;
	long long mid = (lc[p] + rc[p]) >> 1;
	if (l <= mid) res += ask(lson(p), l, r);
	if (r > mid) res += ask(rson(p), l, r);
	return res;
}
void modify(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		change(1, dfn[top[u]], dfn[u], 1); 
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	change(1, dfn[u], dfn[v], 1);
	/*
	          | 0
	          v/ \
	          1   2
	        #/ \
	         3 4
	         ^ ^
	         | |
	         
	    Without the next statement, the edge marked with '#' will be counted twice
	    (Modification are marked with arrows)
	*/
	change(1, dfn[u], dfn[u], -1);  
}
vector <PII> q;
void solve() {
    n = qread();
    repn(i, n - 1) {
        int u = qread(), v = qread();
        G[u].pb(v); G[v].pb(u);
        q.pb(mp(u, v));
    }
    dep[1] = 1; fa[1] = 1;
    dfs1(1); dfs2(1, 1);
    build(1, 1, n);
    m = qread();
    repn(i, m) {
        int x = qread(), y = qread();
        modify(x, y);
    }
  //  rep(i, n + 1) fprintf(stderr, "%lld ", ask(1, dfn[i], dfn[i]));
    rep(i, n - 1) {
        int x = q[i].first, y = q[i].second;
        if (dep[x] > dep[y]) swap(x, y);
        printf("%lld ", ask(1, dfn[y], dfn[y]));
    }
}
int main() {
    int T = 1;
    //int T = qread();
    while (T--) solve();
    return 0;
}
