#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cstddef>
#include <cmath>
#include <vector>
#include <queue>
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
#define GRAPH 19260817
#ifdef GRAPH
typedef pair <int, int> Edge;
#define v first
#define w second
#endif
#ifdef GEOMETRY
typedef pair <int, int> Point;
#define x first
#define y second
#endif
#ifdef FILEIO
#define FILEOPEN(in, out) freopen(in, "r", stdin);freopen(out, "w", stdout);
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
const int MAXN = 5050;
int n, m ,t;
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
typedef tuple <int, int, int> TII;
vector <Edge> G[MAXN];
int dp[MAXN][MAXN];
int path[MAXN][MAXN];
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> t;
	rep(i, m) {
		int x, y, z;
		cin >> x >> y >> z;
		G[x].pb(mp(y, z));
	}
	memset(dp, INF, sizeof(dp));
	__gnu_pbds::priority_queue < TII, less <TII>, pairing_heap_tag> pq;
	dp[1][1] = 0;
	pq.push(make_tuple(0, 1, 1));
	until(pq.empty()) {
		int x = get< 0 >(pq.top()), y = get< 1 >(pq.top()), z = get < 2 > (pq.top());
		pq.pop();
		if (x != dp[y][z])continue;
		for (auto e:G[z]) {
			if (dp[y + 1][e.v] > x + e.w) {
				dp[y + 1][e.v] = x + e.w;
				path[y + 1][e.v] = z;
				pq.push(make_tuple(dp[y + 1][e.v], y + 1, e.v));
			}
		}
	}
	vector <int> res;
	int x = -1;
	for (int i = n; i >= 1; i--) {
		if (dp[i][n] <= t) {
			x = n;
			while (i >= 1) {
				res.pb(x);
				x = path[i][x];
				i--;
			}
			break;
		}
	}
	reverse(res.begin(), res.end());
	cout << res.size() << endl;
	for (auto i:res)cout << i << ' ';
	cout << endl;
	return 0;
}

