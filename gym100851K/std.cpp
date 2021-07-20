#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 1000;
int n, m;
vector<int> edge[maxn];
int e[maxn][2];
bool vis[maxn];
int in[maxn], out[maxn], nxt[maxn];
int stk[maxn];

void bad() {
  printf("There is no route, Karl!\n");
  exit(0);
}
void dfs(int x) {
  if (vis[x]) return;
  vis[x] = true;
  for (int t = 0; t < (int)edge[x].size(); t++) {
    int y = edge[x][t];
    dfs(y);
  }
}

void search(int x, int cnt) {
  if (cnt == n) {
    stk[cnt] = x;
    if (x == 1) {
      // find answer
      for (int i = 0; i <= cnt; i++) printf("%d ", stk[i]);
      printf("\n");
      exit(0);
    }
    return;
  }
  if (vis[x]) return;
  stk[cnt] = x;
  vis[x] = true;
  if (nxt[x]) {
    search(nxt[x], cnt + 1);
  } else {
    for (int t = 0; t < (int)edge[x].size(); t++) {
      int y = edge[x][t];
      search(y, cnt + 1);
    }
  }
  vis[x] = false;
  stk[cnt] = 0;
}

int main() {
  //	freopen("king.in", "r", stdin);
  //	freopen("king.out", "w", stdout);
  scanf("%d%d", &n, &m);
  if (m < n) {
    bad();
    return 0;
  }
  for (int i = 1; i <= n; i++) edge[i].clear();
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &e[i][0], &e[i][1]);
    edge[e[i][0]].push_back(e[i][1]);
  }
  // check connectivity
  memset(vis, 0, sizeof vis);
  dfs(1);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) bad();  //?

  for (int i = 1; i <= n; i++) edge[i].clear();
  for (int i = 1; i <= m; i++) edge[e[i][1]].push_back(e[i][0]);
  memset(vis, 0, sizeof vis);
  dfs(1);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) bad();  //?

  for (int i = 1; i <= n; i++) edge[i].clear();
  for (int i = 1; i <= m; i++) edge[e[i][0]].push_back(e[i][1]);

  // build nxt[]
  memset(nxt, 0, sizeof nxt);
  memset(in, 0, sizeof in);
  memset(out, 0, sizeof out);
  for (int i = 1; i <= m; i++) {
    int a = e[i][0], b = e[i][1];
    if (!in[b])
      in[b] = a;
    else if (in[b] != a)
      in[b] = -1;

    if (!out[a])
      out[a] = b;
    else if (out[a] != b)
      out[a] = -1;  // out[a]!
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (in[i] == 0 || out[i] == 0) bad();
  for (int i = 1; i <= n; i++)
    if (in[i] != -1 && out[i] != -1) {
      nxt[in[i]] = i;
      nxt[i] = out[i];
    } else
      cnt++;

  memset(vis, 0, sizeof vis);
  search(1, 0);
  bad();  //?
  return 0;
}
