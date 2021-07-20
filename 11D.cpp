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
const int N = 20;
int d[N][N]; LL dp[lsh(N - 1)][N]; int  n, m;
int lowbit(int x) {
	rep(i, 20) if (lsh(i) & x) return i;
}
int main() {
	cin >> n >> m;
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		d[u][v] = d[v][u] = 1;
	}
	rep(i, n) dp[lsh(i)][i] = 1;
	rep(s, lsh(n))
		rep(i, n)
			if (dp[s][i])
				for (int j = lowbit(s) + 1; j < n; j++) {
					if (d[i][j] && !(s & lsh(j))) dp[s | lsh(j)][j] += dp[s][i];
				}
	LL ans = 0;
	rep(s, lsh(n))
		if (__builtin_popcount(s) >= 3)
			rep(i, n) 
				if (d[i][lowbit(s)])
					ans += dp[s][i];
	cout << ans / 2 << endl;
	return 0;
}

