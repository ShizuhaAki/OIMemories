#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500050;
int n, m;
int ans[MAXN];
int color[MAXN];
int c;
vector <int> g[MAXN];
int dfs(int u)
{
	int res = 1;
	if (color[u])return 0;
	color[u] = c;
	for (vector <int> :: iterator it = g[u].begin(); it != g[u].end(); it++)
		res += dfs(*it); 
	return res;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int k; cin >> k;
		if (k == 0)continue;
		if (k == 1)
		{
			int tmp;
			cin >> tmp;
			continue;
		}
		int prev, curr;
		cin >> prev;
		for (int j = 2; j <= k; j++)
		{
			cin >> curr;
	//		cerr << curr << ' ' << prev << endl;
			g[curr].push_back(prev);
			g[prev].push_back(curr);
			prev = curr;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!color[i])
		{
			c++;
			ans[c] = dfs(i);
		}
		cout << ans[color[i]] << ' ';
	}
	cout << endl;
	
	return 0;
}

