
// Problem : F. Number of Components
// Contest : Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/F
// Memory Limit : 256.000000 MB 
// Time Limit : 4000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c = getchar();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
const int N = 310, C = 2000020;;
int fa[C], a[N][N];
int n, m, q, c;
vector <pair <int, int> > add[C], del[C];
int in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
struct dsu {
	int fa[C], cnt, sz[C];
	void makeset(int b) {rep(i, b) fa[i] = i, sz[i] = 1;}
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]); }
	int merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return 0;
		if (sz[x] < sz[y]) swap(x, y);
		fa[y] = x;
		sz[x] += sz[y];
		return 1;
	}
}u;
int change[C];
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
#define x first
#define y second
void run(vector < pair <int, int> >& v, int mode) {
	rep(i, n) rep(j, m) a[i][j] = 0;
	u.makeset(n * m + 10);
	for (auto i:v) {
		int cur = 1;
		int x = i.x / m, y = i.x % m;
		a[x][y] = 1;
		rep(j, 4) {
			int nx = x + dx[j], ny = y + dy[j];
			if (in(nx, ny) && a[nx][ny] == 1) 
				cur -= u.merge(nx * m + ny, x * m + y);
		}
		change[i.y] += cur * mode;
	}
}
int main() {
	n = qread(); m = qread(); q = qread();
	rep(i, q) {
		int x = qread(), y = qread(), col = qread();
		--x; --y;
		if (a[x][y] == col) continue;
		c = col + 1;
		add[col].pb(mp(x * m + y, i));
		del[a[x][y]].pb(mp(x * m + y, i));
		a[x][y] = col;
	}
	rep(i, n) rep(j, m) del[a[i][j]].pb(mp(i * m + j, q));
	rep(i, c) reverse(del[i].begin(), del[i].end());
	rep(i, c) run(add[i], 1);
	rep(i, c) run(del[i], -1);
	int ans = 1;
	rep(i, q) {
		ans += change[i];
		printf("%d\n", ans);
	}
	return 0;
}
