#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define LL long long
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c;
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
const int N = 300030, MOD = 998244353;
vector <int> G[N];
int col[N], red, cerulean, n, m; LL pw[N]; bool bad = false;
void dfs(int u, int c) {
	col[u] = c;
	if (c == 0)red++; if (c == 1)cerulean++;
	for (auto v:G[u]) {
		if (col[v] < 0) dfs(v, c ^ 1);
		else if (col[v] == col[u]) {
			bad = true;
			return;
		}
	}
}
int main() {
	int T = qread();
	pw[0] = 1;
	repn(i, N + 1) pw[i] = (pw[i - 1] << 1) % MOD;
	while (T--) {
		n = qread(), m = qread(); rep(i, n + 1)G[i].clear(), col[i] = -1; bad = false;
		rep(i, m) {
			int u = qread(), v = qread(); --u; --v;
			G[u].pb(v); G[v].pb(u);
		}
		LL ans = 1;
		rep(i, n) {
			if (col[i] < 0) {
				red = cerulean = bad = 0;
				dfs(i, 0);
				if (bad) {
					ans = 0;
					break;
				}
				ans = (ans * (pw[red] + pw[cerulean]) % MOD) % MOD; 
			} 
		}
		cout << ans << endl;
	} 
	return 0;

}

