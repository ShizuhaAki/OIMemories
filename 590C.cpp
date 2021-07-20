
// Problem : C. Three States
// Contest : Codeforces Round #327 (Div. 1)
// URL : https://codeforces.com/contest/590/problem/C
// Memory Limit : 512 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define pf push_front
#define mp make_pair
#define y1 y114514
#define y2 y1919810
typedef pair <int, int> PII;
#define all(x) (x.begin(),  x.end())
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = s; (i) <= (int)t; (i)++)
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
int n, m;
const int N = 1100;
string a[N];
int ans = INF;
int vis[N][N];
int dist[3][N][N];
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int main() {
	n = qread(); m = qread();
	rep(i, n) cin >> a[i];
	deque < pair <int, int> > q;
	memset(dist, -1, sizeof(dist));
	rep(p, 3) {
		q.clear();
		rep(i, n) rep(j, m) if (a[i][j] - '1' == p) {dist[p][i][j] = 0;q.pb(mp(i, j));}
		while (!q.empty()) {
	//		cerr << q.size() << endl;
			int x = q.front().first;
			int y = q.front().second;
			q.pop_front();
			rep(i, 4) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#') continue;
				int nd = dist[p][x][y] + (a[nx][ny] == '.');
				if (dist[p][nx][ny] > nd || dist[p][nx][ny] == -1) {
					dist[p][nx][ny] = nd;
					if (a[nx][ny] == '.') q.pb(mp(nx, ny));
					else q.pf(mp(nx, ny));
				}
			}
		}
	}
//	cerr << 65 << endl;
	int ans = INF;
	rep(i, n) rep(j, m) {
		if (dist[0][i][j] != -1 && dist[1][i][j] != -1 && dist[2][i][j] != -1) {
			ans = min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2 * (a[i][j] == '.'));
		}
	}
	cout << ((ans == INF) ? -1 : ans) << endl;
	return 0;
}
