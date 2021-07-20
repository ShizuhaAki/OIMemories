#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN = 200010;
bool cmp(int x,int y)
{
	return x>y;
}
int a[MAXN];
int main(){
	int n,k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> a[i];
	string sq;cin >> sq;
	long long ans = 0;
	for (int i = 0; i <n ; )
	{
		//cerr << i << endl;
		int j;
		for (j = i; j < n&& sq[j] == sq[i]; j++);
		//cerr << j << endl;
		if (j-i<=k)
		{
			for (int d = i; d < j; d ++)ans+=a[d];
			i=j;
			if (j >= n)break;
			continue;
		}
		sort(a+i,a+j,cmp);
		for (int x = i; x < i+k; x++)ans+=a[x];
		i=j;
		if (j >= n)break;
	} 
	cout << ans << endl;
}
