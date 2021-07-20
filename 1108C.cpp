#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s,orig;
	cin>>s;orig=s;
	if (n==1)//spj
	{
		cout << 0 << endl << s << endl;
		return 0;
	}
	if (n==2)//spj
	{
		int ans=0;
		if (s[0]==s[1]){
			ans=1;
			if (s[0]=='B')s[1]='G';
			else if (s[0]=='G')s[1]='R';
			else if (s[0]=='R')s[1]='B';
		}
		cout << ans << endl << s << endl;return 0;
	}
	if (n==3)//spj
	{
		if (s=="RGB"||s=="RBG"||s=="BGR"||s=="BRG"||s=="GBR"||s=="GRB")cout<<0<<endl<<s<<endl;
		if (s=="RRR"||s=="GGG"||s=="BBB")cout<<2<<endl<<"RGB"<<endl;
		else
		{
			bool changed=true;
			while (changed)
			{
				changed=false;
				if (s[0]==s[1])
				{
					changed=true;
					if (s[0]=='B')s[1]='G';
				    if (s[0]=='G')s[1]='R';
					if (s[0]=='R')s[1]='B';
				}
				if (s[1]==s[2])
				{
					changed=true;
					if (s[1]=='B')s[2]='G';
					if (s[1]=='G')s[2]='R';
					if (s[1]=='R')s[2]='B';
				}
				if (s[0]==s[2])
				{
					changed=true;
					if (s[0]=='B')s[2]='G';
					if (s[0]=='G')s[2]='R';
					if (s[0]=='R')s[2]='B';
				}
			}
			cout<<1<<endl<<s<<endl;
			return 0;
		}
	}
	char perm[3] = {'B','G','R'};
	int ans=0x3F3F3F3F;
	do
	{
		//cerr<<perm<<" ";
		int curr=0;
		string c=orig;
		for (int i=0;i<c.length();i++)if (c[i]!=perm[i%3])curr++,c[i]=perm[i%3];
		if (curr < ans)
		{
			ans=curr;
			s=c;
		}
		//cerr<<curr<<endl;
	}while(next_permutation(perm,perm+3));
	cout<<ans<<endl<<s<<endl; 
}
