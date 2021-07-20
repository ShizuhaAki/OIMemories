
// Problem : E. Erase Subsequences
// Contest : Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/E
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
	char c = getchar();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
string s, t;
const int N = 410;
vector < vector <int> > nxt;
int dp[N][N], n, m;
bool run(string a, string b) {
	int sa = a.length(), sb = b.length();
	memset(dp, INF, sizeof(dp));
	dp[0][0] = 0;
	rep(i, n + 1) {
		rep(j, m + 1) {
			if (dp[i][j] > n) continue;
			int cur = dp[i][j];
			if (i < sa && nxt[cur][a[i]] < INF) dp[i + 1][j] = min(dp[i + 1][j], nxt[cur][a[i]] + 1);
			if (j < sb && nxt[cur][b[j]] < INF) dp[i][j + 1] = min(dp[i][j + 1], nxt[cur][b[j]] + 1);
		}
	}
	return dp[sa][sb] < INF;
}
string solve() {
	rep(i, m) {
		if (run(t.substr(0, i), t.substr(i, m))) return "YES";
	}
	return "NO";
}
int main() {
	int T = qread();
	while (T--) {
		cin >> s >> t;
		n = s.length(), m = t.length();
		rep(i, n) s[i] -= 'a';
		rep(j, m) t[j] -= 'a';
		//prework next array
		nxt.assign(n + 1, vector <int> (26, INF));
		for (int i = n - 1; i >= 0; i--) {
			nxt[i] = nxt[i + 1];
			nxt[i][s[i]] = i;
		}
		cout << solve() << endl;
	}
	return 0;
}
