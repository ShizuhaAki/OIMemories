#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 300030;
int x[N],  // the initial position of turtle $i
    t[N],  // the level of turtle $i, will be the first part of the final ans
    p[N], q[N];
int cnt[N];  // the number of food that turtle $i eaten
set<pair<int, int> > c;
multiset<pair<int, int> > d;
void cleanup(int id) {
  if (!c.count(make_pair(x[id], id))) return;
  while (true) {
    auto it = c.lower_bound(make_pair(x[id] + 1, -1));
    if (it == c.end()) break;
    int s = it->second;
    if (x[id] + t[id] < x[s] + t[s]) break;
    c.erase(it);
    d.erase(make_pair(x[s] + t[s], s));
  }
}
void attempt(int id) {
  while (true) {
    auto it = c.lower_bound(make_pair(x[id] + 1, -1));
    if (it == c.begin()) break;
    it--;
    if (it->first < x[id]) break;
    int s = it->second;
    t[id] += q[s];
    cnt[id]++;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> t[i];
    c.insert(make_pair(x[i], i));
    d.insert(make_pair(x[i] + t[i], i));
    cleanup(i);
  }
  for (int i = 0; i < m; i++) {
    cin >> p[i] >> q[i];
    auto it = c.lower_bound(make_pair(p[i], -1));
    
  }
}