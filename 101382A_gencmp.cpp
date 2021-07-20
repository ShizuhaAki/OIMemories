#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
typedef pair <int, int> PII;
#define all(x) (x.begin(),  x.end())
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c = getchar();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
int main() {
	for (int i = 1; i <= 100000; i++) {
		system(("echo " + to_string(i) + " > input.txt").c_str());
		string r1 = "E:\\Codeforces\\101382A_testgen1 < E:\\Codeforces\\input.txt";
		string r2 = "E:\\Codeforces\\101382A_testgen2 < E:\\Codeforces\\input.txt";
		system((r1).c_str());
		system((r2).c_str());
		if (system("fc E:\\Codeforces\\bf.out E:\\Codeforces\\sol.out > nul")) {
			cout << "FAILED ON TEST " << i << endl;
			system("fc E:\\Codeforces\\bf.out E:\\Codeforces\\sol.out");
			return 1;
		}
		else {cout << "\rPASSED TEST " << i << "[";double pr = i / 100000.0 * 100; rep(i, pr) cout << "#"; rep(i, 100-pr) cout << "-";cout << "]";}
	}
	return 0;
}
