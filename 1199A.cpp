#include <bits/stdc++.h>
using namespace std;
int n, x, y;
const int MAXN = 100010;
int a[MAXN];
int main()
{
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		bool flg = true;
		for (int j = max(1, i - x); j <= min(n, i + y); j++)
			if (a[j] < a[i])
			{
				flg = false;
				break;
			}
		if (flg)
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}

