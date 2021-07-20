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
const int N = 51;
char grid[N][N];
int vis[N][N], n, m;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool hasCycle = false;
void dfs(int x, int y, int fx, int fy) {
	if (vis[x][y]) {
	//	cout << x << ' ' << y << ' ' << fx << ' ' << fy << endl;
		hasCycle = true;
		return;
	}
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (1 <= nx && nx <= n && 1 <= ny && ny <= m ) {
			if (nx == fx && ny == fy) continue;
			if (grid[nx][ny] == grid[x][y]) {
				 dfs(nx, ny, x, y);
			} 
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", grid[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (!vis[i][j]) dfs(i, j, -1, -1);
			if (hasCycle) {
				puts("Yes");
				return 0;
			}
		}
	puts("No"); 
	return 0;
}
