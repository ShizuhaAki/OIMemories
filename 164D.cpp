
// Problem : D. Minimum Diameter
// Contest : VK Cup 2012 Round 3
// URL : https://codeforces.com/contest/164/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 1500.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = s; (i) <= (int)t; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 1010;
long long qread() {
	char c = getchar();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};
#define sqr(x) (x) * (x)
double dist(Point a, Point b) {
	return /*sqrt(*/sqr(a.x - b.x) + sqr(a.y - b.y)/*)*/;
}
int n, k;
vector <Point> a;
int deg[N];
vector <int> G[N];
bool deleted[N], ans[N];
void remove(int x) {
	//cerr << "RM " << x << endl;
	deleted[x] = true;
	for (auto v:G[x]) {
		deg[v]--;
		deg[x]--;
	}
}
void recover(int x) {
	///cerr << "RECOVER " << x << endl;
	deleted[x] = false;
	for (auto v:G[x]) {
		deg[v]++;
		deg[x]++;
	}
}
bool solve(int k) {
//	if (k < 0) return false;
	int leaf = -1, x = -1;
	rep(i, n) if (!deleted[i] && deg[i] == 1) {leaf = i; break;}
//	cerr << "LEAF = " << leaf << endl;
	if (leaf != -1) {
		auto it = G[leaf].begin();
		for (; it != G[leaf].end(); it++) {
			if (!deleted[*it]) break;
		}
		int v = *it;
		remove(v);
		if (k > 0 && solve(k - 1)) return true;
		recover(v);
		return false;
	}
	int maxdeg = 0;
	rep(i, n) if (!deleted[i] && deg[i] > maxdeg) {
		maxdeg = deg[i];
		x = i;
	}
	if (maxdeg == 0) return true; if (k == 0) return false;
	remove(x);
	if (solve(k - 1)) return true;
	recover(x);
	if (maxdeg > 1 && maxdeg <= k) {
		vector <int> ne;
		for (auto v:G[x]) if (!deleted[v]) ne.pb(v);
		for (auto i:ne) remove(i);
		if (solve(k - maxdeg)) return true;
		for (auto i:ne) recover(i);
	} 
	return false;
}
bool check(int x) {
//	cerr << "CALLING CHECK " << x << endl;
	rep(i, n) G[i].clear();
	memset(deg, 0, sizeof(deg));
	rep(i, n) rep(j, n) if (dist(a[i], a[j]) > x) {G[i].pb(j);deg[i]++;}
	memset(deleted, 0, sizeof(deleted));
	return solve(k);
}
int main() {
	n = qread(); k = qread();
	rep(i, n) {
		int x = qread(), y = qread();
		a.pb(Point(x, y));
	}
	int L = -1, R = 2100000000;
	while (L + 1 < R) {
		int mid = (L + R) >> 1;
		if (check(mid)) {rep(i, n) ans[i] = deleted[i]; R = mid;}
		else L = mid;
	}
	int rem = k;
	rep(i, n) if (ans[i]) rem--;
	rep(i, n) if (rem > 0 && !ans[i]) {
		ans[i] = true;
		rem--;
	}
	// rep(i, n) cerr << ans[i] << ' '; cerr << endl;
	rep(i, n) if (ans[i]) cout << i + 1 << ' '; cout << endl;
	return 0;
}
