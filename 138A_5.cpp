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
const long double EPS = 1e-6;
int n, k;
const string vowel = "aeiou";
string a[10010];
char buf[10010];
int main() {
	scanf("%d%d", &n, &k);
	rep(i, n * 4) {
		scanf("%s", buf);
		int cnt = 0;
		for (int j = strlen(buf) - 1; j >= 0; j--) {
			if (vowel.find(buf[j]) != string::npos)cnt++;
			if (cnt == k) {
				a[i] = string(buf + j);
				break;
			}
		} 
		if (a[i].size() == 0)a[i] += '0' + (i % 4);
	}
	bool aabb = 1, abba = 1, abab = 1;
	for (int i = 0; i < 4 * n; i += 4) {
		aabb &= a[i] == a[i + 1] and a[i + 2] == a[i + 3];
		abba &= a[i] == a[i + 3] and a[i + 1] == a[i + 2];
		abab &= a[i] == a[i + 2] and a[i + 3] == a[i + 1]; 
	}
	if (aabb and abab and abba)puts("aaaa");
	else if (aabb)puts("aabb");
	else if (abab)puts("abab");
	else if (abba)puts("abba");
	else puts("NO");
	return 0;
}

