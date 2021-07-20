#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
using LL = long long;
using ULL = unsigned long long;
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define int long long
#define fail(s) assert(!s)
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
int m, n;
const int N = 200020;
int lim[N];
vector <int> G[N];
#define from first
#define to second
int vis[N], dp[N], path[N];
int exgcd(int a,int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int z = x; x = y; y = z - y * (a / b);
    return d;
}
signed main()
{
	ios::sync_with_stdio(false);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	if (n){
		rep(i, n) {
			int x;
			cin >> x;
			lim[x] = true;
		}
	}
	rep(u, m) {
		if (lim[u])continue;
		G[__gcd(u, m)].pb(u);
	}
	if (lim[0])G[m].pb(0);
	memset(dp, 0, sizeof(dp));
	rep(i, m + 1) {
		if (i == 0)continue;
		if (!G[i].empty()) {
			dp[i] = 0;
			path[i] = 0;
			rep (j, i) {
				if (j == 0)continue;
				if (i % j == 0 && dp[j] > 0) {
					if (dp[j] > dp[i]) {
						dp[i] = dp[j];
						path[i] = j;
					}
				}
			}
			dp[i] += G[i].size();
		}
	}
	vector <int> ans;
	int x = m;
	while (!G[x].empty()) {
		for (auto y:G[x])ans.pb(y);
		x = path[x];
	}
	cout << ans.size() << endl;
	reverse(ans.begin(), ans.end());
	if (lim[0])ans.pop_back();
	int cur = 1;
	for (auto i:ans) {
		int x, y;
	//	cur = i;
		int d = exgcd(cur, m, x, y);
		cout << ((x * i / d) % m + m) % m << ' ';
		cur = i;
	}
	return 0;
}

