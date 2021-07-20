
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
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = s; (i) <= (int)t; (i)++)
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
int n, m;
const int N = 5050;
vector < pair <int, int> > G[N];
typedef pair < pair <int, int>, int> lwl;
vector < lwl > q;
pair <int, int> fa[N];
int vis[N], dep[N], val[N];
vector < pair <int, int> > edge;
void dfs(int u, int f) {
	vis[u] = true; 
	dep[u] = dep[f] + 1;
	for (auto e:G[u]) {
		int v = e.first, id = e.second;
		if (!vis[v] && v != f) {
			fa[v] = mp(u, id);
			dfs(v, u);
		}
	}
}
int main() {
	n = qread();
	rep(i, n - 1) {
		int u = qread(), v = qread(); --u; --v;
		G[u].pb(mp(v, i)); G[v].pb(mp(u, i));
	}
	dfs(0, -1);
	m = qread();
	rep(i, m) {
		int x = qread(), y = qread(), g = qread(); --x; --y;
		q.pb(mp(mp(x, y), g));
	}
	sort(q.begin(), q.end(), [](const lwl& a, const lwl& b) {return a.second < b.second;});
	//fill
	rep(i, m) {
		int u = q[i].first.first, v = q[i].first.second, g = q[i].second;
//		cerr << "PROCESSING QUERY " << u << " " << v << endl;
		if (dep[u] > dep[v]) swap(u, v);
		while (dep[v] > dep[u]) {
	//		cerr << "   CURRENT PLACE " << u << " " << v << endl;
			auto e = fa[v];
			v = e.first;
			val[e.second] = max(val[e.second], g);
	//		cerr << "   COLORED " << e.second << " WITH " << val[e.second] << endl;
		}
		while (u != v) {
	//		cerr << "   CURRENT PLACE " << u << " " << v << endl;
			auto eu = fa[u], ev = fa[v];
			u = eu.first, v = ev.first;
			val[eu.second] = max(val[eu.second], g);
			val[ev.second] = max(val[ev.second], g);
	//		cerr << "   COLORED " << eu.second << " WITH " << val[eu.second] << endl;
	//		cerr << "   COLORED " << ev.second << " WITH " << val[ev.second] << endl;
		}
	}
	rep(i, n - 1) if (val[i] == 0) val[i] = 1000000;
//	rep(i, n - 1) cerr << val[i] << ' '; cerr << endl;
	//check
	bool bad = false;
	rep(i, m) {
		int u = q[i].first.first, v = q[i].first.second, g = q[i].second;
		if (dep[u] > dep[v]) swap(u, v);
		bool good = false;
		while (dep[v] > dep[u]) {
			auto e = fa[v];
			v = e.first;
			if (val[e.second] < g) {bad = true; break;}
			if (val[e.second] == g) good = true;
		}
		while (u != v) {
			auto eu = fa[u], ev = fa[v];
			u = eu.first, v = ev.first;
			if (val[eu.second] < g || val[ev.second] < g) {bad = true; break;}
			if (val[eu.second] == g || val[ev.second] == g) good = true;
		}
		if (!good || bad) {bad = true; break;}
	}
	if (bad) {cout << -1 << endl; return 0;}
	else {rep(i, n - 1) cout << val[i] << ' '; cout << endl; return 0;}
	return 0;
}
