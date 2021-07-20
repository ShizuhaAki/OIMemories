/*
ID: yzshang1
LANG: C++11
TASK:
*/
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
int n;
vector < pair <int, int> > a;
int main() {
	int T; cin >> T;
	while (T--) {
		cin >> n;
		a.clear();
		repn(i, n) {
			int x, y;
			cin >> x >> y;
			a.pb(mp(x, y));
		}
		sort(a.begin(), a.end(), [](pair <int, int> x, pair <int, int> y) {
			int x1 = x.first, y1 = x.second;
			int x2 = y.first, y2 = y.second;
			if (y2 != y1) return y1 < y2;
			else return x1 < x2;
		});
		int curx = 0, cury = 0;
		string ans;
		rep(i, n) {
			int x = a[i].first, y = a[i].second;
			if (x < curx || y < cury) goto ESCAPE_NO;
			while (curx < x) ans += "R", curx++;
			while (cury < y) ans += "U", cury++;
		}
		puts("YES");
		cout << ans << endl;
		continue;
		ESCAPE_NO:puts("NO");
	}
	return 0;
}

