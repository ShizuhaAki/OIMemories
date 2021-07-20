
// Problem : C. Perfect Keyboard
// Contest : Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/C
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = qread(); 
	while (T--) {
		string s;
		cin >> s;
		int n = s.length();
		if (s.length() == 1) {
			cout << "YES\nabcdefghijklmnopqrstuvwxyz" << endl;
			continue;
		}
		set <int> req[150];
		rep(i, n - 1) {
			req[s[i]].insert(s[i + 1]);
			req[s[i + 1]].insert(s[i]);
		}
		bool bad = false;
		rep(i, n) if (req[s[i]].size() > 2) {
			cout << "NO" << endl;
			bad = true;
			break;
		}
		if (bad) continue;
		int beg = -1;
		rep(i, n) if (req[s[i]].size() == 1) {
			beg = s[i];
			break;
		}
		if (beg == -1) {
			cout << "NO" << endl;
			continue;
		}
		if (bad) continue;
		bool start = true;
		vector <int> vis; vis.resize(150);
		int now = beg;
		vis[now] = true;
		string ans;
		ans.pb(now);
		while (!(!start && req[now].size() == 1)) {
			//cerr << (char)now << endl;
			start = false;
			vis[now] = true;
			for (auto nxt:req[now]) if (!vis[nxt]) {
				vis[nxt] = true;
				now = nxt;
				ans.pb(nxt);
			}
		}
		range(i, 'a', 'z') if (!vis[i]) ans.pb(i);
		cout << "YES" << endl << ans << endl;
	}
	return 0;
}
