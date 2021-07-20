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
const int N = 5050;
struct Edge {
	int v, w;
	Edge(int v = 0, int w = 0) : v(v), w(w) {}
};
vector <Edge> G[N];
int dp[N][N], route[N][N], indeg[N];
int n, m, T;
int main() {
	cin >> n >> m >> T;
	rep(i, m) {
		int u, v, w;
		cin >> u >> v >> w;// u--; v--;
		G[u].pb(Edge(v, w));
	//	G[v].pb(Edge(u, w));
	}
	memset(dp, INF, sizeof(dp));
	dp[1][0] = 0;
	repn(i, n - 1) {
		repn(j, n) {
			if (dp[j][i - 1] != INF) {
				for (auto e:G[j]) {
					int v = e.v, w = e.w;
					if (dp[v][i] > dp[j][i - 1] + w) {
						dp[v][i] = dp[j][i - 1] + w;
						route[v][i] = j;
					}
				}
			}
		}
	}
	int besti = -1;
	for (int i = n; i >= 1; i--) {
		if (dp[n][i] <= T) {
			besti = i;
			break;
		}
	} 
	cout << besti + 1 << endl;
	vector <int> ans;
	ans.pb(n);
	int u = n;
	int x = besti;
	while (x) {
		u = route[u][x];
		x--;
		ans.pb(u);
	}
	reverse(ans.begin(), ans.end());
	for (auto i:ans) cout << i << ' ';
	return 0;
}

