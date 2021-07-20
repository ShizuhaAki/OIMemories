#include <bits/stdc++.h>
using namespace std;
int n, k;
const int MAXN = 200020;
const int MOD = 1000000007;
#define LL long long
vector < int > g[MAXN];
bool vis[MAXN];
LL sz;
void dfs(int u)
{
	if (vis[u])return;
	sz++;
	vis[u] = true;
	for (auto v:g[u])dfs(v);
}
LL qpow(LL a, LL b, LL p)
{
	LL ans = 1;
	for (; b; b >>= 1)
	{
		if (b & 1)ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}
int main()
{
	cin >> n >> k; 
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v, col;
		cin >> u >> v >> col;
		if (!col)
		{
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	LL ans = qpow(n, k, MOD);
	for (int i = 1; i <= n; i++)
		if (!vis[i]) 
		{
			sz = 0;
			dfs(i);
			ans -= qpow(sz, k, MOD);
			ans += MOD;
			ans %= MOD;
		}
	cout << ans << endl;
	return 0;
}

