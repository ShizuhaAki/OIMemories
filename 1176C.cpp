#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500500;
int a[MAXN];
int n;
int ans;
int cnt[7];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == 4)x = 1;
		if (x == 8)x = 2;
		if (x == 15)x = 3;
		if (x == 16)x = 4;
		if (x == 23)x = 5;
		if (x == 42)x = 6;
		a[i] = x;
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 1)
			cnt[1]++;
		else
		{
			if (cnt[a[i] - 1])
			{
				cnt[a[i]]++;
				cnt[a[i] - 1]--;
			}
		}
	}
	cout << n - 6 * cnt[6] << endl;
	return 0;
}

