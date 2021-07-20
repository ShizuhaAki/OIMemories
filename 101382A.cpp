#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
typedef pair <int, int> PII;
#define int long long
#define all(x) (x.begin(),  x.end())
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
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
map <int, int> b;
vector <int> a;
int n, k;
void dfs(int pos, int now, int step) {
	if (now > k) return;
	//if (step > k) return;
	if (pos >= a.size()) {
		if (!step) return;
		if (b.count(now)) b[now] = min(b[now], step);
		else b[now] = step;
		return;
	}
	dfs(pos + 1, now, step);
	if (now * a[pos] <= k) dfs(pos + 1, now * a[pos], step + 1);
	int cnt = 2;
	int v = now * a[pos];
	while (v <= k && a[pos] != 1)  {
		v *= a[pos];
		dfs(pos + 1, v, step + cnt);
		cnt++;
	}
}
int dp[100010];
vector < pair <int, int> > bank;
signed main() {
#ifndef CHTHOLLY
	freopen("complexity.in", "r", stdin);
	freopen("complexity.out", "w", stdout);
#endif
	n = qread(); k = qread();
	int nn = n;
	while (nn > 1) {
		a.pb(nn);
		nn = floor(log2(nn));
	}
	a.pb(1);
	dfs(0, 1, 0);
	repn(i, k) dp[i] = k + k;
//	for (auto p:b) cerr << p.first << ' ' << p.second << endl;
	b[1] = 1;
	for (auto p:b) bank.pb(p);
	dp[0] = 0;
	rep(i, bank.size()) repn(j, k) if (j - bank[i].first >= 0) {dp[j] = min(dp[j], dp[j - bank[i].first] + bank[i].second);}
	//repn(i, k) cerr << dp[i] << ' '; cerr << endl;
	cout << dp[k] << endl;
	return 0;
}
