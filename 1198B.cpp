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
const int EPS = 1e-6;
const int MAXN = 200020;
int a[MAXN], n, Q;
struct chtholly{
	int t, p, x;
	chtholly(int t, int p, int x):t(t), p(p), x(x) {}
};
vector <chtholly> q;
bool updated[MAXN];
int ans[MAXN];
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n)cin >> a[i + 1];
	cin >> Q;
	rep(i, Q) {
		int type, p, x;
		cin >> type;
		if (type == 1)cin >> p >> x;
		else {
			p = -1;
			cin >> x;
		}
		q.pb(chtholly(type, p, x));
	}
	int Max = -INF;
	memset(updated, 0, sizeof(updated));
	for (int i = Q - 1; i >= 0; i--) {
		if (q[i].t == 2)Max = max(Max, q[i].x);
		else {
			if (updated[q[i].p])continue;
			updated[q[i].p] = true;
			ans[q[i].p] = max(q[i].x, Max);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (updated[i])cout << ans[i] << ' ';
		else cout << max(Max, a[i]) << ' ';
	}
	return 0;
}

