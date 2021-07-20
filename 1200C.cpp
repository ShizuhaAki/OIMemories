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
typedef pair <int, int> Edge;
#define v first
#define w second
#endif
using LL = long long;
using ULL = unsigned long long;
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-13;

signed main()
{
	ios::sync_with_stdio(false);
	LL n, m, q;
	cin >> n >> m >> q;
	LL d = __gcd(n, m);
	while (q--) {
		LL x, y, a, b;
		cin >> x >> a >> y >> b;
		a--,b--;
		a /= ((x == 1) ? n : m) / d;
		b /= ((y == 1) ? n : m) / d;
		if (a != b)puts("NO");
		else puts("YES"); 
	}
	return 0;
}

