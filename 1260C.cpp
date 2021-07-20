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

int main() {
	int T; cin >> T;
	while (T--) {
		LL r, b, k;
		cin >> r >> b >> k;		LL _max = max(r, b), _min = min(r, b), d = __gcd(r, b);
		if ((k - 1) * _min > _max) cout << "obey" << endl;
		else {
			bool rebel = false;
			for (LL i = 0; i < (r * b / (d)); i += _max) {
				LL beg, end;
				if (i != 0 && i % _min == 0) beg = i; else beg = (i / _min + 1) * _min;
				if ((i + _max) % _min == 0) end = i + _max; else end = (i + _max) / _min * _min;
				if (end == r * b / d) end--;
		//		cerr << beg << ' ' << end << endl;
				if ((end - beg) / _min >= k - 1) {
					rebel = true;
					break;
				}
			}
			if (rebel) cout << "rebel" << endl; else cout << "obey" << endl;
		} 
	}
	return 0;
}

