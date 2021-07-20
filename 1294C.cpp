/*
ID: yzshang1
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
int n;
long long mulmod(long long a, long long b, long long p) { // calculate (a ^ b) mod p
	long long ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}
const int bases[] = {2, 7, 61};
bool witness(int base, int n)
{
	int tmp = n - 1;
	int s = 0, t = 0;
	while (tmp % 2 == 0)
	{
		tmp /= 2;
		s++;
	}
	t = tmp;
	long long x = mulmod(base, t, n);
	if (x == 1 || x == n - 1)return true; //judge b^t \equiv 1 (\mod n)
	else
	{
		int j = s - 1;
		while (j--)
		{
			x = x * x % n;
			if (x == n - 1)return true;
		}// judge b^{2^jt} \equiv 1 (\mod n)
	}
	return false;
}
bool miller_rabin(int n)
{
	if (n == 2 || n == 61 || n == 7)return true;
	if (n < 2 || n % 61 == 0 || n % 2 == 0 || n % 7 == 0)return false;
	for (int i = 0; i < 3; i++)
	{
		int base = bases[i];
		if (!witness(base, n))return false; 
	}
	return true;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		if (miller_rabin(n)) {
			puts("NO");
			continue;
		}
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				int nn = n / i;
				if (miller_rabin(nn)) continue;
				for (int j = 2; j * j <= nn; j++) {
					if (nn % j == 0 && j != i) {
						if (nn / j != j && nn / j != i) {
							cout << "YES" << endl;
							cout << i << ' ' << j << ' ' << nn / j << endl;
							goto ESC;
						}
					}
				}
			}
		} 
		puts("NO");
		ESC:continue;
	}
	return 0;
}

