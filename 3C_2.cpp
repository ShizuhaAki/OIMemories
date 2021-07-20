#include <bits/stdc++.h>
using namespace std;
vector <int> victory;
string a[3];
#define LSH(x) (1 << (x))
#define IT(__type) vector <__type> :: iterator
void init()
{
	for (int i = 0; i < 3; i++) victory.push_back(LSH(i * 3) + LSH(i * 3 + 1) + LSH(i * 3 + 2));
	for (int i = 0; i < 3; i++) victory.push_back(LSH(i) + LSH(i + 3) + LSH(i + 6));
	victory.push_back(LSH(0) + LSH(4) + LSH(8));
	victory.push_back(LSH(2) + LSH(4) + LSH(6));
}
bool win(char who)
{
	int cnt = 0;
	int s = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[i][j] == who)
				s |= LSH(i * 3 + j);
	for (IT(int) it = victory.begin(); it != victory.end(); it++)
		if ((s & (*it)) == (*it))cnt++;
	return cnt;
}
int Count(char ch)
{
	int res = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[i][j] == ch)
				res++;
	return res; 
}
void solve()
{
	int ca = Count('X'), cb = Count('0');
	if (ca < cb || ca > cb + 1)puts("illegal"), exit(0);
	int now = (ca == cb) ? 0 : 1;
	int wina = win('X'), winb = win('0');
	if ((now == 0 && wina == 1) || (now == 1 && winb == 1))puts("illegal"), exit(0);
	if (wina == 1)puts("the first player won"), exit(0);
	if (winb == 1)puts("the second player won"), exit(0);
	if (ca + cb == 9)puts("draw"), exit(0);
	if (now == 0)puts("first"), exit(0);
	puts("second"), exit(0);
}
int main()
{
	init();
	for (int i = 0; i < 3; i++)cin >> a[i];
	solve();
	return 0;
}

