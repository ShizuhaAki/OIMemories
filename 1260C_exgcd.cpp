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
//solve single case
bool solve(LL r, LL b, LL k) {	
	if (r > b) swap(r, b);
	int d = __gcd(r, b); r /= d; b /= d;
	if ((k - 1) * r + 1 >= b) return true;
	else return false;
}
int main() {
	int T; cin >> T;
	while (T--) {
		LL r, b, k;
		cin >> r >> b >> k;
		if (solve(r, b, k)) cout << "obey" << endl; 
		else cout << "rebel" << endl;
	}
	return 0;
}

