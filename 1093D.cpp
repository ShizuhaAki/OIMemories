#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define LL long long
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
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
const int N = 300030;
int col[N], n, m, red, cerulean;bool flg = 1;
vector <int> G[N];
void dfs(int u, int nowcol) {
	col[u] = nowcol;
	if (nowcol == 0) red++;
	else if (nowcol == 1) cerulean++;
	for (auto v:G[u]) {
		if (col[v] < 0) dfs(v, nowcol ^ 1);
		else if (col[v] == nowcol) {
			flg = false;
			return;
		}
	} 
}
LL pw[N];
int main() {
	int T = qread();
	pw[0] = 1;
	repn(i, 300010) pw[i] = (pw[i - 1] << 1) % MOD;
	while (T--)  {
		n = qread(), m = qread();
		rep(i, n + 10) col[i] = -1, G[i].clear(); flg = true;
		rep(i, m) {
			int u, v;
			u = qread(); v = qread();
			--u; --v;
			G[u].pb(v);
			G[v].pb(u);
		}
		LL ans = 1;
		rep(i, n) {
			if (col[i] == -1) {
				red = cerulean = 0;
				dfs(i, 0);
				if (!flg) {
					ans = 0;
					break;
				}
				ans = ans * (pw[red] + pw[cerulean]) % MOD;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

