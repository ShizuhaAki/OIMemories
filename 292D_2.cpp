//based on solution by [user:tourist]
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10100;
int fa[MAXN], a[MAXN], b[MAXN], r[MAXN], n, m;
bool imp[MAXN];
int find(int x){return (x == fa[x]) ? x : fa[x] = find(fa[x]);}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i];
		imp[i] = false;
	}
	int k = 0;
	for (int i = 1; i <= n; i++)fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int x = find(a[i]), y = find(b[i]);
		if (x != y)
		{
			r[k++] = i;
			imp[i] = true;
			fa[x] = y;
		}
	}
	for (int i = 1; i <= n; i++)fa[i] = i;
	for (int i = m; i >= 1; i--)
	{
		int x = find(a[i]), y = find(b[i]);
		if (x != y)
		{
			if (!imp[i])
			{
				r[k++] = i;
				imp[i] = true;
			}
			fa[x] = y;
		}
	 } 
	int q;
	cin >> q;
	while (q--)
	{
		int L, R;
		cin >> L >> R;
		for (int i = 1; i <= n; i++)fa[i] = i;
		for (int i = 0; i < k; i++)
			if (r[i] < L or r[i] > R)
			{
				int x = find(a[r[i]]);
				int y = find(b[r[i]]);
				if (x != y)fa[x] = y;
			 } 
		int res = 0;
		for (int i = 1; i <= n; i++)if (fa[i] == i)res++;
		cout << res << endl; 
	}
	return 0;
}

