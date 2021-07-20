#include <iostream>
#include <algorithm>
using namespace std;
int a[102];
int n;
int main()
{
	cin>>n;
	for (int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int ans=0;
	for (int i=1;i<n;i+=2)ans+=a[i]-a[i-1];
	cout<<ans<<endl;
	return 0; 
} 
