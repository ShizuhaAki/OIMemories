#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
typedef pair <int, int> PII;
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
void dfs(int pos, int now, int step) {
	if (now > 100000) return;
	if (b.count(now))b[now] = min(b[now], step);
	else b[now] = step;
	range(i, 0, a.size() - 1) {
		int v = a[i];
		now *= v;
		dfs(i, now, step + 1);
		now /= v;
	}
}
int main() {
	freopen("bf.out", "w", stdout);
	int nn = qread();
	while (nn > 1) {
		a.pb(nn);
		nn = floor(log2(nn));
	}
	dfs(0, 1, 0);
	for (auto p:b) cout << p.first << ' ' << p.second << endl;
	return 0;
}

