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
int a[200020], n, m, sz, b[200020];
set <int> forbid;
int main()
{
	cin >> n >> m;
	rep(i, n)cin >> a[i], forbid.insert(a[i]);
	freopen("output.txt", "r", stdin);
	cin >> sz;
	rep(i, sz)cin >> b[i];
	long long prefix = 1;
	rep(i, sz) {
		prefix = (((prefix * b[i]) % m) + m) % m;
		if (forbid.count(prefix)) {
			cerr << "Failed! Duplicate " << prefix << endl;
			return 1;
		} 
		else forbid.insert(prefix);
	}
	cerr << "Passed!" << endl;
	return 0;
}

