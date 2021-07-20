#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 18;
int n, m, rk[N][N], suit[N][N]; 
vector <pair <int, int>> joker;
bool check(int x, int y) {
	int st = suit[x][y];
	set <int> srk;
	bool flg1 = true, flg2 = true;
	for (int i = x; i <= x + 3; i++) 
		for (int j = y; j <= y + 3; j++) {
			if (suit[i][j] != st) flg1 = false;
			if (srk.count(rk[i][j])) flg2 = false;
			else srk.insert(rk[i][j]);
		}
	return flg1 || flg2;
}
bool overLap(pair <int, int> a, pair <int, int> b) {
	
}
int main() {
	cin >> n >> m;
	set < pair <int, int> > cards;
	repn(i, 13) repn(j, 4) cards.insert(mp(i, j));
	repn(i, n) repn(j, m) {
		string s;
		cin >> s;
		int r, su;
		if (s[0] == 'T')  r = 10;
		else if (s[0] == 'J') {
			if (isdigit(s[1])) {
				joker.pb(mp(i, j));
				continue;
			}
			else r = 11;
		}
		else if (s[0] == 'Q') r = 12;
		else if (s[0] == 'K') r = 13;
		else r = s[0] - '0';
		rk[i][j] = r;
		if (s[1] == 'C') su = 1;
		else if (s[1] == 'D') su = 2;
		else if (s[1] == 'H') su = 3;
		else if (s[1] == 'S') su = 4;
		cards.erase(mp(r, su));
	}
	if (joker.empty()) {
		vector < pair <int, int> > ans;
		repn(i, n - 3) repn(j, m - 3) {
			if (!check(i, j)) {
				puts("No Solution.");
				return 0;
			}
			else {
				if (ans.empty()) ans.pb(mp(i, j));
				else if (!overLap)
			}
		} 
	}
	rep(i, )
	return 0;
}

