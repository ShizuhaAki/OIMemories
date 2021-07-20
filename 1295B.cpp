
// Problem : B. Infinite Prefixes
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/B
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define int long long
#define double long double
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
//const long double EPS = 1e-6;
const int N = 100010;
signed main() {
	int T; cin >> T;
	while (T--) {
		int n, x;
		string s;
		map <int, int> cnt;
		int pre = 0;
		cin >> n >> x;
		cin >> s;
		int minn = INF, maxx = -INF;
		rep(i, s.length()) {
			pre = pre + (s[i] == '0' ? 1 : -1);
			cnt[pre]++;
			minn = min(minn, pre);
			maxx = max(maxx, pre);
		}
		int delta = pre;
		if (delta == 0) {
			if (!cnt.count(x)) cout << 0 << endl;
			else cout << -1 << endl;
			continue;
		}
		int resix = x % (maxx - minn + 1);
		int ans = 0;
		for (auto it:cnt) {
			int a = it.first, b = it.second;
			if ((pre - a + x) % delta == 0 && (pre - a + x) * delta > 0) ans += b;
		}
		if (x == 0)   ans++;
		cout << ans << endl;
	}
	return 0;
}
