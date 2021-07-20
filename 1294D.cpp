#include <bits/stdc++.h>
using namespace std;
map <int, int> mp;
const int N = 400040;
int a[N];
int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < x; i++) a[i] = i;
	int res = 0;
	while (n--) {
		int y;
		cin >> y;
		y %= x;
		mp[a[y]] = 1;
		while (mp[res]) res++;
		cout << res << endl;
		a[y] += x;
	}
}
