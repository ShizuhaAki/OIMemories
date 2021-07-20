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
const int MAXN = 200020;
template <int MAXN> struct DSU {
	int fa[MAXN];
	DSU(int n = 0) {
		for (int i = 1; i <= n; i++)fa[i] = i;
	}
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
int a[MAXN], vis[MAXN], n, root;
int dfs(int x) {
	if (vis[x])return x;
	vis[x] = true;
	return dfs(a[x]);
}
DSU <200020> dsu;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;root = -1;
	int ans = 0;
	dsu.make_set(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == i)root = i;
	}
	if (root == -1) {
		root = dfs(1);
		ans++;
		a[root] = root;
		memset(vis, 0, sizeof(vis));
	}
	for (int i = 1; i <= n; i++)dsu.merge(i, a[i]);
	for (int i = 1; i <= n; i++) {
		if (dsu.find(root) == dsu.find(i))continue;
		int now = dfs(i);
		ans++;
		a[now] = root;
		dsu.merge(now, root);
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)cout << a[i] << ' ';
	cout << endl;
	return 0;
}

