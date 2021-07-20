#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2019;
int n, m, k;
vector <int> g[MAXN]; 
const int MOD = 1000000007;
bool vis[MAXN];
int ans;
void bfs(int s)
{
	queue <int> q;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (vector <int> :: iterator it = g[u].begin(); it != g[u].end(); it++)
		{
			int v = *it;
			if (!vis[v])
			{
				vis[v] = true;
				q.push(v);
			}
		}
	}
}
long long qpow(long long a, long long b, long long p)
{
	long long ans = 1;
	for (; b; b >>= 1)
	{
		if (b & 1)ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i + k - 1 <= n; i++)
		for (int j = i, p = 1; j <= i + ((k - 1) / 2); j++, p++)
			g[j].push_back(i + (k - p)), g[i + k - p].push_back(j);
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			ans = (ans + 1) % MOD;
			bfs(i);
		}
	cout << qpow(m, ans, MOD)  << endl;
	
	return 0;
}

