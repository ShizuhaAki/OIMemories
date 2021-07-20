#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int a[MAXN][2];
long long f[MAXN][2];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i][0];
	for (int j = 1; j <= n; j++)cin >> a[j][1];
	long long ans = 0;
	f[1][0] = a[1][0], f[1][1] = a[1][1];
	for (int i = 1; i <= n - 1; i++)
	{
		f[i + 1][0] = max(f[i][0], f[i][1] + a[i + 1][0]);
		f[i + 1][1] = max(f[i][1], f[i][0] + a[i + 1][1]);
	}
	cout << max(f[n][0], f[n][1]) << endl;
	return 0;
}

