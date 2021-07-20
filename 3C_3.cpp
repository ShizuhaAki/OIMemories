#include <bits/stdc++.h>
using namespace std;
unordered_map <string, string> hashmap;
int win(string s)
{

	for (register int i = 0; i < 2; i++)
	{
		if (s[i] == 'X' && s[i + 3] == 'X' && s[i + 6] == 'X')return 1;
		if (s[i] == '0' && s[i + 3] == '0' && s[i + 6] == '0')return 2;
	}
	for (register int i = 0; i <= 6; i += 3)
	{
		if (s[i] == 'X' && s[i + 1] == 'X' && s[i + 2] == 'X')return 1;
		if (s[i] == '0' && s[i + 1] == '0' && s[i + 2] == '0')return 2;
	}
	if (s[0] == 'X' && s[4] == 'X' && s[8] == 'X')return 1;
	if (s[0] == '0' && s[4] == '0' && s[8] == '0')return 2;
	for (register int i = 0; i < 9; i++)if (s[i] == '.')return -1;
	return 0;
}
void dfs(string s,string now, string verdict, int cnt)
{
//	cerr << now << " " << verdict << endl;
	if (now == s)
	{
		puts(verdict.c_str());
		exit(0);
	}
	if (!hashmap.count(now))hashmap.insert(make_pair(now, verdict));
	if (cnt == 9 || verdict == "the first player won" || verdict == "the second player won" || verdict == "draw")return;
	for (register int i = 0; i < now.length(); i++)
	{
		if (now[i] != '.')continue;
		if (verdict == "first")
		{
			now[i] = 'X';
			if (win(now) == 1)
			{
				dfs(s, now, "the first player won", cnt + 1); 
				now[i] = '.';
				continue;
			}
			else if (win(now) == 0)
			{
				dfs(s, now, "draw", cnt + 1);
				now[i] = '.';
				continue;
			}
			else if (win(now) == -1)
			{
				dfs(s, now, "second", cnt + 1);
				now[i] = '.';
				continue;
			}
		}
		else if (verdict == "second")
		{
			now[i] = '0';
			if (win(now) == 2)
			{
				dfs(s, now, "the second player won", cnt + 1); 
				now[i] = '.';
				continue;
			}
			else if (win(now) == 0)
			{
				dfs(s, now, "draw", cnt + 1);
				now[i] = '.';
				continue;
			}
			else if (win(now) == -1)
			{
				dfs(s, now, "first", cnt + 1);
				now[i] = '.';
				continue;
			}
		}
		else assert(!"Invalid verdict.");
	}	
}
int main()
{
	string s;
	for (int i = 1; i <= 3; i++)
	{
		string in;cin >> in;
		s += in;
	}
	int cx, cy;
	for (int i = 0; i < 9; i++)if (s[i] == 'X')cx++;else if (s[i] == '0')cy++;
	if ((win(s) == 1 && cx != cy + 1) || (win(s) == 2 && cx != cy))
	{
		puts("illegal");
		exit(0);
	}
	if (win(s) == 1)puts("the first player won");
	if (win(s) == 0)puts("draw");
	if (win(s) == 2)puts("the second player won");
	dfs(s, ".........", "first", 0);
	if (!hashmap.count(s))puts("illegal");else puts(hashmap[s].c_str());
	return 0;
}

