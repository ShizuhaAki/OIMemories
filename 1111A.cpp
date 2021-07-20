#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c)
{
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
int main()
{
	string a,b;
	cin>>a>>b;
	if (a.length()!=b.length())
	{
		cout<<"No"<<endl;
		return 0; 
	}
	else
	{
		for (int i=0;i<a.length();i++)
		{
			if (isVowel(a[i])!=isVowel(b[i]))
			{
				cout<<"No"<<endl;
				return 0;
			}
		}
		cout<<"Yes"<<endl;
	}
	return 0;
}

