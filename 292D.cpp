#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510;
const int MAXM = 10010; 
struct Disjoint_Set
{
	int fa[MAXN];
	int find(int x)
	{
		if (fa[x] == x)return x;
		return fa[x] = find(fa[x]);
	}
	void merge(int x, int y)
	{
		int xx = find(x), yy = find(y);
		if (xx > yy) swap(xx, yy);
		fa[yy] = xx;
	}
	Disjoint_Set(int n)
	{
		for (int i = 1; i <= n; i++)
			fa[i] = i;
	}
};
vector <Disjoint_Set> l, r;
int n, m;
pair <int, int> input[MAXM];
int main()
{
	cin >> n >> m;
	l.push_back(Disjoint_Set(n)), r.push_back(Disjoint_Set(n));
	for (int i = 1; i <= m; i++)
		cin >> input[i].first >> input[i].second;
	for (int i = 1, j = m; i <= m && j >= 1; i++, j--)
	{
		Disjoint_Set nowl = l.back(), nowr = r.back();
		nowl.merge(input[i].first, input[i].second);
		nowr.merge(input[j].first, input[j].second);
		l.push_back(nowl);
		r.push_back(nowr);
	}
	int q;
	cin >> q;
	while (q--)
	{
		int lbound, rbound;
		cin >> lbound >> rbound;
		Disjoint_Set lset = l[lbound - 1], rset = r[m - rbound];
		Disjoint_Set ans = lset;
		for (int i = 1; i <= n; i++)
			ans.merge(ans.fa[i], rset.fa[i]);
		int res = 0;
		for (int i = 1; i <= n; i++)
			if (ans.fa[i] == i)
				res++; 
		cout << res << endl;
	}
	return 0;
}

