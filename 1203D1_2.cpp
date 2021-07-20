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
string s, t;
int main() {
	ios::sync_with_stdio(false);
	cin >> s >> t;
	int ans = 0;
	for (int i = 0; i < (int)s.length(); i++)
		for (int j = 0; j < (int)s.length(); j++) {
			int len = 0;
			for (int p = 0; p < (int)s.length(); p++) {
				if (i <= p && p <= j)continue;
				if (len < (int)t.length() && s[p] == t[len])len++;
			}
			if (len == (int)t.length())ans = max(ans, j - i + 1);
		}
	cout << ans << endl;
	return 0;
}

