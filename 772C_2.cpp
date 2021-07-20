#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define int long long
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 200020;
int forbid[N], n, m, dp[N], path[N];
vector <int> G[N];
int gcd(int x, int y) {return y == 0 ? x : gcd(y, x % y);}
int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b, a % b, x, y);
	int z = x; x = y; y = z - y * (a / b);
	return d;
}
main() {
	cin >> n >> m;
	rep(i, n) {
		int x;
		cin >> x;
		forbid[x] = true;
	}
	rep(i, m) {	if (!forbid[i]) G[gcd(i, m)].pb(i);	} if (forbid[0]) G[m].pb(0);
//	cerr << "PREWORK CORRECT!!!" << endl;
	repn(i, m) {
		if (!G[i].empty()) {
			dp[i] = 0;
			path[i] = 0;
			repn(j, i - 1) {
				if (i % j == 0 && dp[j] > 0) {
					if (dp[j] <= dp[i]) continue;
					dp[i] = dp[j];
					path[i] = j;
				}
			}
			dp[i] += G[i].size();
		}
	}
	vector <int> ans;
	int now = m;
	while (!G[now].empty()) {
		for (auto i:G[now]) ans.pb(i);
		now = path[now];
	}
	reverse(ans.begin(), ans.end());
	if (forbid[0]) ans.pop_back();
	cout << ans.size() << endl;
	int cur = 1;
	for (auto i:ans) {
		int x, y;
		int d = exgcd(cur, m, x, y);
		cout << ((x * i / d) % m + m) % m << ' ';
		cur = i;
	} 
	return 0;
}

