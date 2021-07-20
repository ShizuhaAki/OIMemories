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
const int N = 200020;
vector <int> G[N];
int n, m;
bool bad = false;
int col[N];
vector < pair <int, int> > e;
void dfs(int u, int c) {
	col[u] = c;
	for (auto v:G[u]) {
		if (col[v] < 0) dfs(v, c ^ 1);
		else if (col[v] == c) {
			puts("NO");
			exit(0);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	memset(col, -1, sizeof(col));
	repn(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v); G[v].pb(u); e.pb(mp(u, v));
	}
	dfs(1, 0);
	puts("YES");
	repn(i, m) 
		printf("%d", col[e[i - 1].first] == 1);
	return 0;
}

