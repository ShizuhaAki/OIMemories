
// Problem : C. Air Conditioner
// Contest : Codeforces Round #620 (Div. 2)
// URL : https://codeforces.com/contest/1304/problem/C
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
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
	char c = getchar();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
const int N = 110;
int t[N], l[N], r[N];
signed main() {
	int T; cin >> T;
	while (T--) {
		int n = qread(), m = qread();
		memset(t, 0, sizeof(t));
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		repn(i, n) {
			t[i] = qread();
			l[i] = qread();
			r[i] = qread();
		}
		int L = m, R = m;
		bool ans = true;
	//	if ();
		range(i, 1, n) {
			int delta = t[i] - t[i - 1];
			L -= delta;
			R += delta;
			if ((R < l[i] || L > r[i])) {
				ans = false;
				break;
			}
			L = max(L, l[i]);
			R = min(R, r[i]);
		}
		//cerr << L << " " << R << endl;
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	} 
	return 0;
}
