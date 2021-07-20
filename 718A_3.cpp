#include <bits/stdc++.h>
using namespace std;
string s;
int n, m;
int pos;
void work(int cur)
{
	cur--;
	if (cur < 0)
	{
		s = '1' + s;
		pos++;
		return;
	}
	if (s[cur] == '.')
		cur--;
	s[cur]++;
	if (s[cur] == '9' + 1)
	{
		s[cur] = '0';
		work(cur);
	}
}
int main()
{
//	ios::sync_with_stdio(false);
	cin >> n >> m;
	cin >> s;
	while (s[pos] != '.')
		pos++;
	pos++;
	while (pos < s.length() && s[pos] < '5')
		pos++;
	if (pos == s.length())
	{
		cout << s << endl;
		return 0;
	}
	for ( ; s[pos] != '.' && m; pos--)
		if (s[pos] >= '5')
		{
			s = s.substr(0, pos);
			work(pos); 
			m--;
		}
	if (s.back() == '.')
		s.pop_back();
	cout << s << endl;
	return 0;
}//2

