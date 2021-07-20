#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
#define ULL unsigned long long
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
const int MAXN = 30;
template <class T1, class T2, class T3>
int n, m;
struct Triple
{
	T1 a;
	T2 b;
	T3 c;
	Triple(T1 a, T2 b, T3 c):a(a), b(b), c(c){}
};
Triple make_triple(T1 a, T2 b, T3 c)
{
	Triple now;
	now.a = a;
	now.b = b;
	now.c = c;
	return now;
}
map <Triple, int> table;
const int d[4][5][2] = 
{
	{}
};
void clear_excess(LL mask, int b)
{
	for (; b <= 64; b++)
		if (mask & lshll(b))
			mask ^= lshll(b);
}
LL find(int x, int y, int nx, int ny)
{
	return lshll((x + nx) * m + (y + ny));
}
LL dp(int x, int y, LL mask)
{
	clear_excess(mask, 3 * n);
	
}
int main()
{
	cin >> n >> m;
	return 0;
}

