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
const int N = 400000;
int random(int range = (int)1e9) {
	return rand() * rand() % range + 1; 
}
int main() {
	srand(2);
	ofstream in;
	for (int i = 1;; i++) {
		in.open("data.in");
		int n = random(10), x = random(5);
		in << n << ' ' << x << endl;
		repn(j, n) {
			int q = random(10);
			in << q << endl;
		}
		in.close();
		system("1294D < data.in > sol.out");
		system("1294D_bf < data.in > ans.out");
		if (system("fc sol.out ans.out > nul")) {
			cout << "FAILED ON TEST " << i << endl;
			return 1;
		}
		else cout << "PASSED TEST " << i << endl;
	//	system("del 1294D"); system("del 1294D_bf");
		system("del data.in"); system("del sol.out"); system("del ans.out");
	}
	return 0;
}

