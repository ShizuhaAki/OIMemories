#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
string s;
int n, t, pos;
void run(int cur) {
	cur--;
	if (cur < 0) {
		s = '1' + s;
		pos++;
		return;
	}
	if (s[cur] == '.') cur--;
	s[cur]++;
	if (s[cur] > '9') {
		s[cur] = '0';
		run(cur);
	}
//	pos = cur;
} 
int main() {
	scanf("%d%d", &n, &t); cin >> s;
	for (pos = 0; s[pos] != '.'; pos++);pos++;
	for (; pos < n && s[pos] < '5'; pos++);
	if (pos == n) {
		cout << s << endl;
		return 0;
	}
	for (; s[pos] != '.' && t; pos--) {
		if (s[pos] >= '5') {
			s = s.substr(0, pos);
			t--;
			run(pos);
		}
	}
	if (s[s.length() - 1] == '.') s.pop_back();
	cout << s << endl;
	return 0;
}

