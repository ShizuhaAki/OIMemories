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
int n;
string s;
const int N = 505;
int dp[N][N];
int DP(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l > r) return dp[l][r] = 0;
	if (l == r) return dp[l][r] = 1;
	dp[l][r] = 1 + DP(l + 1, r);
	for (int i = l + 1; i <= r; i++)
		if (s[l] == s[i])
			dp[l][r] = min(dp[l][r], DP(l + 1, i - 1) + DP(i, r));
	return dp[l][r];
}
int main() {
	cin >> n >> s;
	memset(dp, -1, sizeof(dp));
	cout << DP(0, n - 1) << endl;
	return 0;
}

