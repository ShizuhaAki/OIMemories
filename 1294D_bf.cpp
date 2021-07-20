#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int

const int MAXN = 1e3 + 10;

void solve(){
	int q, x;
	cin >> q >> x;
	vector<int> a(x + 1);
	for( int i = 0; i < x; ++i){
		a[i] = i;
	}

	map<int, int> mp;
	int res = 0;
	int y;
	
	while( q-- ){
		cin >> y;
		y %= x;
		mp[a[y]] = 1;
		while( mp[res] ){
			res++;
		}
		cout << res << '\n';
		//now increase a[y]  to next req
		a[y] += x;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
	//int t; cin >> t;
	//while( t-- )
		solve();
	return 0;
}
