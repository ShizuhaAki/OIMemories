
// Problem : C. NEKO's Maze Game
// Contest : Codeforces Round #614 (Div. 2)
// URL : https://codeforces.com/contest/1293/problem/C
// Memory Limit : 256.000000 MB 
// Time Limit : 1500.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = s; (i) <= (int)t; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c = getchar();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
bool marked[3][100010];
int main() {
	int n = qread(), m = qread();
	int cnt = 0;
	rep(i, m) {
		int x = qread(), y = qread();
		marked[x][y] ^= 1;
		range(i, max(y - 1, 1), min(y + 1, n)) 
			if (marked[x][y] && marked[3 - x][i]) cnt++; 
			else if (marked[x][y] == 0) {
				if (marked[3 - x][i]) cnt--;
			}
		cout << (cnt <= 0 ? "Yes" : "No") << endl;
	}
	return 0;
}
