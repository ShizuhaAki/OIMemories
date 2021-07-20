#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400040;
char a[MAXN];
int row[50050], col[50050]; 
int main()
{
	int T;cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		memset(a, 0, sizeof(a));
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> a[(i - 1) * m + j];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[(i - 1) * m + j] == '.')row[i]++;
		for (int j = 1; j <= m; j++)
			for (int i = 1; i <= n; i++)
				if (a[(i - 1) * m + j] == '.')col[j]++;
		int ans = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				int currans = 0;
				currans = row[i] + col[j] - ((a[(i - 1) * m + j] == '.') ? 1 : 0);
				ans = min(ans, currans);
			}
			
		cout << ans << endl;
	}
	return 0;
}

