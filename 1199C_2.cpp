#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 400040;
int n, I, a[MAXN], sz[MAXN], cnt, ans = 0x3f3f3f3f;
signed main()
{
	cin >> n >> I;
	I = (8 * I) / n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	a[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1])cnt++;
		sz[cnt]++;
	}
	int sum = sz[1], l = 1, r = 1;
	while (l <= cnt)
	{
		if (l != r && (int)log2(r - l) + 1 > I) sum -= sz[l++];
		else
		{
			ans = min(ans, n - sum);
			if (r == cnt) sum -= sz[l++];
			else sum += sz[++r];
		}
	}
	cout << ans << endl;
	return 0;
}

