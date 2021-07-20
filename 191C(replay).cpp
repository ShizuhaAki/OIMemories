#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;
const int N = 150010;
vector <int> G[N];
namespace sgt {
	int sum[N * 4], lazy[N * 4], lc[N * 4], rc[N * 4];
	#define ls p << 1
	#define rs p << 1 | 1
	inline void pushdown(int p) {
		if (lazy[p]) {
			sum[ls] += lazy[p] * (rc[ls] - lc[ls] + 1);
			sum[rs] += lazy[p] * (rc[rs] - lc[rs] + 1);
			lazy[ls] += lazy[p];
			lazy[rs] += lazy[p];
			lazy[p] = 0;
		}
	}
	inline void pushup(int p) {
		sum[p] = sum[ls] + sum[rs];
	}
	void build(int p, int l, int r) {
		lc[p] = l; rc[p] = r;
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		pushup(p);
	}
	void modify(int p, int l, int r, int d) {
        pushdown(p);
		if (l <= lc[p] && rc[p] <= r ) {
			sum[p] += d * (rc[p] - lc[p] + 1);
			lazy[p] += d;
			return;
		} else if (l > rc[p] || r < lc[p]) return;
		modify(ls, l, r, d);
		modify(rs, l, r, d);
		pushup(p);
	}
	int query(int p, int l, int r) {
        pushdown(p);
		if (l <= lc[p] && rc[p] <= r) {
			return sum[p];
		} else if (l > rc[p] || r < lc[p]) return 0;

		return query(ls, l, r) + query(rs, l, r);
	}
}
namespace hld {
	int sz[N], hson[N], top[N], dep[N], fa[N], dfn[N], rnk[N];
	void dfs1(int u) {
		sz[u] = 1;
		for (auto v: G[u]) {
			if (v == fa[u]) continue;
			dep[v] = dep[u] + 1;
			fa[v] = u;
			dfs1(v);
			sz[u] += sz[v];
			if (!hson[u] || sz[hson[u]] < sz[hson[v]]) hson[u] = v;
		}
	}
	int tot;
	void dfs2(int u, int t) {
		top[u] = t;
		tot++;
		dfn[u] = tot;
		rnk[tot] = u;
		if (hson[u]) dfs2(hson[u], t);
		for (auto v: G[u]) if (v != hson[u] && v != fa[u]) dfs2(v, v);
	}
	void modify(int u, int v) {
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) swap(u, v);
			sgt::modify(1, dfn[top[u]], dfn[u], 1);
			u = fa[top[u]];
		}
		if (dep[u] > dep[v]) swap(u, v);
		sgt::modify(1, dfn[u], dfn[v], 1);
		sgt::modify(1, dfn[u], dfn[u], -1);
	}
}
int n;
vector < pair <int, int> > e;
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		e.push_back(make_pair(u, v));
	}
	hld::dep[1] = 1;
	hld::fa[1] = 1;
	hld::dfs1(1);
	hld::dfs2(1, 1);
	sgt::build(1, 1, n);
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		hld::modify(x, y);
	}
	for (int i = 0; i < n - 1; i++) {
		int u = e[i].first, v = e[i].second;
		if (hld::dep[u] > hld::dep[v]) swap(u, v);
		cout << sgt::query(1, hld::dfn[v], hld::dfn[v]) << ' ';
	}
}