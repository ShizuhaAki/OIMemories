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
#define GRAPH
#define mp make_pair
#define pb push_back
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
const int N = 5050;
vector <Edge> G[N];
int dp[N][N], path[N][N];
int n, m, t;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> t;
	rep(i, m) {
		int uu, vv, ww;
		cin >> uu >> vv >> ww;
		uu--;
		vv--;
		G[uu].pb(mp(vv, ww));
	}
	memset(dp, -1, sizeof(dp));
	memset(path, -1, sizeof(path));
	dp[0][0] = 0;
	vector <int> res;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i - 1][j] != -1) {
				for (auto k:G[j]) {
					if (dp[i - 1][j] + k.w > t)continue;
					if (dp[i][k.v] == -1 || dp[i][k.v] > dp[i - 1][j] + k.w) {
						dp[i][k.v] = dp[i - 1][j] + k.w;
						path[i][k.v] = j;
					}
				}
			}
		}
		if (dp[i][n - 1] >= 0) {
			res.clear();
			int cu = n - 1;
			int ii = i;
			while (cu != -1) {
				res.pb(cu);
				cu = path[ii][cu];
				ii--;
			} 
			reverse(res.begin(), res.end());
		}
	}
	cout << res.size() << endl;
	for (auto i: res)cout << i + 1 << ' ';
	cout << endl;
	return 0;
}

