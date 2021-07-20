#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T; cin >> T;
	while (T--)
	{
		long long n, k;
		cin >> n >> k;
		int ans = 0;
		while (n)
		{
			if (n < k)
			{
				ans += n;
				break;
			}
			long long remain = n % k;
			ans += remain;
			n -= remain;
			while (!(n % k))
				n /= k, ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

