 
// Problem : B. National Project
// Contest : Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/B
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
#define lsh(i) (1 << (i))
#define int long long
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = s; (i) <= (int)t; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c = cin.get();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = cin.get();
	if (c == '-') c = cin.get(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = cin.get();
	return neg * val;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = qread();
	while (T--) {
		int n = qread(), g = qread(), b = qread();
		int req = ceil(n / 2.0);
		int peri = req / g, rem = req % g;
		if (peri == 0) {
			cout << n << endl;
			continue;
		}
		int full = (peri) * (g + b);
		if (rem == 0) full -=  b;
		cout << max(n, full + rem) << endl; 
	}
	return 0;
}
