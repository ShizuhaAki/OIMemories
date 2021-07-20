#include <iostream>
using namespace std;
bool check(int a,int b,int c,int x,int y,int z)
{
	return x<=a && y<=b && z<=c;
}
int main()
{
	int y,b,r;
	cin>>y>>b>>r;
	int ans=0x3f3f3f3f;
	if (check(y,b,r,y,y+1,y+2))ans=min(ans,3*y+3);
	if (check(y,b,r,b-1,b,b+1))ans=min(ans,3*b);
	if (check(y,b,r,r-2,r-1,r))ans=min(ans,3*r-3);
	cout<<ans<<endl;
	return 0;
}
