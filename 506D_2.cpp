#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
int n, m, c;
const int N = 100002;
unordered_map <int, int> fa[N], __size[N];
long long qread() {
	char c;
	long long neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
int find(int u, int c) {
	return fa[u][c] == u ? u : fa[u][c] = find(fa[u][c], c);
}
void merge(int u, int v, int c) {
	if (!fa[u].count(c)) fa[u][c] = u, __size[u][c] = 1;
	if (!fa[v].count(c)) fa[v][c] = v, __size[v][c] = 1;
	u = find(u, c);
	v = find(v, c);
	if (__size[u][c] >  __size[v][c]) swap(u, v);
	if (u != v) fa[u][c] = v;
	__size[v][c] += __size[u][c];
}
unordered_map <int, int> mem[N];
int main() {
	n = qread(); m = qread();
	repn(i, m) {
		int u, v, c;
		u = qread(); v = qread(); c = qread();
		merge(u, v, c);
	}
	int q;
	q = qread();
	while (q--) {
		int u, v;
		u = qread(); v = qread();
		if (fa[u].size() > fa[v].size()) swap(u, v);
		if (mem[u][v]) {
			cout << mem[u][v] << endl;
			continue;
		}
		int ans = 0;
		for (auto i:fa[u]) {
			if (fa[v].count(i.first) && find(u, i.first) == find(v, i.first)) ans++;
		}
		mem[u][v] = ans;
		cout << ans << endl; 
	}
	return 0;
}

