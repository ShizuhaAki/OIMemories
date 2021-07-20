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
const int N = 12;
const int w[4][3][3] = {{{1, 1, 1},{0, 1, 0},{0, 1, 0}},{{1, 0, 0},{1, 1, 1},{1, 0, 0}},{{0, 1, 0},{0, 1, 0},{1, 1, 1}},{{0, 0, 1},{1, 1, 1},{0, 0, 1}}};
int n, m, ans;
int grid[N][N], ch[N][N];
inline bool check(int scheme, int posX, int posY) {
	rep(u, 3)
		rep(v, 3)
			if (w[scheme][u][v])
				if (grid[posX + u][posY + v])
					return false;
	return true;
}
const double CTRL = 6.9;
inline void dfs(int x, int y, int cnt) {
	if ((n - x) * m < (ans - cnt) * CTRL) return;
	if (y + 2 >= m) {
		dfs(x + 1, 0, cnt);
		return;
	} 
	if (x + 2 >= n) {
		if (cnt > ans) {
			memcpy(ch, grid, sizeof grid);
			ans = cnt;
		}
		return;
	}
	rep(i, 4) {
		if (check(i, x, y)) {
			cnt++;
			rep(u, 3) rep(v, 3) if (w[i][u][v]) grid[x + u][y + v] = cnt;
			dfs(x, y + 1, cnt);
			rep(u, 3) rep(v, 3) if (w[i][u][v]) grid[x + u][y + v] = 0;
			cnt--;
		}
	}
	dfs(x, y + 1, cnt);
}
inline void print() {
	cout << ans << endl;
	rep(i, n) {
		rep(j, m) cout << (char)(ch[i][j] ? ('A' + ch[i][j] - 1) : '.');
		cout << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	if (n < 3 or m < 3) {
		print();
		return 0;
	}
	dfs(0, 0, 0);
	print();
	return 0; 
}

