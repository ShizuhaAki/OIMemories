#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define int long long
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 2e5 + 10;
vector < pair <int, int> > G[N];
int m, n, k, t, a[N];
bool check(int x) {
	int ans = 0;
	int right = -1;
	repn(i, n) {
		for (auto j:G[i]) if (j.second > a[x]) right = max(right, j.first);
		if (i <= right)ans += 2;
	}
//	printf("checking %d, a[x] = %d, time = %d\n", x, a[x], ans + n + 1);
	return ans <= t;
}
signed main() {
	cin >> m >> n >> k >> t; t -= (n + 1);
	repn(i, m) cin >> a[i];
	sort(a + 1, a + m + 1); reverse(a + 1, a + m + 1);
	a[0] = 1e9;
	int l, r, d;
	repn(i, k) cin >> l >> r >> d, G[l].pb(mp(r, d));
	int L = 0, R = m + 1;
	while (L + 1 < R) {
		int mid = (L + R) >> 1;
		if (check(mid)) {
			L = mid;
		}
		else R = mid;
	} 
	cout << L << endl;
	return 0;
}
