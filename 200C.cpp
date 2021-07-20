#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = s; (i) <= (int)t; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c;
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
char team1[30], team2[30];
const string home = "BERLAND";
map <string, int> goal;
map <string, int> dif;
map <string, int> score;
set <string> st;
set <string> played;
vector <string> teams;
int main() {
	repn(i, 5) {
		int x, y;
		scanf("%s %s %d:%d", team1, team2, &x, &y);
		
		string ta(team1), tb(team2);
		if (!st.count(ta)) {
			st.insert(ta);
			teams.pb(ta);
		}
		if (!st.count(tb)) {
			st.insert(tb);
			teams.pb(tb);
		}
		
		if (ta == home) 
			played.insert(tb);
		else if (tb == home) 
			played.insert(ta);
			
		if (x > y) 
			score[ta] += 3;
		else if (x == y) {
			score[ta]++; 
			score[tb]++;
		}
		else 
			score[tb] += 3;
			
		goal[ta] += x; 
		goal[tb] += y; 
		dif[ta] += x;
		dif[ta] -= y; 
		dif[tb] += y; 
		dif[tb] -= x;
	}
	played.insert(home);
	sort(teams.begin(), teams.end(), [](string a, string b) {
		if (score[a] != score[b]) 
			return score[a] > score[b];
		if (dif[a] != dif[b]) 
			return dif[a] > dif[b];
		if (goal[a] != goal[b]) 
			return goal[a] > goal[b];
		return a < b;
	});
	if (teams[0] == home || teams[1] == home) {
		cout << "1:0" << endl;
		return 0;
	}
	string enemy;
	for (auto x:teams) 
		if (!played.count(x)) {
			enemy = x;
			break;
		}
	int ansx = 300, ansy = 0;
	rep(i, 300)
		rep(j, i) {
			score[home] += 3; 
			goal[home] += i; 
			dif[home] += i; 
			dif[home] -= j;
			goal[enemy] += j; 
			dif[enemy] += j; 
			dif[enemy] -= i;
			
			sort(teams.begin(), teams.end(), [](string a, string b) {
				if (score[a] != score[b]) 
					return score[a] > score[b];
				if (dif[a] != dif[b]) 
					return dif[a] > dif[b];
				if (goal[a] != goal[b]) 
					return goal[a] > goal[b];
				return a < b;
			});
			if (teams[0] == home || teams[1] == home) {
				if (i - j < ansx - ansy) {
					ansx = i;
					ansy = j;
				}
				else if (i - j == ansx - ansy) {
					if (j < ansy) {
						ansx = i;
						ansy = j;
					}
				}
			}
			
			score[home] -= 3; 
			goal[home] -= i; 
			dif[home] -= i; 
			dif[home] += j;
			goal[enemy] -= j; 
			dif[enemy] -= j; 
			dif[enemy] += i;
		}
	if (ansx == 300 && ansy == 0) 
		puts("IMPOSSIBLE");
	else 
		printf("%d:%d\n", ansx, ansy);
	return 0;
}
