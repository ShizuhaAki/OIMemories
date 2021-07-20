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
const int BL = 5;
const int N = 100010;
int size = 0;
vector <int> a;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	while (n--) {
		string op; cin >> op;
		if (op == "add") {
			int x;
			cin >> x;
			a.insert(lower_bound(a.begin(), a.end(), x), x);
		}
		else if (op == "del") {
			int x;
			cin >> x;
			a.erase(lower_bound(a.begin(), a.end(), x));
		}
		else if (op == "sum") {
			long long ans = 0;
			for (int i = 2; i < (int)a.size(); i += 5) ans += a[i];
			cout << ans << endl;
		}
	}
	return 0;
}

