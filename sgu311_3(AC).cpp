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
#define int long long
#define all(x) x.begin(),  x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
    char c = getchar();
    int neg = 1;
    long long val = 0;
    while (c != '-' && !isdigit(c)) 
        c = getchar();
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
const int N = 1000011;
LL cost[N], costSum[N], cntSum[N];
void update(int x, int y) {
    cost[x] += y;
    for (int i = x; i <= 1e6; i += (i & -i)) {
        costSum[i] += (LL)x * (LL)y;
        cntSum[i] += (LL)y;
    }
}
LL query(LL* arr, int x) {
    LL ret = 0;
    for (int i = x; i; i -= (i & -i)) {
        ret += arr[i];
    }
    return ret;
}
int get(LL x) {
    int ret = 0;
    for (int i = 19; i >= 0; i--) {
        if (ret + lsh(i) <= 1e6 && cntSum[ret + lsh(i)] < x) {
            ret += lsh(i);
            x -= cntSum[ret];
        }
    }
    return ret;
}
void solve() {
    string s;
    int n, t;
    while (cin >> s >> n >> t) {
        if (s == "ARRIVE") {
            update(t, n);
        } else {
            int cur = get(n);
            int price = query(costSum, cur) + (n - query(cntSum, cur)) * (cur + 1);
            if (price > t) {
                cout << "UNHAPPY" << endl;
            } else {
                cout << "HAPPY" << endl;
                while (n) {
                    cur = get(1) + 1;
                    LL delta = min(cost[cur], (LL)n);
                    n -= delta;
                    update(cur, -delta);
                }
            }
        }
    }
}
signed main() {
    int T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}
