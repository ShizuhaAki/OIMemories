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
const int N = 100010;
int a[N], n;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n)cin >> a[i];
	LL ans = 0;
	int pos = 0, neg = 0, zero = 0;
	rep(i, n) {
		if (a[i] == 0) {
			zero++;
			continue;
		}
		int diffp = abs(a[i] - 1);
		int diffn = abs(a[i] - (-1));
		if (diffp <= diffn)pos++, ans += diffp;
		else neg++, ans += diffn;
	}
	if (neg % 2 == 1) {
		if (zero) {
			zero--;
			ans++;
		}
		else ans += 2;
	}
	ans += zero;
	cout << ans << endl;
	return 0;
}

