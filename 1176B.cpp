#include <bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	int T;cin >> T;
	while (T--)
	{
		int n, unpaired = 0, ans = 0, one = 0, two = 0;
		cin >> n;
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			if (x % 3 == 0) ans++;
			if (x % 3 == 1) one++;
			if (x % 3 == 2) two++;
		}
		//pair one with two
		if (one < two)
		{
			ans += one;
			two -= one;
			one = 0;
		}
		else if (one > two)
		{
			ans += two;
			one -= two;
			two = 0;
		}
		else
		{
			ans += one;
			one = two = 0;
		}
		//pair one with itself
		if (one > 0)
		{
			ans += one / 3;
		}
		//pair two with itself
		if (two > 0)
		{
			ans += two / 3;
		}
		cout << ans << endl;
	}
	return 0;
}

