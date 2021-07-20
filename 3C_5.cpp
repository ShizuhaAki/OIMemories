#include <bits/stdc++.h>
using namespace std;
#define get(i, j) (((i) >> ((j) << 1) & 3)
#define opposite(str) ((str == "first") ? "second" : "first")
const string wins[] = {"012", "345", "678", "036", "147", "258", "246", "048"};
inline int countones(int x)
{
	int res;
	for (; x; x >>= 1)if (x & 1)res++;
	return res;
}
inline bool check(string s)
{
	for (int i = 0; i < 8; i++)
		if ((get(s, wins[i][0] - '0') == get(s, wins[i][1] - '0')) and (get(s, wins[i][1] - '0') == get(s, wins[i][2] - '0')) and get(s, wins[i][0]))return true;
	return false;
}
unordered_map <string, string> chtholly;
void dfs(int state, string verdict, int sign)
{
	if (check(state))chtholly[state] = "the  " + opposite(verdict) + "player won";
	else if (countones(state) == 9)chtholly[state]  = "draw";
	else
	{
		chtholly[state] = verdict;
		for (int i = 0; i < 9; i++)
			if (get(state, i) == 0)
			{
				state ^= sign << (2 * i);
				dfs(state, opposite(verdict), 3 - sign);
				state ^= sign << (2 * i);
			}
	}
}
int main()
{
	dfs(0, "first", 1);
	string in;
	int nephren = 0;
	for (int i = 1; i <= 3; i++)
	{
		cin >> in;
		for (int j = 0; j < 3; j++)
			if (in[j] == 'X')nephren |= 1 << (6 * i + 2 * j);
			else if (in[j] == '0')nephren |= 2 << (6 * i + 2 * j); 
	}
	if (chtholly.count(nephren))cout << chtholly[nephren] << endl;
	else cout << "illegal" << endl;
	return 0;
}

