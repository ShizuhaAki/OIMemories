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
const string result[] = {"Cry", "Break a heart", "Flowers"};
const int N = 5020;
int dp[N][N][2];
vector < pair <int, int> > G[N];
int n, m, s, t;
struct node {
	int dist1, dist2, w;
	node(int dist1, int dist2, int w) : dist1(dist1), dist2(dist2), w(w) {}
}p[N];
int dis[N];
struct cmp {
	bool operator () (const int a, const int b) const {
		return dis[a] > dis[b];
	}
};
inline void dijkstra(int s) {
	memset(dis, INF, sizeof(dis));
	dis[s] = 0;
	priority_queue <int, vector <int>, cmp> pq; pq.push(s);
	while (!pq.empty()) {
		int u = pq.top(); pq.pop();
		vis[u] = false;
		for (auto e:G[u]) {
			int v = e.first, w = e.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) {
					vis[v] = true;
					pq.push(v);
				}
			}
		}
	} 
}
int a[N][N], b[N][N], ret[N]; 
vector <int> discrete(void) {
	int COUNT = 1; 
	ret[0] = 1;
	repn(i, n - 1) {
		if (dis[i] != dis[i - 1]) COUNT++;
		ret[i] = COUNT;
	}
}
void prework(void) {
	dijkstra(s);
	discrete();
	rep(i, n) p[i].dist1 = ret[i];
	dijkstra(t);
	discrete();
}
int main(void) {
	cin >> n >> m >> s >> t;
	rep(i, n) cin >> p[i].w;
	rep(i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		--u;
		--v;
		G[u].pb(mp(v, w));
		G[v].pb(mp(u, w));
	}
	prework();
	return 0;
}

