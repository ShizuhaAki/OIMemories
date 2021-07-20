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
int vis[N], n, m, flg = true;
vector <int> G[N];
void DFS(int u, int c) {
	if (vis[u]) {
		if (vis[u] != c) flg = false;
		return;
	}
	vis[u] = c;
	for (auto v:G[u]) DFS(v, 3 - c);
} 
int main() {
	n = qread(), m = qread();int u, v;
	repn(i, m) {u = qread(); v = qread(); G[u].pb(v); G[v].pb(u);}
	repn(i, n) {if (!vis[i]) DFS(i, 1);}
	if (!flg) {cout << -1 << endl; return 0;}
	printf("%d\n", count(vis + 1, vis + n + 1, 1));repn(i, n) if (vis[i] == 1) printf("%d ", i);
	printf("\n%d\n", count(vis + 1, vis + n + 1, 2));repn(i, n) if (vis[i] == 2) printf("%d ", i);
	return 0;
}

