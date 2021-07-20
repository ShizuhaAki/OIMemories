
// Problem : F. Berland Beauty
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/F
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = s; (i) <= (int)t; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c = cin.get();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = cin.get();
	if (c == '-') c = cin.get(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = cin.get();
	return neg * val;
}
const int N = 5050;
int dfn[N], top[N], dep[N], rnk[N], fa[N], sz[N], hson[N], tot, n, p[N];
map < pair <int, int>, int > e;
vector <int> G[N];
void dfs1(int u) {
	sz[u] = 1; hson[u] = -1;
	for (auto v:G[u]) if (v != fa[u]) {
		fa[v] = u;
		dep[v] = dep[u] + 1;
		p[v] = e[mp(u, v)];
	//	printf("p[%d] = %d\n", v, p[v]);
		dfs1(v);
		sz[u] += sz[v];
		if (hson[u] == -1 || sz[v] > sz[hson[u]]) hson[u] = v;
	}
}
void dfs2(int u, int tp) {
	top[u] = tp;
	dfn[u] = ++tot;
	rnk[tot] = u;
	if (hson[u] != -1) dfs2(hson[u], tp);
	for (auto v:G[u]) if (v != hson[u] && v != fa[u]) dfs2(v, v);
}
int a[N];
struct brute_force {
	void assign(int l, int r, int v) {--l;--r;range(i, l, r) a[p[i]] = v;}
	int ask(int l, int r) {--l;--r;int ret = INF; range(i, l, r) ret = min(ret, a[p[i]]); return ret;}
}t;
struct Query {
	int u, v, d;
	bool operator < (const Query b) const {return d < b.d;}
	Query(int u, int v, int d) : u(u), v(v), d(d) {}
};
vector <Query> q;
void modify(int u, int v, int d) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		t.assign(dfn[top[u]], dfn[u], d);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	t.assign(dfn[v], dfn[u], d);
}
int ask(int u, int v) {
	int res = INF;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		res = min(res, t.ask(dfn[top[u]], dfn[u]));
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	res = min(res, t.ask(dfn[v], dfn[u]));
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	n = qread();
	repn(i, n - 1) {
		int u = qread(), v = qread();
		G[u].pb(v); G[v].pb(u);
		e[mp(u, v)] = e[mp(v, u)] = i;
	}
	fa[1] = 1; dep[1] = 1; p[1] = 0;
//	memset(a, -1, sizeof(a));
	dfs1(1); dfs2(1, 1);
	int nQuery = qread();
	while (nQuery--) {
		int u = qread(), v = qread(), d = qread();
		q.pb(Query(u, v, d));
	}
	sort(q.begin(), q.end());
	for (auto x:q) modify(x.u, x.v, x.d);
//	range(i, 1, n - 1) cout << a[p[i]] << ' '; cout << endl;
	range(i, 1, n - 1) {/*cerr << a[p[i]] << ' ';*/if (a[p[i]] <= 0) a[p[i]] = 1000000;}

	range(i, 1, n - 1) cout << a[p[i]] << ' '; cout << endl;
	for (auto x:q) if (ask(x.u, x.v) != x.d) {cout << -1 << endl; return 0;}
	range(i, 1, n - 1) cout << a[p[i]] << ' '; cout << endl;
	return 0;
}
