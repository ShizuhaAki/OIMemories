#include <cstdio>
using namespace std;
const int MAXN = 200020;
char s[MAXN];
int main()
{
	int n, m;
	scanf("%d%d%s", &n, &m, s + 1);
	int pos = 1;
	while (s[pos] != '.')pos++;
	while (pos <= n && s[pos] < '5')pos++;
	if (pos >= n + 1)
	{
		printf("%s", s + 1);
		return 0;
	}
//	fprintf(stderr, "%d", pos);
	pos--;
	int len = 0;
	while (m)
	{
		if (s[pos] != '.')
			s[pos]++;
		else
		{
			pos--;
			len = pos;
			while (pos >= 1 && s[pos] == '9')
			{
				s[pos] = '0';
				pos--;
			}
			if (pos == 0)
				putchar('1');
			else
				s[pos]++;
			break;
		}
		if (s[pos] < '5')
		{
			len = pos;
			break;
		}
		else
		{
			len = pos; 
			pos--;
		}
		m--;
	}
	for (int i = 1; i <= len; i++)
		putchar(s[i]); 
	return 0;
}
