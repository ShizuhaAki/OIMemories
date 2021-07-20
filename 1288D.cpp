/*
ID: yzshang1
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 300030, M = 10;
int a[N][M];
int n, m, mx;
pair <int, int> res;
bool check(int x) {
	vector <int> mask(lsh(m), -1);
	rep(i, n) {
		int p = 0;
		rep(j, m) {
			if (a[i][j] >= x) p ^= lsh(j);
		}
		mask[p] = i;
	}
	vector <int> app(lsh(m));
	if(mask[(1 << m) - 1] != -1)
    {
        res.first = res.second = mask[(1 << m) - 1];
        return true;
    }
	rep(i, lsh(m)) rep(j, lsh(m)) if (mask[i] != -1 && mask[j] != -1 && (i | j) == lsh(m) - 1)	{
	//	cerr << "qwq" << endl; 
		res.first = mask[i];
		res.second = mask[j];
		return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n) rep(j, m) {
		cin >> a[i][j];
		mx = max(mx, a[i][j]);
	} 
	int L = 0, R = 1000000050;
	while (L + 1 < R) {
		int mid = (L + R) >> 1;
		if (check(mid)) {
			L = mid;
		}
		else R = mid;
	}
//	if (res.first)
		cout << res.first + 1 << ' ' << res.second + 1 << endl;
//	else cout << n << ' ' << n << endl;
	return 0;
}

