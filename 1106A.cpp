#include <bits/stdc++.h>
using namespace std;
const int MAXN = 520; 
char mat[MAXN][MAXN];
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>mat[i][j];
	for (int i=1;i+2<=n;i++)
		for (int j=1;j+2<=n;j++)
			if (mat[i][j]=='X'&&mat[i+2][j]=='X'&&mat[i][j+2]=='X'&&mat[i+1][j+1]=='X'&&mat[i+2][j+2]=='X')ans++;
	cout<<ans<<endl;
	return 0;
}

