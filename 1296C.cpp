
// Problem : C. Yet Another Walking Robot
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/C
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
map < pair <int, int>, int> vis;
int n; string s;
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> s;
		vis.clear();  vis[mp(0, 0)] = 0;
		int ansl = -1, ansr = INF;
		int l = -1, r = -1;
		int x = 0, y = 0;
		s = "$" + s;
		bool good = false;
		repn(i, n) {
			if (s[i] == 'L') x--;
			else if (s[i] == 'R') x++;
			else if (s[i] == 'U') y++;
			else if (s[i] == 'D') y--;
			auto it = vis.find(mp(x, y));
			if (it != vis.end()) {
				int l = it -> second + 1, r = i;
				if (r - l > ansr - ansl) goto BREAK;
				ansl = l; ansr = r;
				good = true;
				goto BREAK;
			}
			BREAK:vis[mp(x, y)] = i;
		}
		if (not good) cout << -1 << endl;
		else cout << ansl << ' ' << ansr << endl;
	}
	return 0;
}
