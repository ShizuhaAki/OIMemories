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
int n, t;
string s;
int pos = 0;
void work(int cur) {
	cur--;
	if (cur < 0) {
		s = "1" + s;
		pos++;
		return;
	}
	if (s[cur] == '.')cur--;
	s[cur]++;
	if (s[cur] == '9' + 1) {
		s[cur] = '0';
		work(cur);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> t >> s;
	while (s[pos] != '.')pos++;
	pos++;
	while (pos < s.length() && s[pos] < '5')pos++;
	if (pos == s.length()) {
		cout << s << endl;
		return 0;
	}
	for (; s[pos] != '.' && t; pos--) {
		if (s[pos] >= '5') {
			s.resize(pos);
			work(pos);
			t--;
		}
	}
	if (s.back() == '.')s.pop_back();
	cout << s << endl;
	return 0;
}

