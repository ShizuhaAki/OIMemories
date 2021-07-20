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
int n, m, k;
template <int MAXN> struct DSU {
	int fa[MAXN];
	void make_set(int n) {
		for (int i = 1; i <= n; i++)fa[i] = i;
	}
	int find(int x) {
		return (x == fa[x]) ? x : fa[x] = find(fa[x]);
	}
	void merge(int x, int y) {
		int xx = find(x), yy = find(y);
		if (xx != yy)fa[yy] = xx;
	}
	int count(int n) {
		int res = 0;
		for (int i = 1; i <= n; i++)
			if (fa[i] == i)res++;
		return res;
	}
};
DSU < 2019 > dsu;
const int MOD = (int)(1e9 + 7);
LL qpow(LL a, LL b, LL p) {
	LL ans = 1;
	for(; b; b >>= 1) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	dsu.make_set(n);
	for (int i = 1; i + k - 1<= n; i++) 
		for (int j = i, p = 1; j <= (i + (k - 1) / 2); j++, p++)
			dsu.merge(j, i + k - p);
	cout << qpow(m, dsu.count(n), MOD) << endl;
	return 0;
}

