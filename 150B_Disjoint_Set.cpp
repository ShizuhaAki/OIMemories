#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2020;
int fa[MAXN];
void make_set(int n)
{
	for (int i = 1; i <= n; i++)
		fa[i] = i;
}
int find(int x)
{
	return (x == fa[x]) ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	int xx = find(x), yy = find(y);
	fa[yy] = xx;
}
int n, m, k;
const int MOD = 1000000007;
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
	make_set(n);
	for (int i = 1; i + k - 1 <= n; i++)
		for (int j = i, p = 1; j <= i + ((k - 1) / 2); j++, p++)
			merge(j, i + k - p);
	int ans = 0;
//	for (int i = 1; i <= n; i++)cerr << fa[i] << ' ';cerr << endl;
	for (int i = 1; i <= n; i++)
		if (fa[i] == i)
			ans++;
	cout << qpow(m, ans, MOD) << endl; 
	return 0;
}

