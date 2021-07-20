/*
ID: yzshang1
LANG: C++11
TASK: Holes
*/
#include <bits/stdc++.h>
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
int n, m;
const int N = 100010;
int a[N];
int dep[N], fa[N], vis[N];
vector <int> G[N];
void addEdge(int x) {
	int u = x, v = ((x + a[x]) > n) ? n + 1 : x + a[x];
	G[u].pb(v); G[v].pb(u);
//	cerr << "Connect " << u << " " << v << endl;
}
void dfs(int u, int f) {
	vis[u] = true;
	fa[u] = f;
	dep[u] = dep[f] + 1;
	for (auto v:G[u]) {
		if (v != f && !vis[v]) dfs(v, u);
	}
}
int find(int u) {
	cerr << u << endl;
	if (u == n + 1) return -1;
	if (dep[u] == 1) return u;
	return dep[fa[u]] == 1 ? fa[u] : fa[u] = find(fa[u]);
}
void change(int u, int s) {
	int newDest = ((u + s) > n) ? n + 1 : u + s;
	dep[u] = dep[newDest] + 1;
	fa[u] = newDest;
//	find(u);
//	cerr << "Father of " << u << " changed to " << newDest << endl; 
//	cerr << "Depth of " << u << " changed to " << dep[u] << endl; 
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	repn(i, n) cin >> a[i];
	//prework: builds the tree;
	repn(i, n) addEdge(i);
	dep[0] = -1;
	dfs(n + 1, 0);
	repn(i, m) {
		int op, u, s;
		cin >> op;
		if (op == 0) {
			cin >> u >> s;
			change(u, s);
			a[u] = s;
		}
		else if (op == 1) {
			cin >> u;
			int dest = (a[u] + u) > n ? n + 1 : a[u] + u;
		//	cerr << "Father of " << u  << " is " << fa[u] << endl;
			int fnd = find(dest);
			if (fnd != -1) change(u, a[u]);// change(dest, a[dest]);
		//	cerr << "OUT:";
			cout << (fnd == -1 ? u : fnd) << ' ' << dep[u] << endl;
		}
	} 
	return 0;
}

