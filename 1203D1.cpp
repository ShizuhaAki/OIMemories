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
using LL = long long;
using ULL = unsigned long long;
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
string s, t;
int ans;
vector <int> em(0);
inline int calc(vector <int> x) {
	int res = x[0] - 1;
	for (int i = 1; i < x.size(); i++)res = max(res, x[i] - x[i - 1] - 1);
	return res;
}
void dfs(int now, int dep, vector <int> route) {
	if (dep == t.length()) {
		ans = max(ans, calc(route));
		return;
	 } 
	else {
		for (int i = now + 1; i < s.length(); i++) {
			if (s[i] = t[dep]) {
				route.pb(i);
				dfs(i, dep + 1, route);
				route.pop_back();
			}
		}
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cin >> s >> t;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == t[0]) {
			vector <int> fi;
			fi = em;
			fi.pb(i);
			dfs(i, 1, fi);
			break;
		}
	cout << ans << endl;
	return 0;
}

