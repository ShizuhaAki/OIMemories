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
#include <cstdlib>
#include <ctime>
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

int main() {
	ios::sync_with_stdio(false);
	srand(time(NULL));
	while (true) {
		int n = rand() % 10;
		freopen("input.txt", "w", stdout);
		cout << n << endl;
		for (int i = 1; i <= n; i++)cout << rand() % 10 + 1 << endl;
		freopen("log.txt", "w", stdout);
		system("E:\\Codeforces\\1203E_WA3.exe < input.txt > output.txt");
		system("E:\\Codeforces\\1203E.exe < input.txt > answer.txt");
		freopen("output.txt", "r", stdin);
		int x;
		cin >> x;
		cout << x << " ";
		freopen("answer.txt", "r", stdin);
		int y;
		cin >> y;
		cout << y << " ";
		if (x != y)return 1;
	}
	return 0;
}

