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
const LL INFLL = lshll(60);
const long double EPS = 1e-6;
const int MAXN = 100010;
LL dp[MAXN];
LL c[MAXN], v[MAXN];
int n, q, a, b;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)cin >> v[i];
	for (int i = 1; i <= n; i++)cin >> c[i];
	while (q--) {
		cin >> a >> b;
		LL mx = 0, mxx = 0, plc = 0;
		for (int i = 1; i <= n; i++)dp[i] = -INFLL;
		for (int i = 1; i <= n; i++) {
			LL col = c[i], val = v[i];
			dp[col] = max(dp[col], 
			          max(dp[col] + val * a, 
					     ((plc == col) ? mxx : mx) + val * b));
			if (plc == col)mx = dp[col];
			else if (dp[col] > mx) {
				mxx = mx;
				mx = dp[col];
				plc = col;
			}
			else if (dp[col] > mxx) {
				mxx = dp[col];
			}
		}
		cout << mx << endl;

	}
	return 0;
}

