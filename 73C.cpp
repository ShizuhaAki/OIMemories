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
#define chmax(a, b) (a = max(a, b))
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
const int MOD = 1e9 + 7;
const int MAXN = 301, MAXC = 57;
int dp[MAXN][MAXN][MAXC];
int M, K;
int d[MAXN][MAXN];
int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for (auto& i:s)i -= 'a';
	cin >> K;
	cin >> M;
	rep(i, M) {
		char u, v;int w;
		cin >> u >> v >> w;
		d[u - 'a'][v - 'a'] = w;

	}
	int len = s.length();
	rep(i, len + 1)
		rep(j, K + 1)
			rep(k, 26)
				dp[i][j][k] = -INF;
	rep(i, 26)dp[0][(s[0] != i)][i] = 0;
	rep(i, len - 1)
		rep(j, K + 1) {
			rep(k, 26) {
				if (dp[i][j][k] != -INF) {
					rep(c, 26) {
						dp[i + 1][j + (c != s[i + 1])][c] = max(dp[i + 1][j + (c != s[i + 1])][c], dp[i][j][k] + d[k][c]);
					}
				}
			}
		}
	int ans = -INF;
	rep(j, K + 1)
		rep(k, 26)
		//	cerr << dp[len - 1][j][k] << endl;
			ans = max(ans, dp[len - 1][j][k]);
	cout << ans << endl;
	return 0;
}
