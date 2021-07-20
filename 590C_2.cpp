#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair <int, int> PII;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
long long qread() {
	char c = getchar(); int neg = 1; long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar(); if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
const int N = 1010, INF = 0x3f3f3f3f;
int n, m;
string a[N];
deque <PII> q;
int d[3][N][N];
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
#define pf push_front
int main() {
	n = qread(); m = qread(); rep(i, n) cin >> a[i];
	memset(d, -1, sizeof d);
	rep(p, 3) {
		rep(x, n) rep(y, m) if (a[x][y] - '1' == p) { d[p][x][y] = 0; q.pb(mp(x, y));}
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second; q.pop_front();
			rep(i, 4) {
				int nx = x + dx[i], ny = y + dy[i];
				if (!(-1 < nx && nx < n && -1 < ny && ny < m && a[nx][ny] != '#')) continue;
				int nd = d[p][x][y] + (a[nx][ny] == '.');
				if (d[p][nx][ny] == -1 || d[p][nx][ny] > nd) { d[p][nx][ny] = nd; a[nx][ny] == '.' ? q.pb(mp(nx, ny)) : q.pf(mp(nx, ny));}
			}
		}
	}
	int ans = INF; 
	rep(i, n) rep(j, m) if ([i, j](){rep(x, 3) if (d[x][i][j] == -1) return false; return true;}()) 
		ans = min(ans, [i, j](){int r = 0;rep(x, 3)r += d[x][i][j];return r - 2 * (a[i][j] == '.');}());
	cout << (ans == INF ? -1 : ans) << endl;
	return 0;
}
