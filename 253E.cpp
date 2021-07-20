
// Problem : E. Printer
// Contest : Codeforces Round #154 (Div. 2)
// URL : https://codeforces.com/problemset/problem/253/E
// Memory Limit : 256.000000 MB 
// Time Limit : 4000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int long long
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = s; (i) <= (int)t; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c;
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
const int N = 50500;
struct Task {
	int time, priority, page, id;
	Task(int time = 0, int priority = 0, int page = 0, int id = 0):
		time(time), priority(priority), page(page), id(id){}
	bool operator < (const Task b) const{if (time != b.time)return time < b.time;return priority > b.priority;}
}a[N];
int n, missing, T;
vector <int> feasible;
set <int> P;
int remain[N], endtime[N];
void simulate(int x) {
	priority_queue < pair <int, int> > pq;
	rep(i, n) remain[i] = a[i].page; 
	a[missing].priority = x;
	rep(i, n) {
		int t = i ? a[i - 1].time : 0;
		//cerr << t << endl;
		while (!pq.empty() && t < a[i].time) {
			int idx = pq.top().second;
			int done = min(a[i].time - t, remain[idx]);
			remain[idx] -= done; t += done;
			if (!remain[idx]) {
				endtime[a[idx].id] = t;
				pq.pop();
			}
		}
		pq.push(mp(a[i].priority, i));
	}
	int t = a[n - 1].time;
	while (!pq.empty()) {
		int idx = pq.top().second; pq.pop();
		t += remain[idx];
		endtime[a[idx].id] = t;
	}
	
}
signed main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	n = qread();
	rep(i, n) {
		int t = qread(), s = qread(), p = qread();
		a[i] = Task(t, p, s, i);
		P.insert(p);
	}
	T = qread();
	sort(a, a + n);
	rep(i, n) {
		if (a[i].priority == -1) {missing = i; continue;}
		if (a[i].priority > 1 && !P.count(a[i].priority - 1)) feasible.pb(a[i].priority - 1);
		if (a[i].priority + 1 < 1000000000 && !P.count(a[i].priority + 1)) feasible.pb(a[i].priority + 1);
	}
	sort(feasible.begin(), feasible.end()); feasible.resize(unique(feasible.begin(), feasible.end()) - feasible.begin());
	int L = 0, R = feasible.size();
	//cerr << L << ' ' << R << endl;
	while (L + 1 < R) {
		int mid = (L + R) >> 1;
		//cerr << mid << endl;
		simulate(feasible[mid]);
		if (endtime[a[missing].id] == T) {
			a[missing].priority = feasible[mid];
			break;
		}
		else if (endtime[a[missing].id] > T) L = mid;
		else R = mid;
	}
	cout << a[missing].priority << endl;
	rep(i, n) cout << endtime[i] << ' '; cout << endl;
	return 0;
}
