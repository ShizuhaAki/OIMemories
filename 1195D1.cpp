#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long Power(long long a, long long b, long long p) {  // calculate (a ^ b) mod p
    long long ans = 1;
    for (; b; b >>= 1) {
        if (b & 1)
            ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}
int main()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		int cnt = 1;
		while (x)
		{
			int y = x % 10;x /= 10;
//			cerr << y << endl;
			ans = ((ans + n * y * Power(10, 2 * cnt - 1, MOD)) % MOD + n * y * Power(10, 2 * cnt - 2, MOD)) % MOD;
	//		cerr << ans << endl;
			cnt++;
		}
	}
	cout << ans << endl;
	return 0;
}

