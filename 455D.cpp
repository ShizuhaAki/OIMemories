/*
ID: yzshang1
LANG: C++11
TASK: Serega and Fun
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
int lastans, n, m;
int BL;
const int N = 400;
deque <int> a[N];
int cnt[400][100010];
void decode(int &x) {
	x = (x + lastans - 1) % n + 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	BL = (int)sqrt(n);
	rep(i, n) {
		int x;
		cin >> x;
		a[i / BL].pb(x);
		cnt[i / BL][x]++;
	}
	int q; 
	cin >> q;
	while (q--) {
		int op, l, r; 
		cin >> op >> l >> r; 
		decode(l); decode(r); 
	//	cerr << "Q " << l << ' ' << r << endl;
		if (l > r) swap(l, r);
		l--;
		int bl = l / BL, br = r / BL;
		if (op == 2) {
			int k;
			cin >> k;
			decode(k);
	//		cerr << "V " << k << endl;
			int ans = 0;
			if (bl == br) {	//in the same block, brute force
				for (int i = l % BL; i < r % BL; i++) 
					ans += (a[bl][i] == k);
			}
			else { //not in the same block
				for (int i = bl + 1; i < br; i++) ans += cnt[i][k];
				for (int i = l % BL; i < (int)a[bl].size(); i++) ans += a[bl][i] == k;
				for (int i = 0; i < r % BL; i++) ans += a[br][i] == k;
			}
			lastans = ans;
	//		cerr << "ANSWER:";
			cout << ans << endl;
		}
		else {
			if (bl == br) {	//in the same block
				int x = a[bl][r % BL - 1];
				a[bl].erase(a[bl].begin() + r % BL - 1);
				a[bl].insert(a[bl].begin() + l % BL, x);
			}
			else {
				for (int i = bl; i < br; ) {	
				//deal with the fully covered blocks
					int x = a[i].back();
					a[i].pop_back();
					cnt[i][x]--;
					i++;
					a[i].push_front(x);
					cnt[i][x]++;
				} 
				//deal with the last block
				int x = a[br][r % BL];
				a[br].erase(a[br].begin() + r % BL);
				cnt[br][x]--;
				a[bl].insert(a[bl].begin() + l % BL, x);
				cnt[bl][x]++;
	//			rep(i, n / BL + 1) {
	//				rep(j, a[i].size()) cerr << a[i][j] << ' ';
	//				cerr << endl;
	//			}
			}
		}
	}
	return 0;
}

