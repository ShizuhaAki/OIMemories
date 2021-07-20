#include <iostream>
#include <cstring>
using namespace std;
int col[2010][2010], now;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		memset(col, 0, sizeof(col));
		now = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
			//	cerr << i << ' ' << j << endl;
				if (col[i][j])continue;
				now++;
				col[i][j] = now;
				int x = i, y = j, dx = 1, dy = 1;
				int cnt = 0;
				while (cnt != 2)
				{
					cnt = 0;
			//		cerr << x << " " << y << endl;
					x = x + dx, y = y + dy;
					col[x][y] = now;
					if (x == 1 || x == n)
					{
						cnt++;
						dx = -dx;
					}
					if (y == 1 || y == m)
					{
						cnt++;
						dy = -dy;
					}
				}
			}
		cout << now << endl;
	}
}
