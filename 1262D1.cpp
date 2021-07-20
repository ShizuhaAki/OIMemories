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
const int N = 120;
int n;
int a[N], b[N];
vector <int> c;
map <int, int> cnt;
int main() {
	cin >> n;// a.resize(n + 1);
	repn(i, n) cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1, [](int x, int y) {
		return x > y;
	});
	int q; cin >> q;
	while (q--) {
		int k, pos;
		cin >> k >> pos;
		cnt.clear(); c.clear(); c.pb(-1);
		repn(i, k) cnt[b[i]]++;
		repn(i, n) {
			if (cnt[a[i]]) {
				cnt[a[i]]--;
				c.pb(a[i]);
			}
		}
		cout << c[pos] << endl;
	}
	return 0;
}

