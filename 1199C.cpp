#include <bits/stdc++.h>
using namespace std;

long long n, I;
const long long MAXN = 400010;
long long mxsz;
long long a[MAXN], b[MAXN], cnt, sz[MAXN], cl[MAXN], cr[MAXN], dsz;
void prework()
{
	for (long long l = 1; l <= cnt; l++)
		cl[l] = cl[l - 1] + sz[l - 1];
	for (long long r = cnt; r >= 1; r--)
		cr[r] = cr[r + 1] + sz[r + 1]; 
	return;
}
long long prefix[MAXN];
bool check(long long l, long long mid)
{
	return prefix[mid] - prefix[l - 1] <= dsz;
}
signed main()
{
	cin >> n >> I;
	for (long long i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	dsz = 1;
	for (long long i = 1; i <= (8 * I / n); i++)
	{
		if (dsz >= n)break;
		dsz *= 2;
	}
	for (long long i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1])
			cnt++;
	//	b[i] = cnt;
		sz[cnt]++;
		mxsz = max(mxsz, sz[cnt]);
	}
	if (8 * I / n == 0)
	{
		cout << cnt - mxsz << endl;
		return 0;
	}
	for (long long i = 1; i <= cnt; i++)prefix[i]  = prefix[i - 1] + sz[i]; 
	prework();
	long long ans = (1LL << 60LL);
	if (cnt <= dsz)
	{
		cout << 0 << endl;
		return 0;
	}
	for (long long l = 1; l <= cnt; l++)
	{
		long long L = l, R = cnt;
		while (L < R)
		{
			long long mid = (L + R) >> 1;
			if (check(l, mid))
				L = mid + 1;
			else 
				R = mid; 
		}
		ans = min(ans, cl[L] + cr[R]);
	}
	cout << n - ans << endl;
	return 0;
}

