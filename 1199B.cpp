#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long l, h;
	cin >> h >> l;
	cout << fixed << setprecision(10) << (l * l - h * h) / (long double)(2 * h) << endl;
	return 0;
}

