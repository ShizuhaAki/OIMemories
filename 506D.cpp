/*
ID: yzshang1
LANG: C++11
TASK: Mr. Kitayuta's Colorful Graph
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
const int N = 100010;
struct dsu {
	vector <int> fa;
	bool flg = false;
	void makeSet(int n) {
		fa.resize(n + 1);
		repn(i, n) fa[i] = i;
		flg = true;
	}
	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx != fy) fa[fx] = fy;
	}
};
map < int, dsu > s;
map < pair <int, int>, vector <int> > ans;
set < int > large;
vector < pair <int, int> > input[N];
vector < pair <int, int> > G[N];
map < pair <int, int> , int> memory;
int n, m;
bool vis[N];
void DFS(int u, int col) {
	vis[u] = true;
	for (auto e:G[u]) {
		int v = e.first, c = e.second;
		if (vis[v] || c != col) continue;
		ans[mp(u, col)].pb(v);
	//	ans[mp(v, col)].pb(u);
		DFS(v, col);
	}
}
int main() {
	cin >> n >> m;
	rep(i, m) {
		int u, v, c;
		cin >> u >> v >> c;
		input[c].pb(mp(u, v));
		G[u].pb(mp(v, c));
		G[v].pb(mp(u, c));
	}
	int lim = sqrt(m);
	repn(c, m) {
		if (input[c].size() > lim) {
			s[c].makeSet(n); large.insert(c);
			rep(i, input[c].size()) 
				s[c].merge(input[c][i].first, input[c][i].second);
		}
		
	}
	int q;
	cin >> q;
	while (q--) {
		int u, v, res = 0;
		cin >> u >> v;
		repn(c, m) {
			if (large.count(c)) {
				if (s[c].same(u, v)) res++;
			}
			else {
				memset(vis, 0, sizeof(vis));
				if (ans[mp(u, c)].empty())DFS(u, c);
				for (int j:ans[mp(u, c)]) if (j == v) res++;
				if (ans[mp(v, c)].empty()) DFS(v, c);
				for (int j:ans[mp(v, c)]) if (j == u) res++;
			}
		}
		memory[mp(u, v)] = res;
		cout << res << endl;
	}
	return 0;
}

