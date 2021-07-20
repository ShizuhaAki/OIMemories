
// Problem : C. Obtain The String
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/C
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
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
string s, t;
#define cur t[i] - 'a'
int main() {
	int T; cin >> T;
	while (T--) {
		cin >> s >> t;
		vector <int> app[27];
		rep(i, s.length()) app[s[i] - 'a'].pb(i);
		int prev = -1, ans = 0;
		int i = 0;
		while (i < t.length()) {
			int j = 0;
			while (j < (int)s.length() && i < (int)t.length()) {
				if (app[cur].empty()) {
					ans = -1;
					break;
				}
				auto it = lower_bound(app[cur].begin(), app[cur].end(), j);
				if (it == app[cur].end()) break;
				j = *it + 1;
				i++;
			}
			if (ans == -1) break;
			//start of a new attempt, increase ans
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
