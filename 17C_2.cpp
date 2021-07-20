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
const int N = 160;
int f[N][60];
int dp[N][60][60][60], n;
const int MOD = 51123987;
char s[N];
int main() {
	cin >> n;
	scanf("%s", s + 1);
	f[n + 1][0] = f[n + 1][1] = f[n + 1][2] = n + 1;
	for (int i = n; i >= 1; i--) {
		f[i][0] = f[i + 1][0];
		f[i][1] = f[i + 1][1];
		f[i][2] = f[i + 1][2];
		if (s[i] == 'a') f[i][0] = i;
		if (s[i] == 'b') f[i][1] = i;
		if (s[i] == 'c') f[i][2] = i;
	}
	int m = (n + 2) / 3;
	int ans = 0;
	dp[1][0][0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int a = 0; a <= m; a++)
			for (int b = 0; b <= m; b++)
				for (int c = 0; c <= m; c++) {
					int now = dp[i][a][b][c];
					if (a + b + c == n && abs(a - b) <= 1 && abs(b - c) <= 1 && abs(c - a) <= 1) {
						ans += now;
						ans %= MOD;
					}
					if (f[i][0] <= n) dp[f[i][0]][a + 1][b][c] += now, dp[f[i][0]][a + 1][b][c] %= MOD;
					if (f[i][1] <= n) dp[f[i][1]][a][b + 1][c] += now, dp[f[i][1]][a][b + 1][c] %= MOD;
					if (f[i][2] <= n) dp[f[i][2]][a][b][c + 1] += now, dp[f[i][2]][a][b][c + 1] %= MOD; 
				}
	cout << ans << endl; 
	return 0;
}

