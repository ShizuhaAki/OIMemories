#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
struct Edge {
	int v, w;
	Edge(int v = 0, int w = 0) : v(v), w(w) {}
};
const int N = 20020, P = 20;
vector <Edge> G[N];
int vis[N], d[N], dis[P][P], place[P], cost[P], dp[lsh(P)][P][2];
int n, p, m, g, t;
inline void spfa(int s) {
	memset(vis, 0, sizeof(vis));
	memset(d, INF, sizeof(d));
	queue <int> q;
	int start = place[s];
	q.push(start);
	d[start] = 0; vis[start] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (auto e:G[u]) {
			int v = e.v, w = e.w;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	} 
	rep(i, p) dis[s][i] = d[place[i]];
}
int main() {
	cin >> n >> p >> m >> g >> t;
	rep(i, p) {
		cin >> place[i] >> cost[i];
		g -= cost[i];
	}
	if (g < 0) {
		cout << "impossible" << endl;
		return 0;
	}
	rep(i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].pb(Edge(v, w));
		G[v].pb(Edge(u, w));
	}
	p++;
	rep(i, p) spfa(i);
	memset(dp, INF, sizeof(dp));
	dp[lsh(p - 1)][p - 1][0] = 0;
	rep(s, lsh(p)) {
		rep(i, p) {
			if (!(lsh(i)) & s) continue;
			rep(j, p) {
				if (lsh(j) & s) continue;
				dp[s ^ lsh(j)][j][0] = min(dp[s ^ lsh(j)][j][0], dp[s][i][0] + dis[i][j]);
				dp[s ^ lsh(j)][j][1] = min(dp[s ^ lsh(j)][j][1], min(dp[s][i][1] + dis[i][j], dp[s][i][0] + t));
			}
		}
	}
	int ans1 = INF, ans2 = INF;
	rep(i, p){
		ans1 = min(ans1, dp[lsh(p) - 1][i][0] + dis[i][p - 1]);
		ans2 = min(ans2, min(dp[lsh(p) - 1][i][1] + dis[i][p - 1], dp[lsh(p) - 1][i][0] + t));
	}
	if (ans1 <= g) 
		cout << "possible without taxi" << endl;
	else if (ans2 <= g)
		cout << "possible with taxi" << endl;
	else cout << "impossible" << endl; 
	
	return 0;
}

