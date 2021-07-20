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
#pragma GCC optimize("O3")
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const LL MOD = 1e9 + 7;
LL qpow(LL a, LL b, LL p) {
	LL ans = 1;
	for (; b ; b >>= 1) {
		if (b & 1)ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}
inline LL read(LL &n)
{
	LL num=0;
	LL negative=1;
	char c=cin.get();
//	c=cin.get();
	while (c<'0'||c>'9')
	{
		if (c=='-')
			negative=-1;
		c=cin.get();
	}
//	c=cin.get();
	while (c<='9'&&c>='0')
	{
		num=num*10+c-'0';
		c=cin.get();
	}
	n=num*negative;
	return num*negative;
}
int main() {
	ios::sync_with_stdio(false);
	LL T;read(T);
	LL inv = qpow(24, MOD - 2, MOD);
	while (T--) {
		LL n;
		read(n);
		n += 3;
		n = ((((n * (n - 1)) % MOD) * (n - 2) % MOD) * (n - 3) % MOD);
		cout << n * inv % MOD << endl;
	}
	return 0;
}

