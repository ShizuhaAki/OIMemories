#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	string s;
	cin>>s;
	for (int i=1;i<(s.length()-1);i++)
	{
		if (s[i]==s[i-1])
		{
			ans++;
			if (s[i]==s[i+1])
			{
				if (s[i-1]=='B')s[i]='G';
				else if (s[i-1]=='G')s[i]='R';
				else if (s[i-1]=='R')s[i]='B';
			}
			else
			{
				if (s[i-1]=='B'&&s[i+1]=='G')s[i]='R';
				if (s[i-1]=='G'&&s[i+1]=='B')s[i]='R';
				if (s[i-1]=='R'&&s[i+1]=='G')s[i]='B';
				if (s[i-1]=='G'&&s[i+1]=='R')s[i]='B';
				if (s[i-1]=='R'&&s[i+1]=='B')s[i]='G';
				if (s[i-1]=='B'&&s[i+1]=='R')s[i]='G';
			}
		}
	}
	if (s[n-1]==s[n-2])//spj
	{
		ans++;
		if (s[n-2]=='B')s[n-1]='G';
		else if (s[n-2]=='G')s[n-1]='R';
		else if (s[n-2]=='R')s[n-1]='B';
	}
	cout<<ans<<endl<<s<<endl;
	return 0;
}
