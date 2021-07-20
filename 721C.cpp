#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
typedef pair <int, int> Edge;
#define v first
#define w second
#define mp make_pair
#define pb push_back 
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int EPS = 1e-6;
const int MAXN = 5050;
vector <Edge> G[MAXN];
int n, m, T;
int dp[MAXN][MAXN];
int DP(int x, int y) {
	if (y == 1)return (x == n - 1) ? 0 : INF;
	if (dp[x][y] <= INF)return dp[x][y];
	for (auto e:G[x]) {
		dp[x][y] = min(dp[x][y], min(INF, DP(e.v, y - 1) + e.w));
	}
	return dp[x][y];
}
int cnt = 0, ans = -1;
void print(int x, int y) {
	if (cnt < ans)cout << x + 1 << ' ';
	cnt++;
	if (y == 1)return;
	for (auto e:G[x]) 
		if (dp[e.v][y - 1] + e.w == dp[x][y]) {
			print(e.v, y - 1);
			break;
		}
}
int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> T;
	rep(i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		--u;--v;
		G[u].pb(mp(v, w));
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = INF + 1;
	dp[n - 1][1] = 0;
	for (int i = n; i > 1; i--) {
		if (DP(0, i) <= T) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	print(0, ans);
	cout << endl;
	return 0;
}

