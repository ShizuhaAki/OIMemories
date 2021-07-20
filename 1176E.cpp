#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200020;
vector <int> g[MAXN];
int n, m;
int d[MAXN];
inline void bfs(int s)
{
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (auto nxt:g[curr])
		{
			if (d[nxt] == 0x3F3F3F3F)d[nxt] = d[curr] + 1,q.push(nxt);
		}
		
	}
}
inline void output(vector <int> vec)
{
	cout << vec.size() << endl;
	for (auto it = vec.begin(); it != vec.end(); it++)cout << *it << " ";
	cout << endl;
}
int main()
{
	int T;
	cin.tie(0);ios::sync_with_stdio(0);
	cin >> T;
	while (T--)
	{

		
		cin >> n >> m;
		for (int i = 1; i <= n; i++)g[i].clear();
		for (int i = 1; i <= n; i++)d[i] = 0x3f3f3f3f;
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		bfs(1);
		vector <int> ans[2];
		for (int i = 1; i <= n; i++)ans[d[i] % 2].push_back(i);
		if (ans[0].size() < ans[1].size())output(ans[0]);
		else output(ans[1]); 
	}
}
