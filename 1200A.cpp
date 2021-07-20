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
bool room[11];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)  {
		char c = s[i];
		if (isdigit(c))room[c - '0'] = 0;
		else if (c == 'R') {
			for (int r = 9; r >= 0; r--) 
				if (!room[r])
				{
					room[r] = 1;
					break;
				}
		}
		else if (c == 'L') {
			rep(l, 10)
				if (!room[l])
				{
					room[l] = 1;
					break;
				}
		}
	}
	rep(i, 10)cout << room[i];
	cout << endl;
	return 0;
}

