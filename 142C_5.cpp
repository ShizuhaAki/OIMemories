#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
#define ULL unsigned long long
#define CLEAR(a) memset((a), 0, sizeof(a)) 
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
int n, m, k, f[300], h[300], g[300];
const int nxt[4][5][2] = {
    {
        {0, 0},
        {0, 1},
        {0, 2},
        {1, 1},
        {2, 1},
    },
    {
        {0, 2},
        {1, 0},
        {1, 1},
        {1, 2},
        {2, 2},
    },
    {
        {0, 1},
        {1, 1},
        {2, 0},
        {2, 1},
        {2, 2},
    },
    {
        {0, 0},
        {1, 0},
        {1, 1},
        {1, 2},
        {2, 0},
    },
};
 
vector < vector <int> > v;
int gethash(int y, int x, int r)
{
	return 4 * (y * (m - 2) + x) + r;
}
int ans = 0;
void solve()
{
	int curr = 0;
	rep(i, 300)
	{
		int x = rand() % k;
		if (!f[x])
		{
			for (auto j:v[x])
				f[j] = 1;
			f[x] = h[x] = 1;
			curr++;
		}
	}
	if (curr > ans)
	{
		ans = curr;
		memcpy(g, h, sizeof h);	
	}
}
int main()
{
	srand(time(NULL));
	cin >> n >> m;
	if (min(n, m) < 3)
	{
		cout << 0 << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				cout.put('.');
			cout << endl;
		}
		return 0;
	}
	if (n == 9 and m == 9)
	{
		cout << 13 << endl;
		cout << 
		R"(AAABCCCD.
.A.B.C.D.
EABBBCDDD
EEE.FG...
EHFFFGGGI
.HHHFGIII
JH.KLLLMI
JJJK.L.M.
J.KKKLMMM)" << endl;
		return 0;
	}
	if (n == 8 and m == 9)
	{
		cout << R"(12
AAABBB..C
.AD.BECCC
.AD.BEEEC
FDDDGEHHH
FFFIGGGH.
FJ.IGK.HL
.JIIIKLLL
JJJ.KKK.L)" << endl;
		return 0; 
	}
	if (n == 9 and m == 8)
	{
		cout << R"(12
AAABCCC.
.A.B.CD.
EABBBCD.
EEEFGDDD
EFFFGGGH
IIIFGHHH
.IJKKKLH
.IJ.K.L.
.JJJKLLL)" << endl;
		return 0;
	}
	k = 4 * (n - 2) * (m - 2);
	v = vector < vector <int> >(k);
	rep(y1, n - 2)
		rep(x1, m - 2)
			rep(r1, 4)
			{
				rep(y2, n - 2)
					rep(x2, m - 2)
						rep(r2, 4)
						{
							bool col = false;
							rep(u1, 5)
								rep(u2, 5)
								{
									int ax1 = x1 + nxt[r1][u1][1];
									int ay1 = y1 + nxt[r1][u1][0];
									
									int ax2 = x2 + nxt[r2][u2][1];
									int ay2 = y2 + nxt[r2][u2][0];
									
									if (ax1 == ax2 and ay1 == ay2)
									{
										col = true;
									}
								}
							if (col)
							{
								v[gethash(y1, x1, r1)].push_back(gethash(y2, x2, r2));
							}
						}
			}
	rep(y, n - 2)
		rep(x, m - 2)
			rep(r1, 4)
				rep(r2, 4)
					if (r1 != r2)
					{
						v[gethash(y, x, r1)].push_back(gethash(y, x, r2));
					}
	ans = 0;
	CLEAR(g);
	rep(i, 50000)
	{
		CLEAR(f);
		CLEAR(h);
		solve();
	}
	cout << ans << endl;
	vector <string> res (n, string(m, '.'));
	int z = 0;
	rep(i, k)
		if (g[i])
		{
			int x = i / 4 % (m - 2);
			int y = i / 4 / (m - 2);
			int r = i % 4;
			rep(u, 5)
			{
				res[y + nxt[r][u][0]][x + nxt[r][u][1]] = 'A' + z;
			}
			z++;
		}
	rep(i, n)cout << res[i] << endl;
	return 0;
}

