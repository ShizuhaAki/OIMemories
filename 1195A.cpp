#include <bits/stdc++.h>
using namespace std;
int cnt[1100];
int main()
{
	int n, k;
	cin >> n >> k; 
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}
	int remain = ceil(n / 2.0), ans = 0;
	for (int i = 1; i <= k; i++)
		if (cnt[i] % 2 == 0)
			if (remain - cnt[i] / 2 >= 0)remain -= cnt[i] / 2, cnt[i] = 0;	
	for (int i = 1; i <= k; i++)
		if (cnt[i] > 1)
			if (remain - cnt[i] / 2 >= 0)remain -= cnt[i] / 2, cnt[i] = 1;
	for (int i = 1; i <= k; i++)
		if (cnt[i])
			if (remain - 1 >= 0)remain -= 1, cnt[i] = 0;
//	for (int i = 1; i <= k; i++)cerr << cnt[i] << ' ';
//	cerr << endl;
	for (int i = 1; i <= k; i++)ans += cnt[i];
	cout << n - ans << endl;
	return 0;
}

