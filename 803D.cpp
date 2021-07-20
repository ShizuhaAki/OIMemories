
// Problem : D. Magazine Ad
// Contest : Educational Codeforces Round 20
// URL : https://codeforces.com/problemset/problem/803/D
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = 1; (i) <= (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
int k; string s; vector <int> wrap;
bool check(int mid) {
	int cnt = 1;
	int sum = 0;
	rep(i, wrap.size()) {
		sum += wrap[i];
		if (sum > mid) {
			sum = wrap[i];
			cnt++;
		}
	}
	return cnt <= k;
}
int main() {
	cin >> k;
	string ss;
	while (cin >> ss) {
		s += "-";
		s += ss;
	}
	s.erase(s.begin());
	int last = -1;
	int L = 0, R = s.length() + 1;
	rep(i, s.length()) 
		if (s[i] == ' ') {
			wrap.pb(i - last);
			last = i;
			L = max(L, i - last);
		}
	wrap.pb(s.length() - last - 1);
	L = max(L, (int)s.length() - 1 - last);
	while (L + 1 < R) {
		int mid = (L + R) >> 1;
		if (check(mid)) R = mid; else L = mid;
	}
	cout << L << endl;
	return 0;
}
