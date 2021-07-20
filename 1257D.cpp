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
const int N = 200020;
int a[N];
struct Hero {
	int p, s;
	Hero(int p = 0, int s = 0) :p(p), s(s) {}
	bool operator < (const Hero b) const  {
		if (p != b.p) return p > b.p;
		else return s > b.s;
	}
}hero[N];
int n, m;
bool check(int x, int i) {
	return hero[x].p >= a[i];
}
int main() {
	int T; cin >> T;
	while (T--) {
		int maxP = -1, maxA = -1;
		cin >> n; repn(i, n) cin >> a[i], maxA = max(maxA, a[i]);
		cin >> m; repn(i, m) cin >> hero[i].p >> hero[i].s, maxP = max(maxP, hero[i].p);
		if (maxP < maxA) {
			cout << -1 << endl;
			continue;
		}
		sort(hero + 1, hero + m + 1);
		int nowHero = 0;
		int p, s;
		int ans = 0;
		int lastHero = -1;
		repn(i, n) {
			//binary search for a hero that is suitable for the monster
			int L = 1, R = m;
			while (L <= R) {
				int mid = (L + R) >> 1;
				if (check(mid, i)) L = mid + 1;
				else R = mid - 1;
			}
			//cerr << "Picked hero " << R << " for " << i << endl;
			if (lastHero != R) s = hero[R].s, ans++;// cerr << lastHero << ' ' << R << endl;;
			lastHero = R;
			if (!s && hero[R + 1].p >= a[i]) s = hero[R + 1].s;
			else if (!s && hero[R + 1].p < a[i]) s = hero[R].s, ans++;  
			s--;
		}
		cout << ans << endl;
	}
	return 0;
}

