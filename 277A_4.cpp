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
const int N = 210;
int n, m, vis[N];
bool zero = true;
vector <int> G[N];
void dfs(int u) {
	vis[u] = true;
	for (auto v:G[u]) if (!vis[v]) dfs(v);
}
int main() {
	scanf("%d%d", &n, &m);
	repn(i, n) {
		int k;
		scanf("%d", &k);
		if (k) zero = false;
		while (k--) {
			int x;
			scanf("%d", &x);
			G[i].pb(x + n);
			G[x + n].pb(i);
		}
	}
	if (zero) {
		printf("%d\n", n);
		return 0;
	}
	int ans = 0;
	repn(i, n) {
		if (!vis[i]) {
			dfs(i);
			ans++;
		}
	} 
	printf("%d\n", ans - 1); 
	return 0;
}

