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
int col[N], n, m, vis[N];bool flag = 1;
vector <int> G[N];
void dfs(int u, int nowcol) {
	col[u] = nowcol; vis[u] = 1;
	for (auto v:G[u]) {
		if (col[v] < 0) dfs(v, nowcol ^ 1);
		else if (col[v] == nowcol) {
			flag = false;
			return;
		}
	} 
}
int main() {
	n = qread(), m = qread();
	rep(i, m) {
		int u = qread(), v = qread();--u;--v;
		G[u].pb(v); G[v].pb(u);
	}
	memset(col, -1, sizeof(col));
	rep(i, n) {
		flag = true;
		if (vis[i]) continue;
		dfs(i, 0);
		if (flag == false) cout << -1 << endl, exit(0);
	}
	vector <int> chtholly, nephren;
	rep(i, n) if (col[i]) chtholly.pb(i); else nephren.pb(i);
	printf("%d\n", (int)chtholly.size());
	for (auto i:chtholly)printf("%d ", i + 1);
	puts("");
	printf("%d\n", (int)nephren.size());
	for (auto i:nephren)printf("%d ", i + 1);
	return 0;
}

