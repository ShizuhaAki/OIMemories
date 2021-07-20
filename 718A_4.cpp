#include <bits/stdc++.h>
using namespace std;
char s[200010];
int n, m;
int main()
{
	scanf("%d%d%s", &n, &m, s + 1);
	s[0] = '0';
	for (int i = 0; i <= n; i++)
	{
		if (s[i] == '.')
		{
			for (int j = i + 1; j <= n; i++)
			{
				if (s[j] >= '5')
				{
					s[j] = '0';
					bool rounded = true;
					m--;
					for (int k = j - 1; k > i; k--)
					{
						if (rounded)
						{
							s[k]++;
							if (s[k] >= '5' && m)
							{
								s[k] = 0;
								m--;
								rounded = true;
							}
							else
								rounded = false;
						}
					}
					if (rounded)
					{
						s[i] = 0;
						for (int k = i - 1; k >= 0; k--)
						{
							s[k]++;
							if (s[k] <= '9')
								break;
							else
								s[k] = '0';
						}
					}
					break;
				}
			}
		}
	}
	if (s[0] != '0')
		printf("%s", s);
	else
		printf("%s", s + 1);
	return 0;
}

