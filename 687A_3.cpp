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
long long qread() {
	char c;
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
const int N = 100010;
vector <int> G[N];
int col[N], n, m;
bool bad = false;
void dfs(int u, int c) {
	col[u] = c;
	for (auto v:G[u]) {
		if (col[v] < 0) dfs(v, c ^ 1);
		if (col[v] == c) {
			bad = true;
			return;
		}
	}
}
int main() {
	n = qread(), m = qread();
	rep(i, m) {
		int u = qread(), v = qread(); u--; v--;
		G[u].pb(v); G[v].pb(u);
	}
	memset(col, -1, sizeof(col));
	rep(i, n) {
		if (col[i] < 0) {
			dfs(i, 0);
			if (bad) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	printf("%d\n", count(col, col + n, 1)); rep(i, n) if (col[i] == 1) printf("%d ", i + 1); puts("");
	printf("%d\n", count(col, col + n, 0)); rep(i, n) if (col[i] == 0) printf("%d ", i + 1); puts("");
	return 0;
}

