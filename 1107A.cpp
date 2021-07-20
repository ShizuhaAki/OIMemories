#include <iostream>
using namespace std;
int main()
{
	int q;
	cin>>q;
	while (q--)
	{
		int n;cin>>n;
		string s;
		cin >> s;
		if (n==2)
			if (s[1] <= s[0])cout <<"NO" << endl;
			else cout << "YES" << endl << 2 << endl << s[0] << " " << s[1] << endl;
		else{
			cout << "YES" << endl << 2 << endl; 
			cout << s[0] << " ";
			for (int j = 1; j < n; j++)cout << s[j];
			cout << endl;
		}
	}	
}
