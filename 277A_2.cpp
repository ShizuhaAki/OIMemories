#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int fa[MAXN];
void make_set(int n)
{
	for (int i = 1; i <= n; i++)fa[i] =  i;
}
int find(int x)
{
	return (x == fa[x]) ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	int xx = find(x), yy = find(y);
	fa[xx] = yy;
}
bool a[MAXN][MAXN];
int main()
{
	int n, m;
	cin >> n >> m;
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		if (k)flag = false;
		for (int j = 1; j <= k; j++)
		{
			int x;
			cin >> x;
			a[i][x] = true;
		}
	}
	if (flag)
	{
		cout << n << endl;
		return 0;
	}
	make_set(n);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			bool found = false;
			for (int k = 1; k <= m; k++)if (a[i][k] && a[j][k])found = true;
			if (found)merge(i, j);
		}
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (find(i) == i)res++;
	cout << res - 1 << endl; 
	return 0;
}

