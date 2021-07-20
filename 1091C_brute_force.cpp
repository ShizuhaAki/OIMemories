#include <set>
#include <iostream>
using namespace std;
int main()
{
	long long ans=1;
	set<long long>s;
	int curr=0;
	int n;cin>>n;
	for (int i=1;i<=n;i++)
	{
		curr=(curr+i)%n;
		while (curr)
		{
			ans+=(curr+1);
			curr=(curr+i)%n;
		}
		if (!s.count(ans))s.insert(ans);
		ans=1;
	}
	for (auto it=s.begin();it!=s.end();it++)cout<<*it<<" ";
}
