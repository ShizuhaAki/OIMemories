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
#define lshll(i) (1LL << (i))s
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
const string vowels = "aeiou";
int n, k;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	string ans = "aaaa";
	rep(i, n) {
		vector <string> s;
		rep(j, 4) {
			string buf;
			cin >> buf;
			int vcnt = 0;
			for (int p = buf.length() - 1; p >= 0; p--) {
				if (strchr("aeiou", buf[p]) != NULL)vcnt++;
				if (vcnt >= k) {
					s.pb(buf.substr(p));
					break;
				}
			}
		}
		string res;
		if (s.size() < 4) {
			res = "NO";
		}
		else if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3]){
			res = "aaaa";
		}
		else if (s[0] == s[1] && s[2] == s[3]) {
			res = "aabb";
		}
		else if (s[0] == s[2] && s[1] == s[3]) {
			res = "abab";
		}
		else if (s[0] == s[3] && s[1] == s[2]) {
			res = "abba";
		}
		else {
			res = "NO";
		}
		if (res == "aaaa")continue;
		if (ans == "aaaa")ans = res;
		else if (ans == res);
		else {
			res = "NO";
		}
	} 
	puts(ans.c_str());
	return 0;
}

