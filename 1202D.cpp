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

int main() {
	ios::sync_with_stdio(false);
	int T;cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int x = 0;
		while (x * (x + 1) / 2 <= n)x++;
		string s;
		int rem = n - x * (x - 1) / 2;
		s += "133";
		while (rem--)s += "7";
		x -= 2;
		while (x--)s += "3";
		cout << s << 7 << endl;
	}
	return 0;
}

