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
const int INF = 100000;
const long double EPS = 1e5;

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int maxx = INF, minx = -INF, maxy = INF, miny = -INF;
		while (n--) {
			int x, y, f1, f2, f3, f4;
			cin >> x >> y >> f1 >> f2 >> f3 >> f4;
			if (!f1) minx = max(minx, x);
			if (!f2) maxy = min(maxy, y);
			if (!f3) maxx = min(maxx, x);
			if (!f4) miny = max(miny, y);
		}
		if (maxx < minx || maxy < miny) {
			cout << 0 << endl;
		}
		else cout << 1 << " " << maxx << " " << maxy << endl;
	} 
	return 0;
}

