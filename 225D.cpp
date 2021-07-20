#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int N = 20;
const int HASHMOD = 19260817;
const int HASHSIZE = 10007;
char grid[N][N];
deque < pair <int, int> > snake;
int n, m, l, stx, sty, enx, eny;
map < deque < pair <int, int> > , int> best;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main() {
	scanf("%d%d", &n, &m);
	repn(i, n) scanf("%s", grid[i] + 1);
	repn(i, n) repn(j, m) {
		if (isdigit(grid[i][j])) l = max(l, grid[i][j] - '0');
		if (grid[i][j] == '1') {
			stx = i;
			sty = j;
		}
		if (grid[i][j] == '@') {
			enx = i;
			eny = j;
		}
	}
	int crx = stx, cry = sty;
	repn(i, l) {
		snake.pb(mp(crx, cry));
		int found = false;
		rep(j, 4) {
			int nx = crx + dx[j];
			int ny = cry + dy[j];
			if (grid[nx][ny] == grid[crx][cry] + 1 && isdigit(grid[nx][ny])) {
				crx = nx;
				cry = ny;
				found = true;
				break;
			}
			if (found) break;
		}
	}
	queue < deque < pair <int, int> > > q;
	q.push(snake);
	best[snake] = 0;
	int ans = 0;
	while (!q.empty()) {
		deque < pair <int, int> > u = q.front();
		q.pop();
		ans = best[u];
		rep(i, 4) {
			deque < pair <int, int> > v = u;
			int nx = (v.front()).first + dx[i], ny = v.front()second + dy[i];
			//it would be obviously illegal if the next point is not even on the grid
			//or the point is not passable
			if (!(0 < nx && nx <= n && 0 < ny && ny <= m) || grid[nx][ny] == '#') continue;
			//check whether the place has been taken by any part of the snake other than the tail
			bool bad = false;
			rep(j, (int)(v.size() - 1)) {
				if (v[j].first == nx && v[j].second == ny) {
					bad = true;
					break;
				}
			}
			if (bad) continue;
			if (grid[nx][ny] == '@') {
				printf("%d\n", ans + 1);
				return 0;
			}
			v.pop_back();
			v.push_front(mp(nx, ny)); 
			if (best.find(v) == best.end()) {
				best[v] = ans + 1;
				q.push(v);
			}
		}
	}
	puts("-1");
	return 0;
}
