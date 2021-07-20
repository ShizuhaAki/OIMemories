#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
int n, m, ch[13][13], a[13][13], ans;
const int w[4][3][3] = 
{
	{
		{1,1,1},
		{0,1,0},
		{0,1,0}
	},
	{
		{0,1,0},
		{0,1,0},
		{1,1,1}
	},
	{
		{1,0,0},
		{1,1,1},
		{1,0,0}
	},
	{
		{0,0,1},
		{1,1,1},
		{0,0,1}	
	}
};
int dbg;
inline bool check(int x, int y, int i){if (y + 2 >= m or x + 2 >= n)return false;rep(u,3)rep(v,3)if(w[i][u][v])if(a[x + u][y + v])return 0;return 1;}
void dfs(int x, int y, int cnt, int __free)
{
	dbg++;
	if (__free <= (ans - cnt) * 6.69)return;
	if (y + 2 >= m)
	{
		dfs(x + 1, 0, cnt, __free);
		return;
	}
	if (x + 2 >= n)
	{
		if (cnt > ans)
		{
			ans = cnt;
			memcpy(ch, a, sizeof a);
		}
		return;
	}
	rep(i,4)if (check(x, y, i))
	{
		cnt++;
		rep(u,3)rep(v,3)if (w[i][u][v])a[x + u][y + v] = cnt;
		dfs(x, y + 1, cnt, __free - 5 - !a[x][y]);
		cnt--;
		rep(u,3)rep(v,3)if (w[i][u][v])a[x + u][y + v] = 0; 
	}
	dfs(x, y + 1, cnt, __free - !a[x][y]);
}
void print()
{
	cout << ans << endl;
	rep(i, n){
		rep(j, m)cout.put(ch[i][j] ? 'A' + ch[i][j] - 1:'.');
		cout << endl; 
	}
	exit(0);
}
int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	cin >> n >> m;
//	if (n < m)swap(n, m);
	if (n < 3 or m < 3)print();
	dfs(0, 0, 0, n * m);
	cerr << "dfs called " << dbg << " times." << endl;
	print();
	return 0;
}

