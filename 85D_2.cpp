#include <bits/stdc++.h>
#define int long long
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
const int N = 1 << 17;
vector <PII> query;
int n;
map <int, int> m;
int cnt[N * 2], c;
int sum[N * 2][5];
void pushup(int x) {
	int ls = x << 1, rs = x << 1 | 1;
	cnt[x] = cnt[ls] + cnt[rs];
	rep(i, 5) sum[x][i] = sum[ls][i] + sum[rs][(i - cnt[ls] % 5 + 5) % 5];
}
signed main() {
	n = qread();
	rep(i, n) {
		string buf; cin >> buf;
		if (buf == "add") {
			int x = qread();
			query.pb(mp(0, x));
			m[x] = 0;
		}
		else if (buf == "del") {
			int x = qread();
			query.pb(mp(1, x));
			m[x] = 0;
		}
		else query.pb(mp(2, 0));
	}
	for (auto& p:m) { p.second = c; c++;}
	rep(i, n) {
		int op = query[i].first, v = query[i].second;
		if (op == 2) cout << sum[1][2] << endl;
		else {
			int id = N + m[v];
			cnt[id] = 1 - op;
			sum[id][0] = (1 - op) * v;
			for (int j = id / 2; j >= 1; j >>= 1) pushup(j);
		}
	}
	return 0;
}
