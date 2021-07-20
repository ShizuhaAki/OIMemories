
// Problem : D. Same GCDs
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define int long long
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
vector <LL> factor;
void fact(LL x) {
	factor.clear();
	int y = x;
	for (int i = 2; i * i <= y; i++) {
		if (x % i == 0) factor.pb(i);
		while (x % i == 0) x /= i;
	}
	if (x > 1) factor.pb(x);
}
LL euler(LL x) {
	fact(x);
	LL res = x;
	for (auto f:factor) {
		res /= f;
		res *= (f - 1);
	}
	return res;
}
signed main() {
	int T; cin >> T;
	while (T--) {
		LL a, b;                                                          
		cin >> a >> b;
		LL d = __gcd(a, b);
		LL ans = 0;
		ans = euler(b / d);
		cout << ans << endl;
	}
	return 0;
}
