#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int INF = 0x3F3F3F3F;
int dp[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	int n, t; string s;
	cin >> n >> t >> s;
	dp[n - 1] = INF;
	for (int i = n - 2; s[i + 1] != '.'; i--)
	{
		if (s[i + 1] == '4')
			dp[i] = dp[i + 1] + 1;
		else
		{
			if (s[i + 1] >= '5')
				dp[i] = 1;
			else
				dp[i] = INF;
		}
		if (dp[i] <= t)
			res = t;
	}
	if (res == -1)
	{
		cout << s << endl;
		return 0;
	}
	else
	{
		if (s[res] == '.')
			res--;
		int len = res;
		while (res && s[res] == '9')
		{
			s[res] = 0;
			res--;
		}
		if (res == -1)cout << 1;
		else s[res]++;
		cout << s.substr(0, len + 1) << endl;
	}
	return 0;
}

