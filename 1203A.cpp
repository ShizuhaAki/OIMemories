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
const long double EPS = 1e-6;
int n, a[210];
int main() {
//	ios::sync_with_stdio(false);
	int Q;cin >> Q;
	while (Q--) {
		cin >> n;
		bool f1 = true, f2 = true;
		int one = -1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] == 1)one = i;
		}
		for (int i = one, j = 1; j <= n; j++) {
			int now = a[i];
			i++;
			if (i == n + 1)i = 1;
			if (a[i] == 1)break;
			if (a[i] != now + 1) {
				f1 = false;
				break;
			}
		}
		for (int i = one, j = 1; j <= n; j++) {
			int now = a[i];
			i--;
			if (i == 0)i = n;
			if (a[i] == 1)break;
			if (a[i] != now + 1) {
				f2 = false;
				break;
			}
		}
		if (!f1 && !f2)puts("NO");else puts("YES");
	}
	return 0;
}

