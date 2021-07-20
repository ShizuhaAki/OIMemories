#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cstddef>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#define pb push_back
#define mp make_pair
#define GRAPH
#ifdef GRAPH
typedef pair <int, int> Edge;
#define v first
#define w second
#endif
#ifdef GEOMETRY
typedef pair <int, int> Point;
#define x first
#define y second
#endif
#ifdef FILEIO
#define FILEOPEN(in, out) freopen(in, "r", stdin);freopen(out, "w", stdout);
#endif
using LL = long long;
using ULL = unsigned long long;
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
const int N = 5050;
vector <Edge> G[N];
int vis[N], n, m, t;
vector <int> topo;
typedef pair <int, int> PII;
PII dp[N][N];
void dfs(int u) {
	vis[u] = true;
	for (auto e:G[u])if (!vis[e.v])dfs(e.v);
	topo.pb(u);
}
void toposort() {
	rep(i, n)if (!vis[i])dfs(i);
	reverse(topo.begin(), topo.end());
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> t;
	for (int i = 0; i <= 5000; i++)
		for (int j = 0; j <= 5000; j++)
			dp[i][j] = mp(INF, INF);
	rep(i, m) {
		int x, y, z;
		cin >> x >> y >> z;
		x--;y--;
		G[x].pb(mp(y, z)); 
	} 
	toposort();
	dp[0][1] = mp(0, 0);
	for (auto x :topo) {
		for (auto y : G[x]) {
			for (int k = 1; k < n; k++) {
				dp[y.v][k + 1] = min(dp[y.v][k + 1], mp(dp[x][k].first + y.w, x));
			}
		} 
	} 
	int besti = 0;
	for (int i = n; i >= 1; i--) 
		if (dp[n - 1][i].first <= t) {
			besti = i;
			break;
		}
	vector <int> ans;
	ans.clear();
	ans.pb(n - 1);
	int v = n - 1;
	do {
		v = dp[v][besti].second;
		besti--;
		ans.pb(v);
	}while (v);
	cout << ans.size() << endl;
	reverse(ans.begin(), ans.end());
	for (auto i : ans)cout << i + 1 << ' ';
	cout << endl;
	return 0;
}

