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
#define mp make_pair
#define pb push_back
#define GRAPH 1
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
int n, m, t;
vector <Edge> G[N];
int dp[N][N], path[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> t;
	rep(i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].pb(mp(v, w));
	}
	memset(dp, INF, sizeof(dp));
	dp[1][0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[j][i - 1] != INF) {
				for (auto k: G[j]) {
					if (dp[k.v][i] > dp[j][i - 1] + k.w) {
						dp[k.v][i] = dp[j][i - 1] + k.w;
						path[k.v][i] = j;
					}
				}
			}
		}
	}
	int besti;
	for (int i = 1; i <= n; i++) {
		if (dp[n][i] <= t)besti = i;
	}
	int u = n;
	vector <int> ans;
	ans.pb(n);
	while (u != 1) {
		u = path[u][besti];
		besti--;
		ans.pb(u);
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto i:ans)cout << i << ' ';
	cout << endl;
	return 0;
}

