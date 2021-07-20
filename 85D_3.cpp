#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int tot = 0;
struct TreapNode* Null;
struct TreapNode {
  LL key, aux, size;
  TreapNode *lc, *rc;
  int id;
  LL sum[5];
  TreapNode() : lc(Null), rc(Null) {}
  TreapNode(LL k = 0) : key(k), aux(rand()), size(1), lc(Null), rc(Null) {
    key = k;
    for (int i = 0; i < 5; i++) sum[i] = 0;
    id = ++tot;
  }
  void pushup() {
    size = lc->size + 1 + rc->size;
    for (int i = 0; i < 5; i++) {
      sum[i] = lc->sum[i];
    }
    LL k = lc->size;
    sum[k % 5] += key;
    k++;
    //	if (k == 5) k = 0;

    for (int i = 0; i < 5; i++) {
      sum[(k + i) % 5] += rc->sum[i];
    }
  }
} * root;
void trackNull() {}
LL getRank(TreapNode* u, LL v) {
  //    cerr << u -> id << endl;
  if (u == Null) return 0;
  return (v < u->key) ? getRank(u->lc, v) : getRank(u->rc, v) + u->lc->size + 1;
}
typedef pair<TreapNode*, TreapNode*> PNN;
PNN split(TreapNode* u, LL k) {
  if (u == Null) return make_pair(Null, Null);
  PNN ret;
  if (u->lc->size < k) {
    ret = split(u->rc, k - 1 - u->lc->size);
    u->rc = ret.first;
    ret.first = u;
  } else {
    ret = split(u->lc, k);
    u->lc = ret.second;
    ret.second = u;
  }
  u->pushup();
  return ret;
}
TreapNode* merge(TreapNode* u, TreapNode* v) {
  if (u == Null) return v;
  if (v == Null) return u;
  if (u->aux < v->aux) {
    u->rc = merge(u->rc, v);
    u->pushup();
    return u;
  } else {
    v->lc = merge(u, v->lc);
    v->pushup();
    return v;
  }
}
void insert(LL v) {
  LL k = getRank(root, v);
  PNN t = split(root, k);
  TreapNode* tmp = new TreapNode(v);
  tmp->pushup();
  root = merge(merge(t.first, tmp), t.second);
}
void erase(LL v) {
  LL k = getRank(root, v);
  PNN t1 = split(root, k - 1), t2 = split(t1.second, 1);
  root = merge(t1.first, t2.second);
}
int main() {
  srand(1);
  int n;
  cin >> n;
  Null = new TreapNode(0);
  Null->size = 0;
  Null->aux = -1;
  Null->lc = Null;
  Null->rc = Null;
  trackNull();
  root = Null;
  while (n--) {
    string op;
    cin >> op;
    if (op == "add") {
      int x;
      cin >> x;
      insert(x);
    } else if (op == "del") {
      int x;
      cin >> x;
      erase(x);
    } else {
      cout << root->sum[2] << endl;
    }
    trackNull();
  }
}