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
const int N = 211;
int a[N], b[N];
unordered_set <int> exist;
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		if (!exist.count(a[i]))exist.insert(a[i]);
	}
	cin >> m;
	rep(i, m) {
		cin >> b[i];
		if (!exist.count(b[i]))exist.insert(b[i]);
	}
	rep(i, n)rep(j, m)if (!exist.count(a[i] + b[j])) {
		cout << a[i] << ' ' << b[j] << endl;
		return 0;
	}
	return 0;
}

