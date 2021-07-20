#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
int cnts[MAXN], cntp[MAXN], cntt[MAXN];
int main()
{
	int T;cin >> T;
	while (T--)
	{
		string s, t, p;
		cin >> s >> t >> p;
		memset(cnts, 0, sizeof(cnts));
		memset(cntp, 0, sizeof(cntp));
		memset(cntt, 0, sizeof(cntt));
		for (auto c:s)cnts[c]++;
		for (auto c:p)cntp[c]++;
		for (auto c:t)cntt[c]++;
		bool flg = true;
		int prev = 0;
		for (int i = 0; i < s.length(); i++)
		{
			bool found = false;
			for (int j = prev; j < t.length(); j++)
			{
				if (t[j] == s[i])
				{
					found = true;
					prev = j + 1;
					break;
				}
			}
			if (!found)
			{
				flg = false;
				break;
			}
		}
		if (!flg)
		{
			puts("NO");
			continue;
		}
		flg = false;
		for (char i = 'a'; i <= 'z'; i++)
		{
			if (cnts[i] + cntp[i] < cntt[i])
			{
				puts("NO");
				flg = true;
				break;
			}
		}
		if (!flg)puts("YES");
	}
	return 0;
}

