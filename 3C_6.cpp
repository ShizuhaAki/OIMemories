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
bool win(const string& s, const char c) {
	rep(i, 3) if (s[i] == c and s[i + 3] == c and s[i + 6] == c) return true;
	rep(i, 3) if (s[i * 3] == c and s[i * 3 + 1] == c and s[i * 3 + 2] == c) return true;
	if (s[0] == c and s[4] == c and s[8] == c) return true;
	if (s[2] == c and s[4] == c and s[6] == c) return true;
	return false;
}
map <string, string> mem;
string s = ".........";
const string p = "X0", v[] = {"first", "second"};
void prework(int dep) {
	if (win(s, 'X')) {
		mem[s] = "the first player won";
		return;
	}
	else if (win(s, '0')) {
		mem[s] = "the second player won";
		return;
	}
	else if (dep == 9) {
		mem[s] = "draw";
		return;
	} 
	mem[s] = v[dep % 2];
	rep(i, 9) {
		if (s[i] != '.') continue;
		s[i] = p[dep % 2];
		prework(dep + 1);
		s[i] = '.';
	}
}
int main() {
	prework(0);
	string in;
	rep(i, 3) {
		string t;
		cin >> t;
		in += t;	
	}
	if (!mem.count(in)) cout << "illegal" << endl; else cout << mem[in] << endl; 
	return 0;
}

