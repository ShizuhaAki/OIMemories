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
#include <queue>
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
const int N = 110;
int n, r;
struct Event {
	int bound, delta;
	bool operator < (const Event& b)const {
		if (delta > 0 && b.delta > 0) {
			if (delta != b.delta) {
				return delta < b.delta; 
			}
			else {
				return bound < b.bound;
			}
//			return delta < b.delta;
		}
		if (delta > 0 && b.delta < 0)return 0;
		if (delta < 0 && b.delta > 0)return 1;
		else {
			return delta < b.delta;
		}
	}
	Event(int bound = 0, int delta = 0) : bound(bound), delta(delta) {} 
};
Event e[N];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> r;
	priority_queue <Event> pq;
	for (int i = 1; i <= n; i++) {
		cin >> e[i].bound >> e[i].delta;
		pq.push(e[i]);
	}
	vector <Event> tmp;
	tmp.clear();
	int took = 0;
	while (!pq.empty()) {
		auto cr = pq.top(); pq.pop();
		if (cr.bound > r || r + cr.delta < 0) {
			tmp.pb(cr);
		}
		else {
//			if (r + cr.delta <= 0)continue; 
			took++;
			r += cr.delta;
			for (auto i:tmp)pq.push(i);
			tmp.clear();
		}
	}
	if (took == n)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}

