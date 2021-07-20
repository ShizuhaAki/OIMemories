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
const int N = 130, K = 30;
string s;
int k, n, m;
int d[K][K], dp[N][N][K];
int main() {
	cin >> s;
	n = s.length();
	rep(i, n) s[i] -= 'a';
	cin >> k >> m;
	repn(i, m) {
		char f, t;
		int b;
		cin >> f >> t >> b;
		d[f - 'a'][t - 'a'] = b;
	}
	memset(dp, -INF, sizeof(dp));
	rep(i, 26) dp[0][s[0] != i][i] = 0; 
	rep(i, n - 1) {
		rep(j, k + 1) {
			rep(p, 26) {
				if (dp[i][j][p] != -INF) {
					rep(q, 26) {
						dp[i + 1][j + (s[i + 1] != q)][q] = max(dp[i + 1][j + (s[i + 1] != q)][q], dp[i][j][p] + d[p][q]);
					}
				}
			}
		}
	}
	int ans = -INF;
	rep(i, k + 1)
		rep(c, 26)
			ans = max(ans, dp[n - 1][i][c]);
	cout << ans << endl;
	return 0;
}

