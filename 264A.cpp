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
const long double EPS = 1e-6;
const int MAXN = 100010;
LL dp[MAXN];
int c[MAXN], v[MAXN];
int n, q, a, b;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	rep(i, n)cin >> c[i + 1];
	rep(i, n)cin >> v[i + 1];
	pair <int, int> mx = {-1, -1}, mxx = {-1, -1};
	while (q--) {
		cin >> a >> b;
		for (int i = 1; i <= n; i++) {
			LL col = c[i], val = v[i];
			if (mx.first == -1) {
				mx.first = i;
				mx.second = v[i] * a;
				dp[col] = v[i] * a;
				continue;
			}
			if (mxx.first == -1) {
				mxx.first = i;
				mx.second = v[i] * b;
				dp[col] = v[i] * b;
				continue;
			}
			dp[col] += v[col] * a;
			if (dp[col] > mx.second) {
				mx.first = col;
				mx.second = dp[col];
			}
			if (mxx.second + v[col] * b > dp[col]) {
				dp[col] = mxx.second + v[col] * b;
				if (col != mxx.first) {
					mxx.first = col;
					mxx.second = dp[col];
				}
			}
		}
		cout << *max_element(dp + 1, dp + n + 1) << endl;
		for (int i = 1; i <= n; i++)dp[i] = 0;
	}
	return 0;
}

