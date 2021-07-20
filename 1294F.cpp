/*
ID: yzshang1
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 200020;
vector <int> G[N];
int n, st, ed;
int dep1[N], dep2[N], dep3[N], vis[N], fa1[N];
int path[N];
bool ban[N];
map < pair <int, int>, int > no;
int maxv, maxi;
void dfs1(int u, int f) {
	vis[u] = true;
	dep1[u] = dep1[f] + 1;
	if (dep1[u] > maxv) {
		maxv = dep1[u];
		maxi = u;
	}
	fa1[u] = f;
	for (auto v:G[u]) {
		if (!vis[v] && v != f) dfs1(v, u);
	}
}
void dfs2(int u, int f) {
	vis[u] = true;
	dep2[u] = dep2[f] + 1;
	if (dep2[u] > maxv) {
		maxv = dep2[u];
		maxi = u;
	}
	for (auto v:G[u]) {
		if (!vis[v] && v != f) {
			path[v] = u;
			dfs2(v, u);
		}
	}
}
void dfs3(int u, int f, int depf) {
	vis[u] = true;
	int depu = depf + 1;
	if (depu > maxv) {
		maxv = depu;
		maxi = u;
	}
	for (auto v:G[u]) {
		if (!ban[no[mp(u, v)]] && !vis[v] && v != f) {
			dfs3(v, u, depu);
		} 
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	repn(i, n - 1) {
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
		no[mp(u, v)] = i;
		no[mp(v, u)] = i;
	}
	dfs1(1, 0);
	st = maxi;
	maxv = maxi = -1;
	repn(i, n) vis[i] = 0;
	path[st] = -1;
	dfs2(st, 0);
	ed = maxi;
//	cerr << st << ' ' << ed << endl;
//	repn(i, n) cerr << dep2[i] << ' '; cerr << endl;
	maxv = maxi = -1;
	vector <int> route;
	int x = ed; route.pb(x);
	while (path[x] != -1) {
		x = path[x];
		route.pb(x);
	}
	int ans = 0;
	rep(i, route.size() - 1) ban[no[mp(route[i], route[i + 1])]] = true, ans++;
	int bestv, besti; 
	bestv = besti = -1;
	for (auto i:route) {
		rep(i, n + 2) vis[i] = 0;
		maxv = maxi = -1;
		dfs3(i, 0, -1);	//	cerr << "START " << i << ", MAXV = " << maxv << ", MAXI = " << maxi << endl;
		if (maxv > bestv) {
			bestv = maxv;
			besti = maxi;
		}
	}
	ans += bestv;
	cout << ans << endl;
	while (besti <= n && (besti == ed || besti == st)) besti++;
	if (besti > n) besti = 1;	
	while (besti < n && (besti == ed || besti == st)) besti++;
	cout << st << ' ' << ed << ' ' << besti << endl;
	return 0;
}

