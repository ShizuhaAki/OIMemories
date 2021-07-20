#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n, k;
string buf;
set <char> vowel = {'a', 'e', 'i', 'o', 'u'};
set <string> ok = {"aabb", "abba", "abab"};
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	vector < vector <int> > r;
	vector < int > nums; 
	vector < int > ans;
	set < vector <int> > exist;
	for (int q = 1; q <= n; q++) {
		map <string, int> rhyme;
		int cnt = 0;
		vector <int> rhythm;
		for (int i = 1; i <= 4; i++) {
			cin >> buf;
			int vcnt = 0;
			string suf;
			//======get suffix======
			for (int j = buf.length() - 1; j >= 0; j--) {
				suf.pb(buf[j]);
				if (vowel.count(buf[j]))vcnt++;
				if (vcnt == k)break;
			}		
			if (vcnt < k) {
				puts("NO");
				return 0;
			}
	//		cerr << suf << endl;
			//======update scheme======
			if (!rhyme.count(suf)) {
				rhythm.pb(++cnt);
				rhyme[suf] = cnt;
			}
			else  {
				rhythm.pb(rhyme[suf]);
			}
			if (cnt > 2) {
				puts("NO");
				return 0;
			}
		} 
		//put it into the schemes list
		r.pb(rhythm);
		nums.pb(cnt);
	}
	//======update answer======
	for (int i = 0; i < r.size(); i++) {
		if (nums[i] == 1)continue;
		else {
			if (!exist.count(r[i])) {
				exist.insert(r[i]);
			}
			if (exist.size() >= 2) {
				puts("NO");
				return 0;
			}
			else {
				ans = r[i];
			}
		}
	}
	//======check the validity of the answer======
	string output;
	if (ans.size() == 0)puts("aaaa"), exit(0);
	else for (auto i:ans) output.pb(i - 1 + 'a');
	if (ok.count(output)) {
		cout << output << endl;
	}
	else {
		puts("NO");
		return 0;
	}
	cout << endl;
	return 0;
}

