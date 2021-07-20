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
const int N = 10010;
string s[N];
extern int n;
inline int check() {
	bool aaaa = 1, aabb = 1, abba = 1, abab = 1;
	for (int i = 0; i < n; i += 4) {
		rep(j, 4) {
			if (s[i] != s[i + j])aaaa = 0;
		}
		if (aaaa)continue;
		if (s[i] != s[i + 1] || s[i + 2] != s[i + 3]) aabb = 0;
		if (s[i] != s[i + 2] || s[i + 1] != s[i + 3]) abab = 0;
		if (s[i] != s[i + 3] || s[i + 1] != s[i + 2]) abba = 0;
	}
	if (aaaa)return 1;
	if (aabb)return 2;
	if (abba)return 3;
	if (abab)return 4;
	return -1;
}
inline bool is_vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
} 
inline int get_pos(const string& buf, int k) {
	int cnt = 0;
	for (int i = buf.length() - 1; i >= 0; i--) {
		if (is_vowel(buf[i]))cnt++;
		if (cnt == k)return i;
	}
	return -1;
} 
int n, k;
string buf;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	n *= 4;
	rep(i, n) {
		cin >> buf;
		int idx = get_pos(buf, k);
		if (idx == -1) {
			cout << "NO" << endl;
			return 0;
		}
		s[i] = buf.substr(idx);
	}
	switch (check()) {
		case 1:
			cout << "aaaa" << endl;
			return 0;
		case 2:
			cout << "aabb" << endl;
			return 0;
		case 3:
			cout << "abba" << endl;
			return 0;
		case 4:
			cout << "abab" << endl;
			return 0;
		case -1:
			cout << "NO" << endl;
			return 0;
		default:
			fail("UNEXPECTED CHECK() VALUE! "); 
	}
	return 0;
}

