#include <bits/stdc++.h>
using namespace std;
const int MAXN=300010;
int a[MAXN];
int main()
{
	int n;cin>>n;
	long long ans=0;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n/2;i++)ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
	cout<<ans<<endl;
	return 0;
}

