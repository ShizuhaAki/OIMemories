#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#define pb push_back
#define mp make_pair
#ifdef GRAPH
typedef pair <int, int> Edge;
#define v first
#define w second
#endif
using LL = long long;
using ULL = unsigned long long;
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
vector <int> path[10][10][10][10];
void dfs(int x, int y, int st, int v, int dep, vector <int> now) {
	if (dep > 10)return;
	if (path[x][y][st][(v + x) % 10].empty() || path[x][y][st][(v + x) % 10].size() > now.size() + 1) {
		now.pb(x);
		path[x][y][st][(v + x) % 10] = now;
		dfs(x, y, st, (v + x) % 10, dep + 1, now);
		now.pop_back();
	}
	if (path[x][y][st][(v + y) % 10].empty() || path[x][y][st][(v + y) % 10].size() > now.size() + 1) {
		now.pb(y);
		path[x][y][st][(v + y) % 10] = now;
		dfs(x, y, st, (v + y) % 10, dep + 1, now);
		now.pop_back();
	}
} 
int main() {
	ios::sync_with_stdio(false);
	vector <int> em(0);
	rep(i, 10)rep(j, 10)rep(st, 10)dfs(i, j, st, st, 1, em);
	string s;
	cin >> s;
	rep(i, 10) {
		rep(j, 10) {
			int ans = 0;
			bool ok = 1;
			rep(k, s.length() - 1) {
				auto& p = path[i][j][s[k] - '0'][s[k + 1] - '0'];
				if (p.empty()) {
					ok = 0;
					break;
				}
				ans += p.size() - 1;
			}
			if (!ok)cout << -1 << ' ';
			else cout << ans << ' ';
		}
		cout << endl;
	}
	return 0;
}

