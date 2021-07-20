#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 155, MOD = 51123987;
long long qread() {
	char c;
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
char s[N];
int n;
int dp[N][60][60][60], nxt[N][3];
#define valid(x) (x) <= n
int main() {
	cin >> n; scanf("%s", s + 1);
	nxt[n + 1][0] = nxt[n + 1][1] = nxt[n + 1][2] = n + 1;
	for (int i = n; i >= 1; i--) {
		nxt[i][0] = nxt[i + 1][0];
		nxt[i][1] = nxt[i + 1][1];
		nxt[i][2] = nxt[i + 1][2];
		if (s[i] == 'a') nxt[i][0] = i;
		if (s[i] == 'b') nxt[i][1] = i;
		if (s[i] == 'c') nxt[i][2] = i;
	}
	memset(dp, 0, sizeof(dp));
	dp[1][0][0][0] = 1;
	int ans = 0;
	repn(i, n) {
		rep(j, (n + 2) / 3 + 1) {
			rep(k, (n + 2) / 3 + 1) {
				rep(l, (n + 2) / 3 + 1) {
					const int &now = dp[i][j][k][l];
					if (j + k + l == n && abs(l - j) <= 1 && abs(j - k) <= 1 && abs(k - l) <= 1) {
						ans += now;
						ans %= MOD;
						continue;
					}
					if (valid(nxt[i][0])) dp[nxt[i][0]][j + 1][k][l] += now, dp[nxt[i][0]][j + 1][k][l] %= MOD;
					if (valid(nxt[i][1])) dp[nxt[i][1]][j][k + 1][l] += now, dp[nxt[i][1]][j][k + 1][l] %= MOD;
					if (valid(nxt[i][2])) dp[nxt[i][2]][j][k][l + 1] += now, dp[nxt[i][2]][j][k][l + 1] %= MOD;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}

