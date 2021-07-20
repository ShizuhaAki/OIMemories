#include <bits/stdc++.h>
using namespace std;
int n, m;
vector < pair <int, int> > t[10];
void prework()
{
	t[1].push_back(make_pair(-1, 0));
	t[1].push_back(make_pair( 1, 0));
	t[1].push_back(make_pair( 0, 0));
	t[1].push_back(make_pair( 0,-1));
	t[1].push_back(make_pair( 0,-2));
	t[2].push_back(make_pair(-1, 0));
	t[2].push_back(make_pair( 1, 0));
	t[2].push_back(make_pair( 0, 0));
	t[2].push_back(make_pair( 0, 1));
	t[2].push_back(make_pair( 0, 2));
	t[3].push_back(make_pair( 0, -1));
	t[3].push_back(make_pair( 0, 1));
	t[3].push_back(make_pair( 0, 0));
	t[3].push_back(make_pair( 1, 0));
	t[3].push_back(make_pair( 2, 0));
	t[4].push_back(make_pair(-1, 0));
	t[4].push_back(make_pair(-2, 0));
	t[4].push_back(make_pair( 0, 0));
	t[4].push_back(make_pair( 0, 1));
	t[4].push_back(make_pair( 0,-1));
}
int vis[15][15];
int cnt;
void dfs(int x, int y)
{
	cerr << "dfs(" << x << "," << y <<")" << endl;
	while (vis[x][y])y++;
	if (y > m)
	{
		x++;
		y = 1;
	}
	if (x > n)
	{
		return;
	}
	if (x >= n && y >= m)return; 
	bool flg = true;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (x + t[i][j].first > n || y + t[i][j].second < m || x + t[i][j].first < 1 || y + t[i][j].second < 1)
			{
				flg = false;
				break;
			} 
			if (vis[x + t[i][j].first][y + t[i][j].second])
			{
				flg = false;
				break;
			}
		}
		if (flg)
		{
			cnt++;
			for (int j = 0; j < 5; j++)
			{
				vis[x + t[i][j].first][y + t[i][j].second] = cnt;
			}
			dfs(x, y + 1);
			for (int j = 0; j < 5; j++)
			{
				vis[x + t[i][j].first][y + t[i][j].second] = 0;
			}			
			cnt--;
		}
		else
		{
			dfs(x, y + 1);
		}
	}	
}
int main()
{
	prework();
	cin >> n >> m;
	if (n < 3 || m < 3)
	{
		cout << 0 << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				cout << '.';
			cout << endl;
		}
		return 0;
	}
	else
	{
		dfs(1, 1);
		cout << cnt << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (!vis[i][j])cout.put('.');
				else cout.put(vis[i][j] + 'A');
			}
			cout << endl;
		}
	}
	return 0;
}

