#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010, INF = 0x3F3F3F3F;
int f[MAXN];
char s[MAXN];
int main()
{
	int n, m;
	scanf("%d%d%s", &n, &m, s + 1);
	memset(f, INF, sizeof(f));
	int pos, len = 0;
	for (int i = n; i >= 2; i--)
	{
		if (s[i] >= '5' && s[i] <= '9')
			f[i - 1] = 1;
		else if (s[i] == '4')
			f[i - 1] = f[i] + 1;
		else if (s[i] == '.')
		{
			pos = i;
			break;
		}
//		else assert(!"Unknown symbol found : symbol s[i] = " + s[i]);
	}
	if (f[pos] <= m)
	{
		len = pos;
		s[pos - 1]++; 
		while (s[pos - 1] > '9')
		{
			pos--;
			s[pos] = '0';
			if (pos - 1 >= 1)
				s[pos - 1]++;
			else
				break;
		}
		if (pos == 1)
			putchar('1');
		for (int i = 1; i < len; i++)putchar(s[i]);
	} 
	else
	{
		while (pos <= n && f[pos] > m)
			pos++;
		if (pos >= n + 1)
			for (int i = 1; i <= n; i++)
				putchar(s[i]);
		else
		{
			s[pos]++;
			len = pos;
			for (int i = 1; i <= len; i++)putchar(s[i]);
		}
	}
	return 0;
}

