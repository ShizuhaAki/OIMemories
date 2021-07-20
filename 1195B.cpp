#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	if (n == 1)cout << 0 << endl,exit(0);
//	cerr << round(sqrt(4 * (2 * n + 2 * k))) << endl;
	cout << fixed << setprecision(0);
	cout << n - (-3 + round(sqrt(4 * (2 * n + 2 * k) + 9))) / 2 << endl;
	return 0;
}

