
// Problem: D. Don't fear, DravDe is kind
// Contest: Codeforces - Codeforces Beta Round #28 (Codeforces format)
// URL: https://codeforces.com/contest/28/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define VPII vector <PII>
#define y2 y1919810
typedef pair <int, int> PII;
typedef vector <int> VI;
//#define int long long
#define all(x) x.begin(),  x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
#define il inline
#define RESET(x) memset((x), 0, sizeof(x))


const int MINF = INT_MIN;
const long double EPS = 1e-6;
LL qread() {
    char c = getchar();
    int neg = 1;
    LL val = 0;
    while (c != '-' && !isdigit(c)) c = getchar();
    if (c == '-') {
        c = getchar(); 
        neg = -1;
    }
    while (isdigit(c)) {
        val = (val << 3) + (val << 1) + c - '0';
        c = getchar();
    }
    return neg * val;
}
const int N = 100010;
int n, v[N], c[N], l[N], r[N];
map <int, VI> sum;
int dp[N], path[N];
void solve() {
    n = qread();
    rep(i, n) {
        v[i] = qread(); c[i] = qread(); l[i] = qread(); r[i] = qread();
        sum[c[i] + l[i] + r[i]].pb(i);
    }
    fill(dp, dp + n, MINF);
    for (auto x: sum) {
        vector <int>& cur = x.second;
        map <int, PII> mx;    // respectively, l[i], v and last (for printing solutions)
        for (auto i: cur) {
            if (l[i] == 0) {
                dp[i] = v[i];
                path[i] = -1;
            } else if (mx.count(l[i])) {    // we've been through this
                dp[i] = mx[l[i]].first + v[i];
                path[i] =mx[l[i]].second;
            }
            if (dp[i] != MINF) {    // update
                mx[l[i] + c[i]] // next
                = max(mx[l[i] + c[i]], mp(dp[i], i));
            }
        }
    }
    int bestv = MINF, besti = -1;
    rep(i, n) {
        if (r[i] == 0 && dp[i] >= bestv) {
            bestv = dp[i];
            besti = i;
        }
    }
    if (bestv == MINF) {puts("0"); return;}
    stack <int> ans;
    for (int i = besti; i != -1; i = path[i]) ans.push(i);
    printf("%d\n", (int)ans.size());
    while (!ans.empty()) {
        printf("%d ", ans.top() + 1);
        ans.pop();
    }
}
signed main() {
    int T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}
