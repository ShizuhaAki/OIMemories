#include <bits/stdc++.h>
using namespace std;
const int N = 200020;
int n, a[N], col[N];
vector <int> g[N];
vector <int> comp[N];
int cnt;
typedef vector <int> :: iterator IT;
void dfs(int curr)
{
	if (col[curr] >= 1)return;
	col[curr] = cnt; comp[cnt].push_back(curr);
	for (IT it = g[curr].begin(); it != g[curr].end(); it++)dfs(*it);
}
int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i], g[i].push_back(a[i]), g[a[i]].push_back(i);
	vector <int> v;
	for (int i = 1; i <= n; i++)
	{
		if (col[i] >= 1)continue;
		cnt++;
		dfs(i);
		int pos = comp[cnt][0];
		for (int j = 0; j < comp[cnt].size(); j++) pos = a[pos];
		v.push_back(pos);
	}
	int root = -1;
	for (int i = 1; i <= n; i++)
		if (i == a[i])
		{
			root = i;
			cnt--;
			break;
		}
	if (root == -1)
	{
		root = v[0];
		a[root] = root;
	}
	for (IT it = v.begin(); it != v.end(); it++)
		if (*it  != root)a[*it] = root;
	cout << cnt << endl;
	for (int i = 1; i <= n; i++)cout << a[i] << ' ';
	cout << endl;
	return 0;
}

