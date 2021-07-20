#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#define pb push_back
#define mp make_pair
#ifdef GRAPH
typedef pair <long long, long long> Edge;
#define v first
#define w second
#endif
using LL = long long;
using ULL = unsigned long long;
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (long long (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)

const long long INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const long long MAXN = 40040;
long long n;
signed main() {
	ios::sync_with_stdio(false);
	cin >> n;
	long long d = 0;
	for (long long i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		d = __gcd(x, d);
	}
	long long ans = 0;
	for (long long i = 1; i * i <= d; i++) {
		if (d % i == 0) {
			if (d / i != i)ans += 2;
			else ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

