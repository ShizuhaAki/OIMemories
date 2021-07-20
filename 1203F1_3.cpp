#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <list>
#include <cassert>
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
#if __cplusplus >= 201103L
using LL = long long;
using ULL = unsigned long long;
#else
#define LL long long
#define ULL unsigned long long
#endif
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
typedef pair <int, int> Event;
#define fi first
#define se second
vector <Event> pos, neg;
int main() {
	ios::sync_with_stdio(false);
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		if (b >= 0)pos.pb(mp(a, b));
		else neg.pb(mp(max(a, -b), b));
	}
	sort(pos.begin(), pos.end());
	for (auto i:pos) {
		if (r < i.fi) {
			puts("NO");
			return 0;
		}
		else r += i.se;
	}
	sort(neg.begin(), neg.end(), [](Event c, Event d) {
		return (c.fi + c.se) > (d.fi + d.se);
	});
//	cerr << "qwq" << endl;
	for (auto i:neg) {
		if (r < i.fi) {
			puts("NO");
			return 0;
		}
		else r += i.se;
	}
	puts("YES");
	return 0;
}

