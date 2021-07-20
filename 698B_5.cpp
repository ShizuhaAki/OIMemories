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
const int N = 200020;
vector <int> G[N];
vector <int> comp[N];
int vis[N], cnt, fa[N], n;vector <int> v;
void dfs(int u) {
	if (vis[u]) return;
	vis[u] = true; comp[cnt].pb(u);
	for (auto v:G[u]) dfs(v);
}
int main() {
	n = qread();
	repn(i, n) fa[i] = qread(), G[i].pb(fa[i]), G[fa[i]].pb(i);
	repn(i, n) {
		if (vis[i]) continue;
		cnt++;
		dfs(i);
		int cur = comp[cnt][0];
		rep(j, comp[cnt].size()) cur = fa[cur];
		v.pb(cur);
	}
	int rt = -1;
	repn(i, n) if (fa[i] == i) {
		rt = i;
		cnt--;
		break;
	}
	if (rt == -1) {
		rt = v[0];
		fa[rt] = rt;
	} 
	int ans = 0;
	rep(i, v.size()) if (fa[v[i]] != rt) {
		ans++; fa[v[i]] = rt;
	}
	printf("%d\n", cnt);
	repn(i, n) printf("%d ", fa[i]);puts("");
	return 0;
}

